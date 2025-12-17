# ReportGenerationAgent

Агент формирования итогового отчёта по оптимизации размещения складов.

---

## Общая информация

| | |
|---|---|
| **Класс действия** | `action_generate_report` |
| **Файл реализации** | `agents/ReportGenerationAgent.cpp` |
| **Лог-файл** | `logs/ReportGenerationAgent.log` |

---

## Назначение

Формирует итоговый отчёт, объединяющий информацию о торговой сети, всех вариантах размещения и рекомендации.

---

## Аргументы вызова

| № | Роль | Тип | Описание |
|---|------|-----|----------|
| 1 | `rrel_1` | `ScNode` | Торговая сеть |
| 2 | `rrel_2` | `ScNode` | Вариант 1 (K=1) |
| 3 | `rrel_3` | `ScNode` | Вариант 2 (K=2) |
| 4 | `rrel_4` | `ScNode` | Вариант 3 (K=3) |
| 5 | `rrel_5` | `ScNode` | Лучший вариант (рекомендация) |

---

## Что читает из SC-памяти

### Торговая сеть

```
trading_network
    <- concept_trading_network;;
    -> shop_1;;
    -> shop_2;;
    -> shop_3;;
```

Агент подсчитывает количество магазинов в сети.

### Варианты размещения

```
variant_1
    <- concept_placement_variant;;
    => nrel_monthly_cost: [541847];;
    => nrel_economy_percent: [0.0];;
    => nrel_warehouse: warehouse_1;;
```

---

## Преобразование данных

### Алгоритм

1. Подсчитать количество магазинов в торговой сети
2. Создать узел отчёта
3. Добавить количество магазинов
4. Связать все три варианта с отчётом
5. Добавить рекомендацию (лучший вариант)

---

## Что записывает в SC-память

### Выходная структура

```
optimization_report
    <- concept_optimization_report;;
    => nrel_shop_count: [5];;
    => nrel_single_warehouse_variant: variant_1;;
    => nrel_two_warehouses_variant: variant_2;;
    => nrel_three_warehouses_variant: variant_3;;
    => nrel_recommendation: variant_3;;
```

### Создаваемые элементы

| Элемент | Тип | Описание |
|---------|-----|----------|
| Узел отчёта | `ScType::ConstNode` | Главный узел отчёта |
| Класс отчёта | `concept_optimization_report` | Классификация |
| shop_count | `nrel_shop_count` | Количество магазинов |
| single_warehouse | `nrel_single_warehouse_variant` | Вариант с 1 складом |
| two_warehouses | `nrel_two_warehouses_variant` | Вариант с 2 складами |
| three_warehouses | `nrel_three_warehouses_variant` | Вариант с 3 складами |
| recommendation | `nrel_recommendation` | Рекомендуемый вариант |

---

## Результат действия

### При успехе
- `action.FinishSuccessfully()`
- Результат содержит полную структуру отчёта

### При ошибке
- `action.FinishWithError()`
- Возможные причины:
  - Торговая сеть не найдена
  - Не все варианты переданы

---

## Пример использования

### C++

```cpp
ScAddr networkAddr = /* торговая сеть */;
ScAddr variant1 = /* вариант K=1 */;
ScAddr variant2 = /* вариант K=2 */;
ScAddr variant3 = /* вариант K=3 */;
ScAddr bestVariant = /* лучший вариант */;

ScAction action = ctx.GenerateAction(LogisticsKeynodes::action_generate_report);
action.SetArguments(networkAddr, variant1, variant2, variant3, bestVariant);
action.InitiateAndWait(60000);

ScStructure report = action.GetResult();
```

---

## Структура отчёта

```
┌─────────────────────────────────────────────────────────────┐
│                   optimization_report                        │
├─────────────────────────────────────────────────────────────┤
│ nrel_shop_count: 5                                          │
├─────────────────────────────────────────────────────────────┤
│ Вариант 1 (1 склад):                                        │
│   • Затраты: 541847 руб/мес                                 │
│   • Экономия: 0%                                            │
├─────────────────────────────────────────────────────────────┤
│ Вариант 2 (2 склада):                                       │
│   • Затраты: 332225 руб/мес                                 │
│   • Экономия: 38.7%                                         │
├─────────────────────────────────────────────────────────────┤
│ Вариант 3 (3 склада):                                       │
│   • Затраты: 234294 руб/мес                                 │
│   • Экономия: 56.8%                                         │
├─────────────────────────────────────────────────────────────┤
│ РЕКОМЕНДАЦИЯ: Вариант 3 (3 склада)                          │
└─────────────────────────────────────────────────────────────┘
```

---

## Связанные агенты

- **Вызывается из:** [WarehouseOptimizationAgent](WarehouseOptimizationAgent.md) (шаг 10)
- **Входные данные от:** [VariantComparisonAgent](VariantComparisonAgent.md)
- **Результат:** Финальный отчёт для пользователя
