# CostCalculationAgent

Агент расчёта транспортных затрат для варианта размещения складов.

---

## Общая информация

| | |
|---|---|
| **Класс действия** | `action_calculate_cost` |
| **Файл реализации** | `agents/CostCalculationAgent.cpp` |
| **Лог-файл** | `logs/CostCalculationAgent.log` |

---

## Назначение

Рассчитывает суммарные месячные транспортные затраты на доставку товаров от складов до магазинов для заданного варианта размещения.

---

## Аргументы вызова

| № | Роль | Тип | Описание |
|---|------|-----|----------|
| 1 | `rrel_1` | `ScNode` | Вариант размещения (`concept_placement_variant`) |
| 2 | `rrel_2` | `ScNode` | Торговая сеть (`concept_trading_network`) |

---

## Что читает из SC-памяти

### Вариант размещения

```
placement_variant
    <- concept_placement_variant;;
    => nrel_warehouse: warehouse_1;;
    => nrel_warehouse: warehouse_2;;

warehouse_1
    <- concept_warehouse;;
    => nrel_x: [15.5];;
    => nrel_y: [22.3];;

warehouse_2
    <- concept_warehouse;;
    => nrel_x: [45.8];;
    => nrel_y: [38.1];;
```

### Торговая сеть

```
trading_network
    -> shop_1;;
    -> shop_2;;

shop_1
    <- concept_shop;;
    => nrel_x: [10];;
    => nrel_y: [15];;
    => nrel_delivery_volume: [200];;
```

### Читаемые атрибуты

**Для каждого склада:**
| Атрибут | Отношение |
|---------|-----------|
| X | `nrel_x` |
| Y | `nrel_y` |

**Для каждого магазина:**
| Атрибут | Отношение |
|---------|-----------|
| X | `nrel_x` |
| Y | `nrel_y` |
| Volume | `nrel_delivery_volume` |

---

## Преобразование данных

### Алгоритм расчёта

1. Собрать координаты всех складов из варианта
2. Собрать координаты и объёмы всех магазинов
3. Для каждого магазина:
   - Найти ближайший склад (евклидово расстояние)
   - Рассчитать затраты на доставку
4. Суммировать затраты

### Формула расчёта

```
Cost = Σ (distance_i × volume_i × tariff)

где:
  distance_i = √[(x_shop - x_warehouse)² + (y_shop - y_warehouse)²]
  volume_i   = объём поставки магазина (т/мес)
  tariff     = 50 руб/(км·т)
```

### Выбор склада для магазина

Каждый магазин обслуживается **ближайшим** складом:

```
warehouse_for_shop_i = argmin(distance(shop_i, warehouse_j))
```

---

## Что записывает в SC-память

### Выходная структура

```
placement_variant
    => nrel_monthly_cost: [332225];;
```

### Модификация существующих элементов

Агент **добавляет** атрибут `nrel_monthly_cost` к узлу варианта размещения (первый аргумент).

| Элемент | Тип | Описание |
|---------|-----|----------|
| Ссылка cost | `ScType::ConstNodeLink` | Затраты в рублях (целое число) |
| Связь | `nrel_monthly_cost` | Отношение к стоимости |

---

## Результат действия

### При успехе
- `action.FinishSuccessfully()`
- К варианту размещения добавлен атрибут `nrel_monthly_cost`
- Результат содержит созданные элементы

### При ошибке
- `action.FinishWithError()`
- Возможные причины:
  - Вариант размещения не найден
  - Торговая сеть не найдена
  - Не найдено складов
  - Не найдено магазинов

---

## Пример использования

### C++

```cpp
ScAddr variantAddr = /* вариант размещения */;
ScAddr networkAddr = /* торговая сеть */;

ScAction action = ctx.GenerateAction(LogisticsKeynodes::action_calculate_cost);
action.SetArguments(variantAddr, networkAddr);
action.InitiateAndWait(60000);

// Получаем затраты из варианта
ScIterator5Ptr costIter = ctx.CreateIterator5(
    variantAddr, ScType::ConstCommonArc, ScType::ConstNodeLink,
    ScType::ConstPermPosArc, LogisticsKeynodes::nrel_monthly_cost);
if (costIter->Next()) {
    std::string costStr;
    ctx.GetLinkContent(costIter->Get(2), costStr);
    double cost = std::stod(costStr);
}
```

---

## Связанные агенты

- **Вызывается из:** [WarehouseOptimizationAgent](WarehouseOptimizationAgent.md) (шаги 4, 6, 8)
- **Входные данные от:** [ClusteringAgent](ClusteringAgent.md)
- **Результат используется:** [VariantComparisonAgent](VariantComparisonAgent.md)
