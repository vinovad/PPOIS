#include "directed_graph.h"
#include <iostream>
#include <string>
#include <limits>

template<typename T>
void print_menu() {
    std::cout << "\n=== ���� ���������������� ����� ===" << std::endl;
    std::cout << "1.  �������� �������" << std::endl;
    std::cout << "2.  �������� �����" << std::endl;
    std::cout << "3.  ������� �������" << std::endl;
    std::cout << "4.  ������� �����" << std::endl;
    std::cout << "5.  ��������� ������� �������" << std::endl;
    std::cout << "6.  ��������� ������� �����" << std::endl;
    std::cout << "7.  �������� �������� �������" << std::endl;
    std::cout << "8.  ���������� ������" << std::endl;
    std::cout << "9.  ���������� �����" << std::endl;
    std::cout << "10. ��������� ������� �������" << std::endl;
    std::cout << "11. �������� ������� �������" << std::endl;
    std::cout << "12. ������ ������� �������" << std::endl;
    std::cout << "13. ������� �����" << std::endl;
    std::cout << "14. ������� ������ (���������)" << std::endl;
    std::cout << "15. ������� ����� (���������)" << std::endl;
    std::cout << "16. ��������� ����� �������" << std::endl;
    std::cout << "17. �������� ����� �������" << std::endl;
    std::cout << "18. ��� ����������� ����� �������" << std::endl;
    std::cout << "19. ��������� ������� �������" << std::endl;
    std::cout << "20. �������� ������� �������" << std::endl;
    std::cout << "21. ��� ������� �������" << std::endl;
    std::cout << "22. �������� ����" << std::endl;
    std::cout << "23. ��������� ������ �� ����" << std::endl;
    std::cout << "24. ������� ���� (�������� <<)" << std::endl;
    std::cout << "0.  �����" << std::endl;
    std::cout << "�������� ��������: ";
}

template<typename T>
void menu_add_vertex(DirectedGraph<T>& graph) {
    T value;
    std::cout << "������� �������� ��� ����� �������: ";
    std::cin >> value;
    auto id = graph.add_vertex(value);
    std::cout << "��������� ������� � ID: " << id << std::endl;
}

template<typename T>
void menu_add_edge(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type from, to;
    std::cout << "������� ID ��������� �������: ";
    std::cin >> from;
    std::cout << "������� ID �������� �������: ";
    std::cin >> to;

    try {
        graph.add_edge(from, to);
        std::cout << "����� " << from << " -> " << to << " ���������" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_remove_vertex(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID ������� ��� ��������: ";
    std::cin >> vertex_id;

    try {
        graph.remove_vertex(vertex_id);
        std::cout << "������� " << vertex_id << " �������" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_remove_edge(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type from, to;
    std::cout << "������� ID ��������� �������: ";
    std::cin >> from;
    std::cout << "������� ID �������� �������: ";
    std::cin >> to;

    try {
        graph.remove_edge(from, to);
        std::cout << "����� " << from << " -> " << to << " �������" << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_check_vertex(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;
    std::cout << "������� " << vertex_id << (graph.has_vertex(vertex_id) ? " ����������" : " �� ����������") << std::endl;
}

template<typename T>
void menu_check_edge(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type from, to;
    std::cout << "������� ID ��������� �������: ";
    std::cin >> from;
    std::cout << "������� ID �������� �������: ";
    std::cin >> to;
    std::cout << "����� " << from << " -> " << to << (graph.has_edge(from, to) ? " ����������" : " �� ����������") << std::endl;
}

template<typename T>
void menu_get_vertex(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        T value = graph.get_vertex(vertex_id);
        std::cout << "������� " << vertex_id << ": " << value << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_vertex_count(DirectedGraph<T>& graph) {
    std::cout << "���������� ������: " << graph.vertex_count() << std::endl;
}

template<typename T>
void menu_edge_count(DirectedGraph<T>& graph) {
    std::cout << "���������� �����: " << graph.edge_count() << std::endl;
}

template<typename T>
void menu_out_degree(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        std::cout << "��������� ������� ������� " << vertex_id << ": " << graph.out_degree(vertex_id) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_in_degree(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        std::cout << "�������� ������� ������� " << vertex_id << ": " << graph.in_degree(vertex_id) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_vertex_degree(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        std::cout << "������ ������� ������� " << vertex_id << ": " << graph.vertex_degree(vertex_id) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_edge_degree(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type from, to;
    std::cout << "������� ID ��������� �������: ";
    std::cin >> from;
    std::cout << "������� ID �������� �������: ";
    std::cin >> to;

    try {
        std::cout << "������� ����� " << from << " -> " << to << ": " << graph.edge_degree(from, to) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_iterate_vertices(DirectedGraph<T>& graph) {
    std::cout << "������� �����:" << std::endl;
    for (auto it = graph.begin_vertices(); it != graph.end_vertices(); ++it) {
        auto [id, value] = *it;
        std::cout << "[" << id << ": " << value << "] ";
    }
    std::cout << std::endl;
}

template<typename T>
void menu_iterate_edges(DirectedGraph<T>& graph) {
    std::cout << "����� �����:" << std::endl;
    for (auto it = graph.begin_edges(); it != graph.end_edges(); ++it) {
        const auto& edge = *it;
        std::cout << "(" << edge.from << "->" << edge.to << ") ";
    }
    std::cout << std::endl;
}

template<typename T>
void menu_outgoing_edges(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.outgoing_edges(vertex_id);
        std::cout << "��������� ����� ������� " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            const auto& edge = *it;
            std::cout << "(" << edge.from << "->" << edge.to << ") ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_incoming_edges(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.incoming_edges(vertex_id);
        std::cout << "�������� ����� ������� " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            const auto& edge = *it;
            std::cout << "(" << edge.from << "->" << edge.to << ") ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_incident_edges(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.incident_edges(vertex_id);
        std::cout << "��� ����������� ����� ������� " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            const auto& edge = *it;
            std::cout << "(" << edge.from << "->" << edge.to << ") ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_outgoing_vertices(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.outgoing_vertices(vertex_id);
        std::cout << "��������� ������� ������� " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_incoming_vertices(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.incoming_vertices(vertex_id);
        std::cout << "�������� ������� ������� " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_adjacent_vertices(DirectedGraph<T>& graph) {
    typename DirectedGraph<T>::size_type vertex_id;
    std::cout << "������� ID �������: ";
    std::cin >> vertex_id;

    try {
        auto [begin, end] = graph.adjacent_vertices(vertex_id);
        std::cout << "��� ������� ������� " << vertex_id << ": ";
        for (auto it = begin; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "������: " << e.what() << std::endl;
    }
}

template<typename T>
void menu_clear(DirectedGraph<T>& graph) {
    graph.clear();
    std::cout << "���� ������" << std::endl;
}

template<typename T>
void menu_empty(DirectedGraph<T>& graph) {
    std::cout << "���� " << (graph.empty() ? "������" : "�� ������") << std::endl;
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
        case 0: std::cout << "�����..." << std::endl; break;
        default: std::cout << "�������� �����!" << std::endl;
        }

        // ������� ������ �����
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 0);

    return 0;
}