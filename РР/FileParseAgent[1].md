# FileParseAgent

Агент парсинга входного CSV файла с данными о магазинах.

---

## Общая информация

| | |
|---|---|
| **Класс действия** | `action_parse_input_file` |
| **Файл реализации** | `agents/FileParseAgent.cpp` |
| **Лог-файл** | `logs/FileParseAgent.log` |

---

## Назначение

Читает CSV файл с данными о магазинах торговой сети и создаёт соответствующую структуру в SC-памяти.

---

## Аргументы вызова

| № | Роль | Тип | Описание |
|---|------|-----|----------|
| 1 | `rrel_1` | `ScNode` | Узел входной сущности, содержащий путь к CSV файлу через `nrel_main_idtf` |

---

## Что читает из SC-памяти

### Входная структура

```
input_entity
    => nrel_main_idtf: [путь/к/файлу.csv];;
```

Агент ищет:
1. Узел `input_entity` (первый аргумент действия)
2. Связь `nrel_main_idtf` от этого узла
3. Ссылку с путём к CSV файлу

### Формат CSV файла

```csv
shop_id;name;x;y;volume
1;Магазин_1;10;15;200
2;Магазин_2;25;30;350
```

- **Разделитель:** `;`
- **Заголовок:** `shop_id;name;x;y;volume`

---

## Преобразование данных

### Алгоритм

1. Получить путь к файлу через `nrel_main_idtf`
2. Открыть CSV файл
3. Пропустить заголовок
4. Для каждой строки:
   - Разбить по разделителю `;`
   - Извлечь: id, name, x, y, volume
   - Создать узел магазина в SC-памяти
5. Создать узел торговой сети и связать магазины

---

## Что записывает в SC-память

### Выходная структура

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

shop_2
    <- concept_shop;;
    => nrel_id: [2];;
    => nrel_x: [25];;
    => nrel_y: [30];;
    => nrel_delivery_volume: [350];;

input_entity
    => nrel_parsed_data: trading_network;;
```

### Создаваемые элементы

| Элемент | Тип | Описание |
|---------|-----|----------|
| Узел торговой сети | `ScType::ConstNode` | Контейнер для магазинов |
| Принадлежность классу | `concept_trading_network` | Классификация сети |
| Узел магазина | `ScType::ConstNode` | Каждый магазин |
| Принадлежность классу | `concept_shop` | Классификация магазина |
| Ссылка ID | `ScType::ConstNodeLink` | Идентификатор магазина |
| Ссылка X | `ScType::ConstNodeLink` | Координата X |
| Ссылка Y | `ScType::ConstNodeLink` | Координата Y |
| Ссылка Volume | `ScType::ConstNodeLink` | Объём поставки |

---

## Результат действия

### При успехе
- `action.FinishSuccessfully()`
- Результат содержит созданную структуру торговой сети
- Связь `nrel_parsed_data` добавлена к входной сущности

### При ошибке
- `action.FinishWithError()`
- Возможные причины:
  - Аргумент не найден
  - Не удалось получить путь к файлу
  - Ошибка парсинга CSV (неверный формат, файл не найден)

---

## Пример использования

### SCS

```scs
test_input
    => nrel_main_idtf: [data/shops.csv];;

action_parse_input_file
    -> action_1;;

action_1
    -> rrel_1: test_input;;
```

### C++

```cpp
ScAddr inputEntity = ctx.GenerateNode(ScType::ConstNode);
ScAddr pathLink = ctx.GenerateLink(ScType::ConstNodeLink);
ctx.SetLinkContent(pathLink, "data/shops.csv");
ScAddr pathArc = ctx.GenerateConnector(ScType::ConstCommonArc, inputEntity, pathLink);
ctx.GenerateConnector(ScType::ConstPermPosArc, LogisticsKeynodes::nrel_main_idtf, pathArc);

ScAction action = ctx.GenerateAction(LogisticsKeynodes::action_parse_input_file);
action.SetArguments(inputEntity);
action.InitiateAndWait(60000);
```

---

## Связанные агенты

- **Вызывается из:** [WarehouseOptimizationAgent](WarehouseOptimizationAgent.md) (шаг 1)
- **Результат используется:** [DataValidationAgent](DataValidationAgent.md)
