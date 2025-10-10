'''cpp
#include "Set.h"

int main() {
    setlocale(0, "rus");
    SetManager manager;
    int choice;
    
    do {
        std::cout << "\n=== Меню операций с множествами ===" << std::endl;
        std::cout << "1. Создать новое множество" << std::endl;
        std::cout << "2. Добавить элемент в множество" << std::endl;
        std::cout << "3. Удалить элемент из множества" << std::endl;
        std::cout << "4. Определить мощность множества" << std::endl;
        std::cout << "5. Проверить принадлежность элемента множеству" << std::endl;
        std::cout << "6. Объединение двух множеств" << std::endl;
        std::cout << "7. Пересечение двух множеств" << std::endl;
        std::cout << "8. Разность двух множеств" << std::endl;
        std::cout << "9. Построить булеан множества" << std::endl;
        std::cout << "10. Преобразовать в канторово множество" << std::endl;
        std::cout << "11. Показать все множества" << std::endl;
        std::cout << "12. Закрыть меню" << std::endl;
        std::cout << "Выберите операцию: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный ввод! Пожалуйста, введите число от 1 до 12." << std::endl;
            continue;
        }

        std::cin.ignore(10000, '\n');

        switch (choice) {
        case 1:
            manager.createNewSet();
            break;
        case 2:
            manager.addElement();
            break;
        case 3:
            manager.removeElement();
            break;
        case 4:
            manager.printSetCardinality();
            break;
        case 5:
            manager.checkElementMembership();
            break;
        case 6:
            manager.performUnion();
            break;
        case 7:
            manager.performIntersection();
            break;
        case 8:
            manager.performDifference();
            break;
        case 9:
            manager.printPowerSet();
            break;
        case 10:
            manager.convertToCantorSet();
            break;
        case 11:
            manager.printAllSets();
            break;
        case 12:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, введите число от 1 до 12." << std::endl;
            break;
        }
    } while (choice != 12);

    return 0;
}
'''
