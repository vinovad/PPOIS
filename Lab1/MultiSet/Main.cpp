'''cpp
#include "MultiSet.h"

int main() {
    setlocale(0, "rus");
    UndirectedMultiSet currentSet;
    SetManager setManager;
    int choice;

    setManager.addSet("EmptySet", UndirectedMultiSet(""));

    do {
        std::cout << "\n=== Меню работы с мультимножеством ===" << std::endl;
        std::cout << "1. Создать новое мультимножество" << std::endl;
        std::cout << "2. Показать текущее множество" << std::endl;
        std::cout << "3. Сохранить множество" << std::endl;
        std::cout << "4. Список множеств" << std::endl;
        std::cout << "5. Проверить на пустоту" << std::endl;
        std::cout << "6. Добавить элемент в множество" << std::endl;
        std::cout << "7. Удалить элемент из множества" << std::endl;
        std::cout << "8. Проверить принадлежность элемента" << std::endl;
        std::cout << "9. Вывести мощность" << std::endl;
        std::cout << "10. Объединение с другим множеством" << std::endl;
        std::cout << "11. Пересечение с другим множеством" << std::endl;
        std::cout << "12. Разность с другим множеством" << std::endl;
        std::cout << "13. Булеан множества" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите опцию: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::cout << "Введите строку для множества: ";
            char input[1024];
            std::cin.getline(input, sizeof(input));
            if (strlen(input) == 0) {
                std::cout << "Ошибка: строка пуста!" << std::endl;
                break;
            }
            currentSet = UndirectedMultiSet(input);
            setManager.addSetAutoName(currentSet);
            std::cout << "Множество создано и сохранено: ";
            currentSet.print();
            break;
        }
        case 2: {
            std::cout << "Текущее множество: ";
            currentSet.print();
            break;
        }
        case 3: {
            char name[100];
            std::cout << "Введите имя для сохранения множества: ";
            std::cin.getline(name, sizeof(name));
            setManager.addSet(name, currentSet);
            std::cout << "Множество сохранено под именем '" << name << "'" << std::endl;
            break;
        }
        case 4: {
            setManager.listSets();
            break;
        }
        case 5: {
            std::cout << "Множество " << (currentSet.isEmpty() ? "пусто" : "не пусто") << std::endl;
            break;
        }
        case 6: {
            char element[256];
            int count;
            std::cout << "Введите элемент: ";
            std::cin.getline(element, sizeof(element));
            std::cout << "Введите количество: ";
            std::cin >> count;
            std::cin.ignore();

            // ЯВНО УКАЗАТЬ ВСЕ ТРИ ПАРАМЕТРА
            currentSet.add(element, count, false);

            std::cout << "Результат добавления: ";
            currentSet.print();
            break;
        }
        case 7: {
            std::cout << "Текущее множество: ";
            currentSet.print();

            char element[256];
            int count;
            std::cout << "Введите элемент для удаления: ";
            std::cin.getline(element, sizeof(element));
            std::cout << "Введите количество: ";
            std::cin >> count;
            std::cin.ignore();

            bool isSet = (strlen(element) > 0 && element[0] == '{' && element[strlen(element) - 1] == '}');

            if (!currentSet.contains(element, isSet)) {
                std::cout << "Элемент '" << element << "' не найден!" << std::endl;
                std::cout << "Текущее множество: ";
                currentSet.print();
                break;
            }

            // ЯВНО УКАЗАТЬ ВСЕ ТРИ ПАРАМЕТРА
            currentSet.remove(element, isSet, count);
            std::cout << "Результат удаления: ";
            currentSet.print();
            break;
        }
        case 8: {
            char element[256];
            std::cout << "Введите элемент: ";
            std::cin.getline(element, sizeof(element));

            bool isSet = false;
            if (strlen(element) > 0) {
                char trimmed[256];
                strcpy(trimmed, element);
                trim(trimmed);
                isSet = (trimmed[0] == '{' && trimmed[strlen(trimmed) - 1] == '}');
            }

            std::cout << "Элемент '" << element << "' "
                << (currentSet.contains(element, isSet) ? "принадлежит" : "не принадлежит")
                << " множеству" << std::endl;
            break;
        }
        case 9: {
            std::cout << "Мощность множества: " << currentSet.power() << " элементов" << std::endl;
            std::cout << "Уникальных элементов: " << currentSet.uniqueCount() << std::endl;
            break;
        }
        case 10: {
            int index = setManager.selectSet();
            if (index != -1) {
                UndirectedMultiSet otherSet = setManager.getSet(index);
                UndirectedMultiSet unionSet = currentSet + otherSet;
                std::cout << "Объединение: ";
                unionSet.print();

                char saveChoice;
                std::cout << "Сохранить результат? (y/n): ";
                std::cin >> saveChoice;
                std::cin.ignore();
                if (saveChoice == 'y' || saveChoice == 'Y') {
                    setManager.addSetAutoName(unionSet);
                    currentSet = unionSet;
                    std::cout << "Результат сохранен и установлен как текущее множество" << std::endl;
                }
            }
            break;
        }
        case 11: {
            int index = setManager.selectSet();
            if (index != -1) {
                UndirectedMultiSet otherSet = setManager.getSet(index);
                UndirectedMultiSet intersection = currentSet * otherSet;
                std::cout << "Пересечение: ";
                intersection.print();

                char saveChoice;
                std::cout << "Сохранить результат? (y/n): ";
                std::cin >> saveChoice;
                std::cin.ignore();
                if (saveChoice == 'y' || saveChoice == 'Y') {
                    setManager.addSetAutoName(intersection);
                    currentSet = intersection;
                    std::cout << "Результат сохранен и установлен как текущее множество" << std::endl;
                }
            }
            break;
        }
        case 12: {
            int index = setManager.selectSet();
            if (index != -1) {
                UndirectedMultiSet otherSet = setManager.getSet(index);
                UndirectedMultiSet difference = currentSet - otherSet;
                std::cout << "Разность: ";
                difference.print();

                char saveChoice;
                std::cout << "Сохранить результат? (y/n): ";
                std::cin >> saveChoice;
                std::cin.ignore();
                if (saveChoice == 'y' || saveChoice == 'Y') {
                    setManager.addSetAutoName(difference);
                    currentSet = difference;
                    std::cout << "Результат сохранен и установлен как текущее множество" << std::endl;
                }
            }
            break;
        }
        case 13: {
            if (currentSet.uniqueCount() > 10) {
                std::cout << "Предупреждение: количество элементов для булеана > 10 может занять много времени!" << std::endl;
            }
            std::cout << "Булеан множества (для демонстрации):" << std::endl;
            UndirectedMultiSet boolean = currentSet.boolean();
            boolean.print();

            char saveChoice;
            std::cout << "Сохранить результат? (y/n): ";
            std::cin >> saveChoice;
            std::cin.ignore();
            if (saveChoice == 'y' || saveChoice == 'Y') {
                setManager.addSetAutoName(boolean);
                std::cout << "Булеан сохранен" << std::endl;
            }
            break;
        }
        case 0: {
            std::cout << "Выход из программы..." << std::endl;
            break;
        }
        default: {
            std::cout << "Неверный выбор!" << std::endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
'''
