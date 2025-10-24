#include <iostream>
#include <string>
#include "task2.h"

using namespace std;

void print_menu() {
    cout << "\n=== МЕНЮ УПРАВЛЕНИЯ ГРАФОМ ===\n";
    cout << "1.  Добавить вершину\n";
    cout << "2.  Добавить ребро\n";
    cout << "3.  Удалить вершину\n";
    cout << "4.  Удалить ребро\n";
    cout << "5.  Проверить наличие вершины\n";
    cout << "6.  Проверить наличие ребра\n";
    cout << "7.  Получить количество вершин\n";
    cout << "8.  Получить количество ребер\n";
    cout << "9.  Вычислить степень вершины\n";
    cout << "10. Показать все вершины\n";
    cout << "11. Показать все ребра\n";
    cout << "12. Показать исходящие ребра вершины\n";
    cout << "13. Показать входящие ребра вершины\n";
    cout << "14. Показать смежные вершины\n";
    cout << "15. Очистить граф\n";
    cout << "16. Проверить пустоту графа\n";
    cout << "17. Вывести полную информацию\n";
    cout << "0.  Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    setlocale(0, "rus");

    DirectedGraph<string> graph;
    int choice;

    do {
        print_menu();
        cin >> choice;
        cin.ignore(); 

        try {
            switch (choice) {
            case 1: {
                string value;
                cout << "Введите значение вершины: ";
                getline(cin, value);
                size_t id = graph.add_vertex(value);
                cout << "Добавлена вершина с ID: " << id << endl;
                break;
            }

            case 2: {
                size_t from, to;
                cout << "Введите ID начальной вершины: ";
                cin >> from;
                cout << "Введите ID конечной вершины: ";
                cin >> to;
                graph.add_edge(from, to);
                cout << "Добавлено ребро: " << from << " ? " << to << endl;
                break;
            }

            case 3: {
                size_t vertex_id;
                cout << "Введите ID вершины для удаления: ";
                cin >> vertex_id;
                graph.remove_vertex(vertex_id);
                cout << "Вершина " << vertex_id << " удалена\n";
                break;
            }

            case 4: {
                size_t from, to;
                cout << "Введите ID начальной вершины: ";
                cin >> from;
                cout << "Введите ID конечной вершины: ";
                cin >> to;
                graph.remove_edge(from, to);
                cout << "Ребро " << from << " ? " << to << " удалено\n";
                break;
            }

            case 5: {
                size_t vertex_id;
                cout << "Введите ID вершины: ";
                cin >> vertex_id;
                if (graph.has_vertex(vertex_id)) {
                    cout << "Вершина " << vertex_id << " существует\n";
                }
                else {
                    cout << "Вершина " << vertex_id << " не существует\n";
                }
                break;
            }

            case 6: {
                size_t from, to;
                cout << "Введите ID начальной вершины: ";
                cin >> from;
                cout << "Введите ID конечной вершины: ";
                cin >> to;
                if (graph.has_edge(from, to)) {
                    cout << "Ребро " << from << " ? " << to << " существует\n";
                }
                else {
                    cout << "Ребро " << from << " ? " << to << " не существует\n";
                }
                break;
            }

            case 7: {
                cout << "Количество вершин: " << graph.vertex_count() << endl;
                break;
            }

            case 8: {
                cout << "Количество ребер: " << graph.edge_count() << endl;
                break;
            }

            case 9: {
                size_t vertex_id;
                cout << "Введите ID вершины: ";
                cin >> vertex_id;
                cout << "Исходящая степень: " << graph.out_degree(vertex_id) << endl;
                cout << "Входящая степень: " << graph.in_degree(vertex_id) << endl;
                cout << "Общая степень: " << graph.vertex_degree(vertex_id) << endl;
                break;
            }

            case 10: {
                cout << "Вершины: ";
                for (auto it = graph.begin_vertices(); it != graph.end_vertices(); ++it) {
                    auto vertex = *it;
                    cout << "[" << vertex.first << ":" << vertex.second << "] ";
                }
                cout << endl;
                break;
            }

            case 11: {
                cout << "Ребра: ";
                for (auto it = graph.begin_edges(); it != graph.end_edges(); ++it) {
                    cout << "(" << it->from << "?" << it->to << ") ";
                }
                cout << endl;
                break;
            }

            case 12: {
                size_t vertex_id;
                cout << "Введите ID вершины: ";
                cin >> vertex_id;
                cout << "Исходящие ребра: ";
                auto edges = graph.outgoing_edges(vertex_id);
                for (auto it = edges.first; it != edges.second; ++it) {
                    cout << "(" << it->from << "?" << it->to << ") ";
                }
                cout << endl;
                break;
            }

            case 13: {
                size_t vertex_id;
                cout << "Введите ID вершины: ";
                cin >> vertex_id;
                cout << "Входящие ребра: ";
                auto edges = graph.incoming_edges(vertex_id);
                for (auto it = edges.first; it != edges.second; ++it) {
                    cout << "(" << it->from << "?" << it->to << ") ";
                }
                cout << endl;
                break;
            }

            case 14: {
                size_t vertex_id;
                cout << "Введите ID вершины: ";
                cin >> vertex_id;
                cout << "Смежные вершины: ";
                auto vertices = graph.adjacent_vertices(vertex_id);
                for (auto it = vertices.first; it != vertices.second; ++it) {
                    cout << *it << " ";
                }
                cout << endl;
                break;
            }

            case 15: {
                graph.clear();
                cout << "Граф очищен\n";
                break;
            }

            case 16: {
                if (graph.empty()) {
                    cout << "Граф пуст\n";
                }
                else {
                    cout << "Граф не пуст\n";
                }
                break;
            }

            case 17: {
                cout << graph << endl;
                break;
            }

            case 0: {
                cout << "Выход...\n";
                break;
            }

            default: {
                cout << "Неверный выбор!\n";
                break;
            }
            }
        }
        catch (const std::out_of_range& e) {
            cout << "ОШИБКА: " << e.what() << endl;
        }
        catch (const std::exception& e) {
            cout << "ОШИБКА: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
