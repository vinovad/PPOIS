# WarehouseOptimizationAgent

Агент-оркестратор, управляющий полным циклом оптимизации размещения складов.

---

## Общая информация

| | |
|---|---|
| **Класс действия** | `action_optimize_warehouse_placement` |
| **Файл реализации** | `agents/WarehouseOptimizationAgent.cpp` |
| **Лог-файл** | `logs/WarehouseOptimizationAgent.log` |

---

## Назначение

Координирует работу всех атомарных агентов для выполнения полного цикла оптимизации — от парсинга входного файла до формирования итогового отчёта.

---

## Аргументы вызова

| № | Роль | Тип | Описание |
|---|------|-----|----------|
| 1 | `rrel_1` | `ScNode` | Входная сущность с путём к CSV файлу |

---

## Что читает из SC-памяти

### Входная структура

```
input_entity
    => nrel_main_idtf: [path/to/shops.csv];;
```

Оркестратор использует эту сущность для вызова FileParseAgent, затем работает с результатами промежуточных агентов.

---

## Последовательность вызовов

```
┌─────────────────────────────────────────────────────────────────────┐
│                    WarehouseOptimizationAgent                        │
│                         (10 шагов)                                   │
└─────────────────────────────────────────────────────────────────────┘

Шаг 1:  FileParseAgent(input_entity)
        └── Результат: trading_network

Шаг 2:  DataValidationAgent(trading_network)
        └── Проверка: shopCount >= 3, nrel_is_valid == "true"

Шаг 3:  ClusteringAgent(trading_network, K=1)
        └── Результат: variant_1

Шаг 4:  CostCalculationAgent(variant_1, trading_network)
        └── Добавлено: variant_1.nrel_monthly_cost

Шаг 5:  ClusteringAgent(trading_network, K=2)
        └── Результат: variant_2

Шаг 6:  CostCalculationAgent(variant_2, trading_network)
        └── Добавлено: variant_2.nrel_monthly_cost

Шаг 7:  ClusteringAgent(trading_network, K=3)
        └── Результат: variant_3

Шаг 8:  CostCalculationAgent(variant_3, trading_network)
        └── Добавлено: variant_3.nrel_monthly_cost

Шаг 9:  VariantComparisonAgent(variant_1, variant_2, variant_3)
        └── Результат: best_variant

Шаг 10: ReportGenerationAgent(network, v1, v2, v3, best)
        └── Результат: optimization_report
```

---

## Преобразование данных

### Алгоритм

1. **Парсинг:** Вызвать FileParseAgent → получить торговую сеть
2. **Валидация:** Вызвать DataValidationAgent → проверить данные + проверить `nrel_is_valid`
3. **Кластеризация K=1:** Вызвать ClusteringAgent → получить вариант 1
4. **Расчёт затрат 1:** Вызвать CostCalculationAgent для варианта 1
5. **Кластеризация K=2:** Вызвать ClusteringAgent → получить вариант 2
6. **Расчёт затрат 2:** Вызвать CostCalculationAgent для варианта 2
7. **Кластеризация K=3:** Вызвать ClusteringAgent → получить вариант 3
8. **Расчёт затрат 3:** Вызвать CostCalculationAgent для варианта 3
9. **Сравнение:** Вызвать VariantComparisonAgent → получить лучший вариант
10. **Отчёт:** Вызвать ReportGenerationAgent → сформировать отчёт + проверить успешность

### Таймаут ожидания

Каждый вызов агента ожидается **60 секунд** (`AGENT_WAIT_TIME_MS = 60000`).

---

## Что записывает в SC-память

Оркестратор не создаёт собственные структуры — он координирует работу атомарных агентов и возвращает результат ReportGenerationAgent.

### Результат действия

Структура, содержащая полный отчёт оптимизации:

```
optimization_report
    <- concept_optimization_report;;
    => nrel_shop_count: [5];;
    => nrel_single_warehouse_variant: variant_1;;
    => nrel_two_warehouses_variant: variant_2;;
    => nrel_three_warehouses_variant: variant_3;;
    => nrel_recommendation: variant_3;;
```

---

## Результат действия

### При успехе
- `action.FinishSuccessfully()`
- Результат содержит полный отчёт оптимизации

### При ошибке
- `action.FinishWithError()`
- Возможные причины (на любом шаге):
  - Шаг 1: Ошибка парсинга файла
  - Шаг 2: Недостаточно магазинов или `nrel_is_valid == "false"`
  - Шаги 3,5,7: Ошибка кластеризации
  - Шаги 4,6,8: Ошибка расчёта затрат
  - Шаг 9: Ошибка сравнения
  - Шаг 10: Ошибка формирования отчёта (проверяется успешность)

---

## Пример использования

### SCS (через UI)

```scs
// Входные данные
test_input
    => nrel_main_idtf: [data/shops.csv];;

// Инициация действия
action_optimize_warehouse_placement
    -> action_1;;

action_1
    -> rrel_1: test_input;;
```

### C++

```cpp
// Создать входную сущность
ScAddr inputEntity = ctx.GenerateNode(ScType::ConstNode);
ScAddr pathLink = ctx.GenerateLink(ScType::ConstNodeLink);
ctx.SetLinkContent(pathLink, "data/shops.csv");
ScAddr pathArc = ctx.GenerateConnector(ScType::ConstCommonArc, inputEntity, pathLink);
ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_main_idtf, pathArc);

// Запустить оптимизацию
ScAction action = ctx.GenerateAction(LogisticsKeynodes::action_optimize_warehouse_placement);
action.SetArguments(inputEntity);

if (action.InitiateAndWait(120000)) {  // 2 минуты на весь цикл
    if (action.IsFinishedSuccessfully()) {
        ScStructure report = action.GetResult();
        // Обработать отчёт
    }
}
```

---

## Диаграмма последовательности

```
User        Orchestrator    FileParse   Validation   Clustering   Cost        Comparison   Report
  │              │              │            │            │          │             │           │
  │──request────▶│              │            │            │          │             │           │
  │              │──parse──────▶│            │            │          │             │           │
  │              │◀──network────│            │            │          │             │           │
  │              │──validate────────────────▶│            │          │             │           │
  │              │◀──ok─────────────────────│            │          │             │           │
  │              │──cluster(K=1)────────────────────────▶│          │             │           │
  │              │◀──variant1───────────────────────────│          │             │           │
  │              │──calcCost(v1)───────────────────────────────────▶│             │           │
  │              │◀──ok────────────────────────────────────────────│             │           │
  │              │  ... (repeat for K=2, K=3) ...                   │             │           │
  │              │──compare(v1,v2,v3)──────────────────────────────────────────▶│           │
  │              │◀──best──────────────────────────────────────────────────────│           │
  │              │──report(network,v1,v2,v3,best)────────────────────────────────────────▶│
  │              │◀──report────────────────────────────────────────────────────────────────│
  │◀──report────│              │            │            │          │             │           │
```

---

## Связанные агенты

**Вызывает:**
1. [FileParseAgent](FileParseAgent.md)
2. [DataValidationAgent](DataValidationAgent.md)
3. [ClusteringAgent](ClusteringAgent.md) (×3)
4. [CostCalculationAgent](CostCalculationAgent.md) (×3)
5. [VariantComparisonAgent](VariantComparisonAgent.md)
6. [ReportGenerationAgent](ReportGenerationAgent.md)

**Вызывается:**
- Пользователем через UI
- Другими системами через SC-память
