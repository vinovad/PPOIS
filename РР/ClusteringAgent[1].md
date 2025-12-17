# ClusteringAgent

Агент K-means кластеризации магазинов для определения оптимального размещения складов.

---

## Общая информация

| | |
|---|---|
| **Класс действия** | `action_cluster_shops` |
| **Файл реализации** | `agents/ClusteringAgent.cpp` |
| **Лог-файл** | `logs/ClusteringAgent.log` |

---

## Назначение

Выполняет кластеризацию магазинов методом K-means и определяет оптимальные координаты складов как взвешенные центроиды кластеров.

---

## Аргументы вызова

| № | Роль | Тип | Описание |
|---|------|-----|----------|
| 1 | `rrel_1` | `ScNode` | Узел торговой сети (`concept_trading_network`) |
| 2 | `rrel_2` | `ScNodeLink` | Ссылка с числом K (количество складов) |

---

## Что читает из SC-памяти

### Входная структура

```
trading_network
    <- concept_trading_network;;
    -> shop_1;;
    -> shop_2;;

shop_1
    <- concept_shop;;
    => nrel_id: [1];;
    => nrel_x: [10];;
    => nrel_y: [15];;
    => nrel_delivery_volume: [200];;

k_value
    <- sc_node_link;;
    // содержит число "2"
```

### Читаемые атрибуты магазина

| Атрибут | Отношение | Использование |
|---------|-----------|---------------|
| X | `nrel_x` | Координата для кластеризации |
| Y | `nrel_y` | Координата для кластеризации |
| Volume | `nrel_delivery_volume` | Вес для взвешенного центроида |
| ID | `nrel_id` | Идентификация магазина |

---

## Преобразование данных

### Алгоритм K-means

1. Получить K из аргумента 2
2. Собрать данные всех магазинов (x, y, volume)
3. Проверить: K ≤ количество магазинов
4. Выполнить K-means кластеризацию:
   - Инициализировать K центроидов
   - Итеративно назначать магазины ближайшему центроиду
   - Пересчитывать центроиды как взвешенные средние
5. Создать вариант размещения с K складами

### Формула взвешенного центроида

```
X_склада = Σ(x_i × volume_i) / Σ(volume_i)
Y_склада = Σ(y_i × volume_i) / Σ(volume_i)
```

### Ограничения

| Параметр | Ограничение |
|----------|-------------|
| K | 1 ≤ K ≤ 10 |
| K | K ≤ количество магазинов |

---

## Что записывает в SC-память

### Выходная структура

```
placement_variant
    <- concept_placement_variant;;
    => nrel_warehouse: warehouse_1;;
    => nrel_warehouse: warehouse_2;;

warehouse_1
    <- concept_warehouse;;
    => nrel_id: [1];;
    => nrel_x: [15.5];;
    => nrel_y: [22.3];;
    => nrel_serves_shops: [1,2,3];;

warehouse_2
    <- concept_warehouse;;
    => nrel_id: [2];;
    => nrel_x: [45.8];;
    => nrel_y: [38.1];;
    => nrel_serves_shops: [4,5];;
```

### Создаваемые элементы

| Элемент | Тип | Описание |
|---------|-----|----------|
| Вариант размещения | `ScType::ConstNode` | Контейнер варианта |
| Класс варианта | `concept_placement_variant` | Классификация |
| Узел склада | `ScType::ConstNode` | Каждый склад |
| Класс склада | `concept_warehouse` | Классификация |
| ID склада | `nrel_id` | Порядковый номер |
| Координата X | `nrel_x` | Расположение |
| Координата Y | `nrel_y` | Расположение |
| Обслуживаемые магазины | `nrel_serves_shops` | Список ID магазинов |

---

## Результат действия

### При успехе
- `action.FinishSuccessfully()`
- Результат содержит:
  - Узел варианта размещения (`concept_placement_variant`)
  - K узлов складов с координатами

### При ошибке
- `action.FinishWithError()`
- Возможные причины:
  - Торговая сеть не найдена
  - K не указано или невалидно
  - K > количества магазинов
  - K < 1 или K > 10

---

## Пример использования

### C++

```cpp
ScAddr networkAddr = /* узел торговой сети */;

// Создаём ссылку с K=2
ScAddr kLink = ctx.GenerateLink(ScType::ConstNodeLink);
ctx.SetLinkContent(kLink, "2");

ScAction action = ctx.GenerateAction(LogisticsKeynodes::action_cluster_shops);
action.SetArguments(networkAddr, kLink);
action.InitiateAndWait(60000);

// Извлекаем вариант размещения из результата
ScStructure result = action.GetResult();
```

---

## Связанные агенты

- **Вызывается из:** [WarehouseOptimizationAgent](WarehouseOptimizationAgent.md) (шаги 3, 5, 7)
- **Входные данные от:** [DataValidationAgent](DataValidationAgent.md)
- **Результат используется:** [CostCalculationAgent](CostCalculationAgent.md)
