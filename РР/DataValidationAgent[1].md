# DataValidationAgent

Агент валидации входных данных торговой сети.

---

## Общая информация

| | |
|---|---|
| **Класс действия** | `action_validate_data` |
| **Файл реализации** | `agents/DataValidationAgent.cpp` |
| **Лог-файл** | `logs/DataValidationAgent.log` |

---

## Назначение

Проверяет корректность данных торговой сети перед запуском оптимизации.

---

## Аргументы вызова

| № | Роль | Тип | Описание |
|---|------|-----|----------|
| 1 | `rrel_1` | `ScNode` | Узел торговой сети (`concept_trading_network`) |

---

## Что читает из SC-памяти

### Входная структура

```
trading_network
    <- concept_trading_network;;
    -> shop_1;;
    -> shop_2;;
    -> shop_3;;

shop_1
    <- concept_shop;;
    => nrel_id: [1];;
    => nrel_x: [10];;
    => nrel_y: [15];;
    => nrel_delivery_volume: [200];;
```

### Проверяемые элементы

Для каждого узла в торговой сети, принадлежащего `concept_shop`:

| Атрибут | Отношение | Обязательность |
|---------|-----------|----------------|
| ID | `nrel_id` | Да |
| X | `nrel_x` | Да |
| Y | `nrel_y` | Да |
| Volume | `nrel_delivery_volume` | Да |

---

## Преобразование данных

### Алгоритм валидации

1. Получить узел торговой сети (аргумент 1)
2. Итерировать по всем членам сети
3. Для каждого узла с классом `concept_shop`:
   - Проверить наличие `nrel_id`
   - Проверить наличие `nrel_x`
   - Проверить наличие `nrel_y`
   - Проверить наличие `nrel_delivery_volume`
   - Подсчитать количество магазинов
4. Проверить: количество магазинов ≥ 3

### Правила валидации

| Правило | Описание | При нарушении |
|---------|----------|---------------|
| Минимум магазинов | Не менее 3 магазинов | Ошибка |
| Обязательные атрибуты | Все 4 атрибута должны быть | Предупреждение |

---

## Что записывает в SC-память

### Выходная структура

```
validation_result
    => nrel_shop_count: [5];;
    => nrel_is_valid: [true];;
```

### Создаваемые элементы

| Элемент | Тип | Описание |
|---------|-----|----------|
| Узел результата | `ScType::ConstNode` | Контейнер результата |
| Ссылка shop_count | `ScType::ConstNodeLink` | Количество магазинов |
| Ссылка is_valid | `ScType::ConstNodeLink` | "true" / "false" |

---

## Результат действия

### При успехе
- `action.FinishSuccessfully()`
- Результат содержит:
  - Количество магазинов (`nrel_shop_count`)
  - Флаг валидности (`nrel_is_valid`)

### При ошибке
- `action.FinishWithError()`
- Возможные причины:
  - Торговая сеть не найдена
  - Менее 3 магазинов

---

## Пример использования

### C++

```cpp
ScAddr networkAddr = /* узел торговой сети */;

ScAction action = ctx.GenerateAction(LogisticsKeynodes::action_validate_data);
action.SetArguments(networkAddr);
action.InitiateAndWait(60000);

if (action.IsFinishedSuccessfully()) {
    // Данные валидны
}
```

---

## Связанные агенты

- **Вызывается из:** [WarehouseOptimizationAgent](WarehouseOptimizationAgent.md) (шаг 2)
- **Входные данные от:** [FileParseAgent](FileParseAgent.md)
- **Результат используется:** [ClusteringAgent](ClusteringAgent.md)
