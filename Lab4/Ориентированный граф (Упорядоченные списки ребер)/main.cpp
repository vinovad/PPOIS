#include "directed_graph.h"
#include <iostream>
#include <string>
#include <limits>

template<typename T>
void print_menu() {
    std::cout << "\n=== МЕНЮ ОРИЕНТИРОВАННОГО ГРАФА ===" << std::endl;
    std::cout << "1.  Добавить вершину" << std::endl;
    std::cout << "2.  Добавить ребро" << std::endl;
    std::cout << "3.  Удалить вершину" << std::endl;
    std::cout << "4.  Удалить ребро" << std::endl;
    std::cout << "5.  Проверить наличие вершины" << std::endl;
    std::cout << "6.  Проверить наличие ребра" << std::endl;
    std::cout << "7.  Получить значение вершины" << std::endl;
    std::cout << "8.  Количество вершин" << std::endl;
    std::cout << "9.  Количество ребер" << std::endl;
    std::cout << "10. Исходящая степень вершины" << std::endl;
    std::cout << "11. Входящая степень вершины" << std::endl;
    std::cout << "12. Полная степень вершины" << std::endl;
    std::cout << "13. Степень ребра" << std::endl;
    std::cout << "14. Перебор вершин (итераторы)" << std::endl;
    std::cout << "15. Перебор ребер (итераторы)" << std::endl;
    std::cout << "16. Исходящие ребра вершины" << std::endl;
    std::cout << "17. Входящие ребра вершины" << std::endl;
    std::cout << "18. Все инцидентные ребра вершины" << std::endl;
    std::cout << "19. Исходящие смежные вершины" << std::endl;
    std::cout << "20. Входящие смежные вершины" << std::endl;
    std::cout << "21. Все смежные вершины" << std::endl;
    std::cout << "22. Очистить граф" << std::endl;
    std::cout << "23. Проверить пустой ли граф" << std::endl;
    std::cout << "24. Вывести граф (оператор <<)" << std::endl;
    std::cout << "0.  Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

template<typename T>
void menu_add_vertex(DirectedGraph<T>& graph) {
    T value;
    std::cout << "Введите значение для новой вершины: ";
    std::cin >> value;
    auto id = graph.add_vertex(value);
    std::cout << "Добавлена вершина с ID: " << id << std::endl;
}

template<typename T>
void menu_add_edge(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type from, to;
    std::cout << "Введите ID начальной вершины: ";
    std::cin >> from;
    std::cout << "Введите ID конечной вершины: ";
    std::cin >> to;

    try {
        graph.add_edge(from, to);
        std::cout << "Ребро " << from << " -> " << to << " добавлено" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_remove_vertex(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины для удаления: ";
    std::cin >> vertex_id;

    try {
        graph.remove_vertex(vertex_id);
        std::cout << "Вершина " << vertex_id << " удалена" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_remove_edge(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type from, to;
    std::cout << "Введите ID начальной вершины: ";
    std::cin >> from;
    std::cout << "Введите ID конечной вершины: ";
    std::cin >> to;

    try {
        graph.remove_edge(from, to);
        std::cout << "Ребро " << from << " -> " << to << " удалено" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_check_vertex(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;
    std::cout << "Вершина " << vertex_id << (graph.has_vertex(vertex_id) ? " существует" : " не существует") << std::endl;
}

template<typename T>
void menu_check_edge(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type from, to;
    std::cout << "Введите ID начальной вершины: ";
    std::cin >> from;
    std::cout << "Введите ID конечной вершины: ";
    std::cin >> to;
    std::cout << "Ребро " << from << " -> " << to << (graph.has_edge(from, to) ? " существует" : " не существует") << std::endl;
}

template<typename T>
void menu_get_vertex(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        T value = graph.get_vertex(vertex_id);
        std::cout << "Вершина " << vertex_id << ": " << value << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_vertex_count(DirectedGraph<T>& graph) {
    std::cout << "Количество вершин: " << graph.vertex_count() << std::endl;
}

template<typename T>
void menu_edge_count(DirectedGraph<T>& graph) {
    std::cout << "Количество ребер: " << graph.edge_count() << std::endl;
}

template<typename T>
void menu_out_degree(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        std::cout << "Исходящая степень вершины " << vertex_id << ": " << graph.out_degree(vertex_id) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_in_degree(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        std::cout << "Входящая степень вершины " << vertex_id << ": " << graph.in_degree(vertex_id) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_vertex_degree(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        std::cout << "Полная степень вершины " << vertex_id << ": " << graph.vertex_degree(vertex_id) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_edge_degree(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type from, to;
    std::cout << "Введите ID начальной вершины: ";
    std::cin >> from;
    std::cout << "Введите ID конечной вершины: ";
    std::cin >> to;

    try {
        std::cout << "Степень ребра " << from << " -> " << to << ": " << graph.edge_degree(from, to) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_iterate_vertices(DirectedGraph<T>& graph) {
    std::cout << "Вершины графа:" << std::endl;
    for (auto it = graph.begin_vertices(); it != graph.end_vertices(); ++it) {
        auto [id, value] = *it;
        std::cout << "[" << id << ": " << value << "] ";
    }
    std::cout << std::endl;
}

template<typename T>
void menu_iterate_edges(DirectedGraph<T>& graph) {
    std::cout << "Ребра графа:" << std::endl;
    for (auto it = graph.begin_edges(); it != graph.end_edges(); ++it) {
        const auto& edge = *it;
        std::cout << "(" << edge.from << "->" << edge.to << ") ";
    }
    std::cout << std::endl;
}

template<typename T>
void menu_outgoing_edges(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.outgoing_edges(vertex_id);
        std::cout << "Исходящие ребра вершины " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            const auto& edge = *it;
            std::cout << "(" << edge.from << "->" << edge.to << ") ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_incoming_edges(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.incoming_edges(vertex_id);
        std::cout << "Входящие ребра вершины " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            const auto& edge = *it;
            std::cout << "(" << edge.from << "->" << edge.to << ") ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_incident_edges(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.incident_edges(vertex_id);
        std::cout << "Все инцидентные ребра вершины " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            const auto& edge = *it;
            std::cout << "(" << edge.from << "->" << edge.to << ") ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_outgoing_vertices(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.outgoing_vertices(vertex_id);
        std::cout << "Исходящие смежные вершины " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_incoming_vertices(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.incoming_vertices(vertex_id);
        std::cout << "Входящие смежные вершины " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_adjacent_vertices(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "Введите ID вершины: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.adjacent_vertices(vertex_id);
        std::cout << "Все смежные вершины " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_clear(DirectedGraph<T>& graph) {
    graph.clear();
    std::cout << "Граф очищен" << std::endl;
}

template<typename T>
void menu_empty(DirectedGraph<T>& graph) {
    std::cout << "Граф " << (graph.empty() ? "пустой" : "не пустой") << std::endl;
}

template<typename T>
void menu_display(DirectedGraph<T>& graph) {
    std::cout << graph << std::endl;
}

int main() {
    setlocale(0, "rus");
    DirectedGraph<std::string> graph;
    int choice;

    do {
        print_menu<std::string>();
        std::cin >> choice;

        switch (choice) {
        case 1: menu_add_vertex(graph); break;
        case 2: menu_add_edge(graph); break;
        case 3: menu_remove_vertex(graph); break;
        case 4: menu_remove_edge(graph); break;
        case 5: menu_check_vertex(graph); break;
        case 6: menu_check_edge(graph); break;
        case 7: menu_get_vertex(graph); break;
        case 8: menu_vertex_count(graph); break;
        case 9: menu_edge_count(graph); break;
        case 10: menu_out_degree(graph); break;
        case 11: menu_in_degree(graph); break;
        case 12: menu_vertex_degree(graph); break;
        case 13: menu_edge_degree(graph); break;
        case 14: menu_iterate_vertices(graph); break;
        case 15: menu_iterate_edges(graph); break;
        case 16: menu_outgoing_edges(graph); break;
        case 17: menu_incoming_edges(graph); break;
        case 18: menu_incident_edges(graph); break;
        case 19: menu_outgoing_vertices(graph); break;
        case 20: menu_incoming_vertices(graph); break;
        case 21: menu_adjacent_vertices(graph); break;
        case 22: menu_clear(graph); break;
        case 23: menu_empty(graph); break;
        case 24: menu_display(graph); break;
        case 0: std::cout << "Выход..." << std::endl; break;
        default: std::cout << "Неверный выбор!" << std::endl;
        }

        // Очистка буфера ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 0);

    return 0;
}