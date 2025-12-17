# VariantComparisonAgent

Агент сравнения вариантов размещения складов и выбора оптимального.

---

## Общая информация

| | |
|---|---|
| **Класс действия** | `action_compare_variants` |
| **Файл реализации** | `agents/VariantComparisonAgent.cpp` |
| **Лог-файл** | `logs/VariantComparisonAgent.log` |

---

## Назначение

Сравнивает три варианта размещения складов по стоимости и выбирает оптимальный (с минимальными затратами). Рассчитывает экономию каждого варианта относительно базового (1 склад).

---

## Аргументы вызова

| № | Роль | Тип | Описание |
|---|------|-----|----------|
| 1 | `rrel_1` | `ScNode` | Вариант 1 (K=1, 1 склад) |
| 2 | `rrel_2` | `ScNode` | Вариант 2 (K=2, 2 склада) |
| 3 | `rrel_3` | `ScNode` | Вариант 3 (K=3, 3 склада) |

---

## Что читает из SC-памяти

### Входная структура

```
variant_1
    <- concept_placement_variant;;
    => nrel_monthly_cost: [541847];;

variant_2
    <- concept_placement_variant;;
    => nrel_monthly_cost: [332225];;

variant_3
    <- concept_placement_variant;;
    => nrel_monthly_cost: [234294];;
```

### Читаемые атрибуты

| Атрибут | Отношение | Описание |
|---------|-----------|----------|
| Месячные затраты | `nrel_monthly_cost` | Стоимость варианта в рублях |

---

## Преобразование данных

### Алгоритм

1. Получить затраты каждого варианта (`nrel_monthly_cost`)
2. Рассчитать экономию относительно варианта 1:
   ```
   economy_k = 100 × (1 - cost_k / cost_1)
   ```
3. Определить лучший вариант:
   ```
   best = argmin(cost_1, cost_2, cost_3)
   ```
4. Добавить экономию к каждому варианту
5. Создать рекомендацию

### Формула экономии

```
economy_2 = 100 × (1 - cost_2 / cost_1) %
economy_3 = 100 × (1 - cost_3 / cost_1) %
economy_1 = 0%  (базовый вариант)
```

---

## Что записывает в SC-память

### Модификация вариантов

К каждому варианту добавляется процент экономии:

```
variant_1
    => nrel_economy_percent: [0.0];;

variant_2
    => nrel_economy_percent: [38.7];;

variant_3
    => nrel_economy_percent: [56.8];;
```

### Выходная структура

```
comparison_result
    => nrel_recommendation: variant_3;;
```

### Создаваемые элементы

| Элемент | Тип | Описание |
|---------|-----|----------|
| Ссылка economy | `ScType::ConstNodeLink` | Процент экономии |
| Связь economy | `nrel_economy_percent` | Отношение к экономии |
| Узел результата | `ScType::ConstNode` | Контейнер результата |
| Связь recommendation | `nrel_recommendation` | Указатель на лучший вариант |

---

## Результат действия

### При успехе
- `action.FinishSuccessfully()`
- Ко всем вариантам добавлен `nrel_economy_percent`
- Результат содержит:
  - Узел результата сравнения
  - Связь `nrel_recommendation` к лучшему варианту

### При ошибке
- `action.FinishWithError()`
- Возможные причины:
  - Не все варианты найдены
  - У вариантов нет `nrel_monthly_cost`

---

## Пример использования

### C++

```cpp
ScAddr variant1 = /* вариант K=1 */;
ScAddr variant2 = /* вариант K=2 */;
ScAddr variant3 = /* вариант K=3 */;

ScAction action = ctx.GenerateAction(LogisticsKeynodes::action_compare_variants);
action.SetArguments(variant1, variant2, variant3);
action.InitiateAndWait(60000);

// Извлекаем лучший вариант
ScStructure result = action.GetResult();
ScIterator5Ptr recIter = ctx.CreateIterator5(
    ScType::ConstNode, ScType::ConstCommonArc, ScType::ConstNode,
    ScType::ConstPermPosArc, LogisticsKeynodes::nrel_recommendation);
if (recIter->Next()) {
    ScAddr bestVariant = recIter->Get(2);
}
```

---

## Связанные агенты

- **Вызывается из:** [WarehouseOptimizationAgent](WarehouseOptimizationAgent.md) (шаг 9)
- **Входные данные от:** [CostCalculationAgent](CostCalculationAgent.md)
- **Результат используется:** [ReportGenerationAgent](ReportGenerationAgent.md)
