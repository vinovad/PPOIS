#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <map>//для ускорение доступа
#include <set>
#include <memory>// для временных коллекций в итераторах
#include <iterator>

// Шаблон ориентированного графа с использованием упорядоченных списков ребер
template<typename T>
class DirectedGraph {
public:
    // ==================== TYPEDEF'Ы ====================
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;

    // Структура для представления ребра
    struct Edge {
        size_type from;
        size_type to;

        Edge(size_type f, size_type t) : from(f), to(t) {}

        bool operator==(const Edge& other) const {
            return from == other.from && to == other.to;
        }

        bool operator<(const Edge& other) const {
            if (from != other.from) return from < other.from;
            return to < other.to;
        }
    };

private:
    std::vector<T> vertices_;  // Вершины графа
    std::set<Edge> edges_;     // Упорядоченное множество ребер

    // Вспомогательные структуры для быстрого доступа
    std::map<size_type, std::set<size_type>> outgoing_;  // Исходящие ребра
    std::map<size_type, std::set<size_type>> incoming_;  // Входящие ребра

    void rebuild_auxiliary_structures();

public:
    DirectedGraph();
    DirectedGraph(const DirectedGraph& other);
    ~DirectedGraph();
    DirectedGraph& operator=(const DirectedGraph& other);
    bool empty() const;
    void clear();
    // ==================== МЕТОДЫ ДЛЯ РАБОТЫ С ВЕРШИНАМИ ====================
    size_type add_vertex(const_reference value);
    bool has_vertex(size_type vertex_id) const;
    size_type vertex_count() const;
    reference get_vertex(size_type vertex_id);
    const_reference get_vertex(size_type vertex_id) const;
    void remove_vertex(size_type vertex_id);

    // ==================== МЕТОДЫ ДЛЯ РАБОТЫ С РЕБРАМИ ====================
    void add_edge(size_type from, size_type to);
    bool has_edge(size_type from, size_type to) const;
    size_type edge_count() const;
    void remove_edge(size_type from, size_type to);

    // ==================== СТЕПЕНИ ====================
    size_type out_degree(size_type vertex_id) const;
    size_type in_degree(size_type vertex_id) const;
    size_type vertex_degree(size_type vertex_id) const;
    size_type edge_degree(size_type from, size_type to) const;

    // ==================== ИТЕРАТОРЫ ДЛЯ ВЕРШИН ====================

    class VertexIterator {
    private:
        typename std::vector<T>::iterator it_;
        size_type index_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = std::pair<size_type, T>;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type;
        VertexIterator() : it_(), index_(0) {}
        VertexIterator(typename std::vector<T>::iterator it, size_type idx);
        reference operator*() const;
        VertexIterator& operator++();
        VertexIterator operator++(int);
        VertexIterator& operator--();
        VertexIterator operator--(int);
        bool operator==(const VertexIterator& other) const;
        bool operator!=(const VertexIterator& other) const;
        size_type get_index() const;
    };

    class ConstVertexIterator {
    private:
        typename std::vector<T>::const_iterator it_;
        size_type index_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = std::pair<size_type, T>;
        using difference_type = std::ptrdiff_t;
        using pointer = const value_type*;
        using reference = value_type;
        ConstVertexIterator() : it_(), index_(0) {}
        ConstVertexIterator(typename std::vector<T>::const_iterator it, size_type idx);
        reference operator*() const;
        ConstVertexIterator& operator++();
        ConstVertexIterator operator++(int);
        ConstVertexIterator& operator--();
        ConstVertexIterator operator--(int);
        bool operator==(const ConstVertexIterator& other) const;
        bool operator!=(const ConstVertexIterator& other) const;
        size_type get_index() const;
    };

    using ReverseVertexIterator = std::reverse_iterator<VertexIterator>;
    using ConstReverseVertexIterator = std::reverse_iterator<ConstVertexIterator>;
    VertexIterator begin_vertices();
    VertexIterator end_vertices();
    ConstVertexIterator begin_vertices() const;
    ConstVertexIterator end_vertices() const;
    ConstVertexIterator cbegin_vertices() const;
    ConstVertexIterator cend_vertices() const;
    ReverseVertexIterator rbegin_vertices();
    ReverseVertexIterator rend_vertices();
    ConstReverseVertexIterator crbegin_vertices() const;
    ConstReverseVertexIterator crend_vertices() const;

    // ==================== ИТЕРАТОРЫ ДЛЯ РЕБЕР ====================
    class EdgeIterator {
    private:
        typename std::set<Edge>::iterator it_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = Edge;
        using difference_type = std::ptrdiff_t;
        using pointer = const Edge*;
        using reference = const Edge&;
        EdgeIterator() : it_() {}
        EdgeIterator(typename std::set<Edge>::iterator it);
        reference operator*() const;
        pointer operator->() const;
        EdgeIterator& operator++();
        EdgeIterator operator++(int);
        EdgeIterator& operator--();
        EdgeIterator operator--(int);
        bool operator==(const EdgeIterator& other) const;
        bool operator!=(const EdgeIterator& other) const;
    };
    class ConstEdgeIterator {
    private:
        typename std::set<Edge>::const_iterator it_;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = Edge;
        using difference_type = std::ptrdiff_t;
        using pointer = const Edge*;
        using reference = const Edge&;
        ConstEdgeIterator() : it_() {}
        ConstEdgeIterator(typename std::set<Edge>::const_iterator it);
        reference operator*() const;
        pointer operator->() const;
        ConstEdgeIterator& operator++();
        ConstEdgeIterator operator++(int);
        ConstEdgeIterator& operator--();
        ConstEdgeIterator operator--(int);
        bool operator==(const ConstEdgeIterator& other) const;
        bool operator!=(const ConstEdgeIterator& other) const;
    };
    using ReverseEdgeIterator = std::reverse_iterator<EdgeIterator>;
    using ConstReverseEdgeIterator = std::reverse_iterator<ConstEdgeIterator>;
    EdgeIterator begin_edges();
    EdgeIterator end_edges();
    ConstEdgeIterator begin_edges() const;
    ConstEdgeIterator end_edges() const;
    ConstEdgeIterator cbegin_edges() const;
    ConstEdgeIterator cend_edges() const;
    ReverseEdgeIterator rbegin_edges();
    ReverseEdgeIterator rend_edges();
    ConstReverseEdgeIterator crbegin_edges() const;
    ConstReverseEdgeIterator crend_edges() const;

    // ==================== ИТЕРАТОРЫ ДЛЯ ИНЦИДЕНТНЫХ РЕБЕР ====================

    class IncidentEdgeIterator {
    private:
        std::shared_ptr<std::vector<Edge>> edges_;
        typename std::vector<Edge>::iterator it_;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = Edge;
        using difference_type = std::ptrdiff_t;
        using pointer = const Edge*;
        using reference = const Edge&;
        IncidentEdgeIterator()
            : edges_(std::make_shared<std::vector<Edge>>()), it_(edges_->begin()) {
        }
        IncidentEdgeIterator(std::shared_ptr<std::vector<Edge>> edges,
            typename std::vector<Edge>::iterator it);
        reference operator*() const;
        pointer operator->() const;
        IncidentEdgeIterator& operator++();
        IncidentEdgeIterator operator++(int);
        IncidentEdgeIterator& operator--();
        IncidentEdgeIterator operator--(int);
        bool operator==(const IncidentEdgeIterator& other) const;
        bool operator!=(const IncidentEdgeIterator& other) const;
    };

    class ConstIncidentEdgeIterator {
    private:
        std::shared_ptr<std::vector<Edge>> edges_;
        typename std::vector<Edge>::const_iterator it_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = Edge;
        using difference_type = std::ptrdiff_t;
        using pointer = const Edge*;
        using reference = const Edge&;
        ConstIncidentEdgeIterator()
            : edges_(std::make_shared<std::vector<Edge>>()), it_(edges_->begin()) {
        }
        ConstIncidentEdgeIterator(std::shared_ptr<std::vector<Edge>> edges,
            typename std::vector<Edge>::const_iterator it);
        reference operator*() const;
        pointer operator->() const;
        ConstIncidentEdgeIterator& operator++();
        ConstIncidentEdgeIterator operator++(int);
        ConstIncidentEdgeIterator& operator--();
        ConstIncidentEdgeIterator operator--(int);
        bool operator==(const ConstIncidentEdgeIterator& other) const;
        bool operator!=(const ConstIncidentEdgeIterator& other) const;
    };

    using ReverseIncidentEdgeIterator = std::reverse_iterator<IncidentEdgeIterator>;
    using ConstReverseIncidentEdgeIterator = std::reverse_iterator<ConstIncidentEdgeIterator>;

    std::pair<IncidentEdgeIterator, IncidentEdgeIterator> outgoing_edges(size_type vertex_id);
    std::pair<IncidentEdgeIterator, IncidentEdgeIterator> incoming_edges(size_type vertex_id);
    std::pair<IncidentEdgeIterator, IncidentEdgeIterator> incident_edges(size_type vertex_id);

    std::pair<ConstIncidentEdgeIterator, ConstIncidentEdgeIterator> outgoing_edges(size_type vertex_id) const;
    std::pair<ConstIncidentEdgeIterator, ConstIncidentEdgeIterator> incoming_edges(size_type vertex_id) const;
    std::pair<ConstIncidentEdgeIterator, ConstIncidentEdgeIterator> incident_edges(size_type vertex_id) const;

    std::pair<ReverseIncidentEdgeIterator, ReverseIncidentEdgeIterator> routgoing_edges(size_type vertex_id);
    std::pair<ReverseIncidentEdgeIterator, ReverseIncidentEdgeIterator> rincoming_edges(size_type vertex_id);
    std::pair<ReverseIncidentEdgeIterator, ReverseIncidentEdgeIterator> rincident_edges(size_type vertex_id);

    std::pair<ConstReverseIncidentEdgeIterator, ConstReverseIncidentEdgeIterator> croutgoing_edges(size_type vertex_id) const;
    std::pair<ConstReverseIncidentEdgeIterator, ConstReverseIncidentEdgeIterator> crincoming_edges(size_type vertex_id) const;
    std::pair<ConstReverseIncidentEdgeIterator, ConstReverseIncidentEdgeIterator> crincident_edges(size_type vertex_id) const;

    // ==================== ИТЕРАТОРЫ ДЛЯ СМЕЖНЫХ ВЕРШИН ====================

    class AdjacentVertexIterator {
    private:
        std::shared_ptr<std::vector<size_type>> vertices_;
        typename std::vector<size_type>::iterator it_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = size_type;
        using difference_type = std::ptrdiff_t;
        using pointer = const size_type*;
        using reference = const size_type&;
        AdjacentVertexIterator()
            : vertices_(std::make_shared<std::vector<size_type>>()), it_(vertices_->begin()) {
        }
        AdjacentVertexIterator(std::shared_ptr<std::vector<size_type>> verts,
            typename std::vector<size_type>::iterator it);
        reference operator*() const;
        pointer operator->() const;
        AdjacentVertexIterator& operator++();
        AdjacentVertexIterator operator++(int);
        AdjacentVertexIterator& operator--();
        AdjacentVertexIterator operator--(int);
        bool operator==(const AdjacentVertexIterator& other) const;
        bool operator!=(const AdjacentVertexIterator& other) const;
    };

    class ConstAdjacentVertexIterator {
    private:
        std::shared_ptr<std::vector<size_type>> vertices_;
        typename std::vector<size_type>::const_iterator it_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = size_type;
        using difference_type = std::ptrdiff_t;
        using pointer = const size_type*;
        using reference = const size_type&;
        ConstAdjacentVertexIterator()
            : vertices_(std::make_shared<std::vector<size_type>>()), it_(vertices_->begin()) {
        }
        ConstAdjacentVertexIterator(std::shared_ptr<std::vector<size_type>> verts,
            typename std::vector<size_type>::const_iterator it);
        reference operator*() const;
        pointer operator->() const;
        ConstAdjacentVertexIterator& operator++();
        ConstAdjacentVertexIterator operator++(int);
        ConstAdjacentVertexIterator& operator--();
        ConstAdjacentVertexIterator operator--(int);
        bool operator==(const ConstAdjacentVertexIterator& other) const;
        bool operator!=(const ConstAdjacentVertexIterator& other) const;
    };

    using ReverseAdjacentVertexIterator = std::reverse_iterator<AdjacentVertexIterator>;
    using ConstReverseAdjacentVertexIterator = std::reverse_iterator<ConstAdjacentVertexIterator>;

    std::pair<AdjacentVertexIterator, AdjacentVertexIterator> outgoing_vertices(size_type vertex_id);
    std::pair<AdjacentVertexIterator, AdjacentVertexIterator> incoming_vertices(size_type vertex_id);
    std::pair<AdjacentVertexIterator, AdjacentVertexIterator> adjacent_vertices(size_type vertex_id);

    std::pair<ConstAdjacentVertexIterator, ConstAdjacentVertexIterator> outgoing_vertices(size_type vertex_id) const;
    std::pair<ConstAdjacentVertexIterator, ConstAdjacentVertexIterator> incoming_vertices(size_type vertex_id) const;
    std::pair<ConstAdjacentVertexIterator, ConstAdjacentVertexIterator> adjacent_vertices(size_type vertex_id) const;

    std::pair<ReverseAdjacentVertexIterator, ReverseAdjacentVertexIterator> routgoing_vertices(size_type vertex_id);
    std::pair<ReverseAdjacentVertexIterator, ReverseAdjacentVertexIterator> rincoming_vertices(size_type vertex_id);
    std::pair<ReverseAdjacentVertexIterator, ReverseAdjacentVertexIterator> radjacent_vertices(size_type vertex_id);

    std::pair<ConstReverseAdjacentVertexIterator, ConstReverseAdjacentVertexIterator> croutgoing_vertices(size_type vertex_id) const;
    std::pair<ConstReverseAdjacentVertexIterator, ConstReverseAdjacentVertexIterator> crincoming_vertices(size_type vertex_id) const;
    std::pair<ConstReverseAdjacentVertexIterator, ConstReverseAdjacentVertexIterator> cradjacent_vertices(size_type vertex_id) const;

    // ==================== УДАЛЕНИЕ ПО ИТЕРАТОРАМ ====================
    void remove_vertex(VertexIterator it);
    void remove_edge(EdgeIterator it);

    // ==================== ОПЕРАТОРЫ СРАВНЕНИЯ ====================
    bool operator==(const DirectedGraph& other) const;
    bool operator!=(const DirectedGraph& other) const;
    bool operator<(const DirectedGraph& other) const;
    bool operator>(const DirectedGraph& other) const;
    bool operator<=(const DirectedGraph& other) const;
    bool operator>=(const DirectedGraph& other) const;

    // ==================== ОПЕРАТОР ВЫВОДА ====================
    friend std::ostream& operator<<(std::ostream& os, const DirectedGraph& graph) {
        os << "DirectedGraph with " << graph.vertex_count()
            << " vertices and " << graph.edge_count() << " edges:\n";

        os << "Vertices: ";
        std::for_each(graph.cbegin_vertices(), graph.cend_vertices(),
            [&os](const std::pair<size_type, T>& v) {
                os << "[" << v.first << ": " << v.second << "] ";
            });
        os << "\n";

        os << "Edges: ";
        std::for_each(graph.cbegin_edges(), graph.cend_edges(),
            [&os](const Edge& e) {
                os << "(" << e.from << "->" << e.to << ") ";
            });
        os << "\n";

        return os;
    }
};


template<typename T>
DirectedGraph<T>::DirectedGraph() = default;

template<typename T>
DirectedGraph<T>::DirectedGraph(const DirectedGraph& other)
    : vertices_(other.vertices_),
    edges_(other.edges_),
    outgoing_(other.outgoing_),
    incoming_(other.incoming_) {
}

template<typename T>
DirectedGraph<T>::~DirectedGraph() = default;

template<typename T>
DirectedGraph<T>& DirectedGraph<T>::operator=(const DirectedGraph& other) {
    if (this != &other) {
        vertices_ = other.vertices_;
        edges_ = other.edges_;
        outgoing_ = other.outgoing_;
        incoming_ = other.incoming_;
    }
    return *this;
}

template<typename T>
bool DirectedGraph<T>::empty() const {
    return vertices_.empty();
}

template<typename T>
void DirectedGraph<T>::clear() {
    vertices_.clear();
    edges_.clear();
    outgoing_.clear();
    incoming_.clear();
}

// Методы для вершин
template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::add_vertex(const_reference value) {
    vertices_.push_back(value);
    return vertices_.size() - 1;
}

template<typename T>
bool DirectedGraph<T>::has_vertex(size_type vertex_id) const {
    return vertex_id < vertices_.size();
}

template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::vertex_count() const {
    return vertices_.size();
}

template<typename T>
typename DirectedGraph<T>::reference DirectedGraph<T>::get_vertex(size_type vertex_id) {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }
    return vertices_[vertex_id];
}

template<typename T>
typename DirectedGraph<T>::const_reference DirectedGraph<T>::get_vertex(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }
    return vertices_[vertex_id];
}

template<typename T>
void DirectedGraph<T>::remove_vertex(size_type vertex_id) {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto it = edges_.begin();
    while (it != edges_.end()) {
        if (it->from == vertex_id || it->to == vertex_id) {
            auto to_remove = it++;
            edges_.erase(to_remove);
        }
        else {
            ++it;
        }
    }

    outgoing_.erase(vertex_id);
    incoming_.erase(vertex_id);

    for (auto& [key, set] : outgoing_) {
        set.erase(vertex_id);
    }
    for (auto& [key, set] : incoming_) {
        set.erase(vertex_id);
    }

    vertices_.erase(vertices_.begin() + vertex_id);

    std::set<Edge> new_edges;
    for (const auto& e : edges_) {
        size_type new_from = e.from > vertex_id ? e.from - 1 : e.from;
        size_type new_to = e.to > vertex_id ? e.to - 1 : e.to;
        new_edges.insert(Edge(new_from, new_to));
    }
    edges_ = std::move(new_edges);

    rebuild_auxiliary_structures();
}

template<typename T>
void DirectedGraph<T>::add_edge(size_type from, size_type to) {
    if (!has_vertex(from) || !has_vertex(to)) {
        throw std::out_of_range("Vertex does not exist");
    }

    Edge edge(from, to);
    edges_.insert(edge);
    outgoing_[from].insert(to);
    incoming_[to].insert(from);
}

template<typename T>
bool DirectedGraph<T>::has_edge(size_type from, size_type to) const {
    return edges_.find(Edge(from, to)) != edges_.end();
}

template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::edge_count() const {
    return edges_.size();
}

template<typename T>
void DirectedGraph<T>::remove_edge(size_type from, size_type to) {
    Edge edge(from, to);
    auto it = edges_.find(edge);
    if (it == edges_.end()) {
        throw std::out_of_range("Edge does not exist");
    }

    edges_.erase(it);
    outgoing_[from].erase(to);
    incoming_[to].erase(from);
}

template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::out_degree(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }
    auto it = outgoing_.find(vertex_id);
    return it != outgoing_.end() ? it->second.size() : 0;
}

template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::in_degree(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }
    auto it = incoming_.find(vertex_id);
    return it != incoming_.end() ? it->second.size() : 0;
}

template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::vertex_degree(size_type vertex_id) const {
    return out_degree(vertex_id) + in_degree(vertex_id);
}

template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::edge_degree(size_type from, size_type to) const {
    if (!has_edge(from, to)) {
        throw std::out_of_range("Edge does not exist");
    }
    return vertex_degree(from) + vertex_degree(to);
}

template<typename T>
DirectedGraph<T>::VertexIterator::VertexIterator(typename std::vector<T>::iterator it, size_type idx)
    : it_(it), index_(idx) {
}

template<typename T>
typename DirectedGraph<T>::VertexIterator::reference DirectedGraph<T>::VertexIterator::operator*() const {
    return std::make_pair(index_, *it_);
}

template<typename T>
typename DirectedGraph<T>::VertexIterator& DirectedGraph<T>::VertexIterator::operator++() {
    ++it_;
    ++index_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::VertexIterator DirectedGraph<T>::VertexIterator::operator++(int) {
    VertexIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DirectedGraph<T>::VertexIterator& DirectedGraph<T>::VertexIterator::operator--() {
    --it_;
    --index_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::VertexIterator DirectedGraph<T>::VertexIterator::operator--(int) {
    VertexIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool DirectedGraph<T>::VertexIterator::operator==(const VertexIterator& other) const {
    return it_ == other.it_;
}

template<typename T>
bool DirectedGraph<T>::VertexIterator::operator!=(const VertexIterator& other) const {
    return it_ != other.it_;
}

template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::VertexIterator::get_index() const {
    return index_;
}

template<typename T>
DirectedGraph<T>::ConstVertexIterator::ConstVertexIterator(typename std::vector<T>::const_iterator it, size_type idx)
    : it_(it), index_(idx) {
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator::reference DirectedGraph<T>::ConstVertexIterator::operator*() const {
    return std::make_pair(index_, *it_);
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator& DirectedGraph<T>::ConstVertexIterator::operator++() {
    ++it_;
    ++index_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator DirectedGraph<T>::ConstVertexIterator::operator++(int) {
    ConstVertexIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator& DirectedGraph<T>::ConstVertexIterator::operator--() {
    --it_;
    --index_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator DirectedGraph<T>::ConstVertexIterator::operator--(int) {
    ConstVertexIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool DirectedGraph<T>::ConstVertexIterator::operator==(const ConstVertexIterator& other) const {
    return it_ == other.it_;
}

template<typename T>
bool DirectedGraph<T>::ConstVertexIterator::operator!=(const ConstVertexIterator& other) const {
    return it_ != other.it_;
}

template<typename T>
typename DirectedGraph<T>::size_type DirectedGraph<T>::ConstVertexIterator::get_index() const {
    return index_;
}

// Методы для получения итераторов вершин
template<typename T>
typename DirectedGraph<T>::VertexIterator DirectedGraph<T>::begin_vertices() {
    return VertexIterator(vertices_.begin(), 0);
}

template<typename T>
typename DirectedGraph<T>::VertexIterator DirectedGraph<T>::end_vertices() {
    return VertexIterator(vertices_.end(), vertices_.size());
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator DirectedGraph<T>::begin_vertices() const {
    return ConstVertexIterator(vertices_.begin(), 0);
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator DirectedGraph<T>::end_vertices() const {
    return ConstVertexIterator(vertices_.end(), vertices_.size());
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator DirectedGraph<T>::cbegin_vertices() const {
    return ConstVertexIterator(vertices_.begin(), 0);
}

template<typename T>
typename DirectedGraph<T>::ConstVertexIterator DirectedGraph<T>::cend_vertices() const {
    return ConstVertexIterator(vertices_.end(), vertices_.size());
}

template<typename T>
typename DirectedGraph<T>::ReverseVertexIterator DirectedGraph<T>::rbegin_vertices() {
    return ReverseVertexIterator(end_vertices());
}

template<typename T>
typename DirectedGraph<T>::ReverseVertexIterator DirectedGraph<T>::rend_vertices() {
    return ReverseVertexIterator(begin_vertices());
}

template<typename T>
typename DirectedGraph<T>::ConstReverseVertexIterator DirectedGraph<T>::crbegin_vertices() const {
    return ConstReverseVertexIterator(end_vertices());
}

template<typename T>
typename DirectedGraph<T>::ConstReverseVertexIterator DirectedGraph<T>::crend_vertices() const {
    return ConstReverseVertexIterator(begin_vertices());
}
template<typename T>
DirectedGraph<T>::EdgeIterator::EdgeIterator(typename std::set<Edge>::iterator it) : it_(it) {}

template<typename T>
typename DirectedGraph<T>::EdgeIterator::reference DirectedGraph<T>::EdgeIterator::operator*() const {
    return *it_;
}

template<typename T>
typename DirectedGraph<T>::EdgeIterator::pointer DirectedGraph<T>::EdgeIterator::operator->() const {
    return &(*it_);
}

template<typename T>
typename DirectedGraph<T>::EdgeIterator& DirectedGraph<T>::EdgeIterator::operator++() {
    ++it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::EdgeIterator DirectedGraph<T>::EdgeIterator::operator++(int) {
    EdgeIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DirectedGraph<T>::EdgeIterator& DirectedGraph<T>::EdgeIterator::operator--() {
    --it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::EdgeIterator DirectedGraph<T>::EdgeIterator::operator--(int) {
    EdgeIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool DirectedGraph<T>::EdgeIterator::operator==(const EdgeIterator& other) const {
    return it_ == other.it_;
}

template<typename T>
bool DirectedGraph<T>::EdgeIterator::operator!=(const EdgeIterator& other) const {
    return it_ != other.it_;
}
template<typename T>
DirectedGraph<T>::ConstEdgeIterator::ConstEdgeIterator(typename std::set<Edge>::const_iterator it) : it_(it) {}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator::reference DirectedGraph<T>::ConstEdgeIterator::operator*() const {
    return *it_;
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator::pointer DirectedGraph<T>::ConstEdgeIterator::operator->() const {
    return &(*it_);
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator& DirectedGraph<T>::ConstEdgeIterator::operator++() {
    ++it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator DirectedGraph<T>::ConstEdgeIterator::operator++(int) {
    ConstEdgeIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator& DirectedGraph<T>::ConstEdgeIterator::operator--() {
    --it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator DirectedGraph<T>::ConstEdgeIterator::operator--(int) {
    ConstEdgeIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool DirectedGraph<T>::ConstEdgeIterator::operator==(const ConstEdgeIterator& other) const {
    return it_ == other.it_;
}

template<typename T>
bool DirectedGraph<T>::ConstEdgeIterator::operator!=(const ConstEdgeIterator& other) const {
    return it_ != other.it_;
}

// Методы для получения итераторов ребер
template<typename T>
typename DirectedGraph<T>::EdgeIterator DirectedGraph<T>::begin_edges() {
    return EdgeIterator(edges_.begin());
}

template<typename T>
typename DirectedGraph<T>::EdgeIterator DirectedGraph<T>::end_edges() {
    return EdgeIterator(edges_.end());
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator DirectedGraph<T>::begin_edges() const {
    return ConstEdgeIterator(edges_.begin());
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator DirectedGraph<T>::end_edges() const {
    return ConstEdgeIterator(edges_.end());
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator DirectedGraph<T>::cbegin_edges() const {
    return ConstEdgeIterator(edges_.begin());
}

template<typename T>
typename DirectedGraph<T>::ConstEdgeIterator DirectedGraph<T>::cend_edges() const {
    return ConstEdgeIterator(edges_.end());
}

template<typename T>
typename DirectedGraph<T>::ReverseEdgeIterator DirectedGraph<T>::rbegin_edges() {
    return ReverseEdgeIterator(end_edges());
}

template<typename T>
typename DirectedGraph<T>::ReverseEdgeIterator DirectedGraph<T>::rend_edges() {
    return ReverseEdgeIterator(begin_edges());
}

template<typename T>
typename DirectedGraph<T>::ConstReverseEdgeIterator DirectedGraph<T>::crbegin_edges() const {
    return ConstReverseEdgeIterator(end_edges());
}

template<typename T>
typename DirectedGraph<T>::ConstReverseEdgeIterator DirectedGraph<T>::crend_edges() const {
    return ConstReverseEdgeIterator(begin_edges());
}
template<typename T>
DirectedGraph<T>::IncidentEdgeIterator::IncidentEdgeIterator(
    std::shared_ptr<std::vector<Edge>> edges,
    typename std::vector<Edge>::iterator it)
    : edges_(edges), it_(it) {
}

template<typename T>
typename DirectedGraph<T>::IncidentEdgeIterator::reference
DirectedGraph<T>::IncidentEdgeIterator::operator*() const {
    return *it_;
}

template<typename T>
typename DirectedGraph<T>::IncidentEdgeIterator::pointer
DirectedGraph<T>::IncidentEdgeIterator::operator->() const {
    return &(*it_);
}

template<typename T>
typename DirectedGraph<T>::IncidentEdgeIterator&
DirectedGraph<T>::IncidentEdgeIterator::operator++() {
    ++it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::IncidentEdgeIterator
DirectedGraph<T>::IncidentEdgeIterator::operator++(int) {
    IncidentEdgeIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DirectedGraph<T>::IncidentEdgeIterator&
DirectedGraph<T>::IncidentEdgeIterator::operator--() {
    --it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::IncidentEdgeIterator
DirectedGraph<T>::IncidentEdgeIterator::operator--(int) {
    IncidentEdgeIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool DirectedGraph<T>::IncidentEdgeIterator::operator==(const IncidentEdgeIterator& other) const {
    return it_ == other.it_;
}

template<typename T>
bool DirectedGraph<T>::IncidentEdgeIterator::operator!=(const IncidentEdgeIterator& other) const {
    return it_ != other.it_;
}
template<typename T>
DirectedGraph<T>::ConstIncidentEdgeIterator::ConstIncidentEdgeIterator(
    std::shared_ptr<std::vector<Edge>> edges,
    typename std::vector<Edge>::const_iterator it)
    : edges_(edges), it_(it) {
}

template<typename T>
typename DirectedGraph<T>::ConstIncidentEdgeIterator::reference
DirectedGraph<T>::ConstIncidentEdgeIterator::operator*() const {
    return *it_;
}

template<typename T>
typename DirectedGraph<T>::ConstIncidentEdgeIterator::pointer
DirectedGraph<T>::ConstIncidentEdgeIterator::operator->() const {
    return &(*it_);
}

template<typename T>
typename DirectedGraph<T>::ConstIncidentEdgeIterator&
DirectedGraph<T>::ConstIncidentEdgeIterator::operator++() {
    ++it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::ConstIncidentEdgeIterator
DirectedGraph<T>::ConstIncidentEdgeIterator::operator++(int) {
    ConstIncidentEdgeIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DirectedGraph<T>::ConstIncidentEdgeIterator&
DirectedGraph<T>::ConstIncidentEdgeIterator::operator--() {
    --it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::ConstIncidentEdgeIterator
DirectedGraph<T>::ConstIncidentEdgeIterator::operator--(int) {
    ConstIncidentEdgeIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool DirectedGraph<T>::ConstIncidentEdgeIterator::operator==(const ConstIncidentEdgeIterator& other) const {
    return it_ == other.it_;
}

template<typename T>
bool DirectedGraph<T>::ConstIncidentEdgeIterator::operator!=(const ConstIncidentEdgeIterator& other) const {
    return it_ != other.it_;
}
template<typename T>
std::pair<typename DirectedGraph<T>::IncidentEdgeIterator,
    typename DirectedGraph<T>::IncidentEdgeIterator>
    DirectedGraph<T>::outgoing_edges(size_type vertex_id) {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<Edge>>();
    for (const auto& edge : edges_) {
        if (edge.from == vertex_id) {
            vec->push_back(edge);
        }
    }

    return { IncidentEdgeIterator(vec, vec->begin()),
            IncidentEdgeIterator(vec, vec->end()) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::IncidentEdgeIterator,
    typename DirectedGraph<T>::IncidentEdgeIterator>
    DirectedGraph<T>::incoming_edges(size_type vertex_id) {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<Edge>>();
    for (const auto& edge : edges_) {
        if (edge.to == vertex_id) {
            vec->push_back(edge);
        }
    }

    return { IncidentEdgeIterator(vec, vec->begin()),
            IncidentEdgeIterator(vec, vec->end()) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::IncidentEdgeIterator,
    typename DirectedGraph<T>::IncidentEdgeIterator>
    DirectedGraph<T>::incident_edges(size_type vertex_id) {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<Edge>>();
    for (const auto& edge : edges_) {
        if (edge.from == vertex_id || edge.to == vertex_id) {
            vec->push_back(edge);
        }
    }

    return { IncidentEdgeIterator(vec, vec->begin()),
            IncidentEdgeIterator(vec, vec->end()) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ConstIncidentEdgeIterator,
    typename DirectedGraph<T>::ConstIncidentEdgeIterator>
    DirectedGraph<T>::outgoing_edges(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<Edge>>();
    for (const auto& edge : edges_) {
        if (edge.from == vertex_id) {
            vec->push_back(edge);
        }
    }

    return { ConstIncidentEdgeIterator(vec, vec->begin()),
            ConstIncidentEdgeIterator(vec, vec->end()) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ConstIncidentEdgeIterator,
    typename DirectedGraph<T>::ConstIncidentEdgeIterator>
    DirectedGraph<T>::incoming_edges(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<Edge>>();
    for (const auto& edge : edges_) {
        if (edge.to == vertex_id) {
            vec->push_back(edge);
        }
    }

    return { ConstIncidentEdgeIterator(vec, vec->begin()),
            ConstIncidentEdgeIterator(vec, vec->end()) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ConstIncidentEdgeIterator,
    typename DirectedGraph<T>::ConstIncidentEdgeIterator>
    DirectedGraph<T>::incident_edges(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<Edge>>();
    for (const auto& edge : edges_) {
        if (edge.from == vertex_id || edge.to == vertex_id) {
            vec->push_back(edge);
        }
    }

    return { ConstIncidentEdgeIterator(vec, vec->begin()),
            ConstIncidentEdgeIterator(vec, vec->end()) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ReverseIncidentEdgeIterator,
    typename DirectedGraph<T>::ReverseIncidentEdgeIterator>
    DirectedGraph<T>::routgoing_edges(size_type vertex_id) {
    auto [begin, end] = outgoing_edges(vertex_id);
    return { ReverseIncidentEdgeIterator(end), ReverseIncidentEdgeIterator(begin) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ReverseIncidentEdgeIterator,
    typename DirectedGraph<T>::ReverseIncidentEdgeIterator>
    DirectedGraph<T>::rincoming_edges(size_type vertex_id) {
    auto [begin, end] = incoming_edges(vertex_id);
    return { ReverseIncidentEdgeIterator(end), ReverseIncidentEdgeIterator(begin) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ReverseIncidentEdgeIterator,
    typename DirectedGraph<T>::ReverseIncidentEdgeIterator>
    DirectedGraph<T>::rincident_edges(size_type vertex_id) {
    auto [begin, end] = incident_edges(vertex_id);
    return { ReverseIncidentEdgeIterator(end), ReverseIncidentEdgeIterator(begin) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ConstReverseIncidentEdgeIterator,
    typename DirectedGraph<T>::ConstReverseIncidentEdgeIterator>
    DirectedGraph<T>::croutgoing_edges(size_type vertex_id) const {
    auto [begin, end] = outgoing_edges(vertex_id);
    return { ConstReverseIncidentEdgeIterator(end), ConstReverseIncidentEdgeIterator(begin) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ConstReverseIncidentEdgeIterator,
    typename DirectedGraph<T>::ConstReverseIncidentEdgeIterator>
    DirectedGraph<T>::crincoming_edges(size_type vertex_id) const {
    auto [begin, end] = incoming_edges(vertex_id);
    return { ConstReverseIncidentEdgeIterator(end), ConstReverseIncidentEdgeIterator(begin) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ConstReverseIncidentEdgeIterator,
    typename DirectedGraph<T>::ConstReverseIncidentEdgeIterator>
    DirectedGraph<T>::crincident_edges(size_type vertex_id) const {
    auto [begin, end] = incident_edges(vertex_id);
    return { ConstReverseIncidentEdgeIterator(end), ConstReverseIncidentEdgeIterator(begin) };
}

template<typename T>
DirectedGraph<T>::AdjacentVertexIterator::AdjacentVertexIterator(
    std::shared_ptr<std::vector<size_type>> verts,
    typename std::vector<size_type>::iterator it)
    : vertices_(verts), it_(it) {
}

template<typename T>
typename DirectedGraph<T>::AdjacentVertexIterator::reference
DirectedGraph<T>::AdjacentVertexIterator::operator*() const {
    return *it_;
}

template<typename T>
typename DirectedGraph<T>::AdjacentVertexIterator::pointer
DirectedGraph<T>::AdjacentVertexIterator::operator->() const {
    return &(*it_);
}

template<typename T>
typename DirectedGraph<T>::AdjacentVertexIterator&
DirectedGraph<T>::AdjacentVertexIterator::operator++() {
    ++it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::AdjacentVertexIterator
DirectedGraph<T>::AdjacentVertexIterator::operator++(int) {
    AdjacentVertexIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DirectedGraph<T>::AdjacentVertexIterator&
DirectedGraph<T>::AdjacentVertexIterator::operator--() {
    --it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::AdjacentVertexIterator
DirectedGraph<T>::AdjacentVertexIterator::operator--(int) {
    AdjacentVertexIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool DirectedGraph<T>::AdjacentVertexIterator::operator==(const AdjacentVertexIterator& other) const {
    return it_ == other.it_;
}

template<typename T>
bool DirectedGraph<T>::AdjacentVertexIterator::operator!=(const AdjacentVertexIterator& other) const {
    return it_ != other.it_;
}
template<typename T>
DirectedGraph<T>::ConstAdjacentVertexIterator::ConstAdjacentVertexIterator(
    std::shared_ptr<std::vector<size_type>> verts,
    typename std::vector<size_type>::const_iterator it)
    : vertices_(verts), it_(it) {
}

template<typename T>
typename DirectedGraph<T>::ConstAdjacentVertexIterator::reference
DirectedGraph<T>::ConstAdjacentVertexIterator::operator*() const {
    return *it_;
}

template<typename T>
typename DirectedGraph<T>::ConstAdjacentVertexIterator::pointer
DirectedGraph<T>::ConstAdjacentVertexIterator::operator->() const {
    return &(*it_);
}

template<typename T>
typename DirectedGraph<T>::ConstAdjacentVertexIterator&
DirectedGraph<T>::ConstAdjacentVertexIterator::operator++() {
    ++it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::ConstAdjacentVertexIterator
DirectedGraph<T>::ConstAdjacentVertexIterator::operator++(int) {
    ConstAdjacentVertexIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
typename DirectedGraph<T>::ConstAdjacentVertexIterator&
DirectedGraph<T>::ConstAdjacentVertexIterator::operator--() {
    --it_;
    return *this;
}

template<typename T>
typename DirectedGraph<T>::ConstAdjacentVertexIterator
DirectedGraph<T>::ConstAdjacentVertexIterator::operator--(int) {
    ConstAdjacentVertexIterator tmp = *this;
    --(*this);
    return tmp;
}

template<typename T>
bool DirectedGraph<T>::ConstAdjacentVertexIterator::operator==(const ConstAdjacentVertexIterator& other) const {
    return it_ == other.it_;
}

template<typename T>
bool DirectedGraph<T>::ConstAdjacentVertexIterator::operator!=(const ConstAdjacentVertexIterator& other) const {
    return it_ != other.it_;
}

template<typename T>
std::pair<typename DirectedGraph<T>::AdjacentVertexIterator,
    typename DirectedGraph<T>::AdjacentVertexIterator>
    DirectedGraph<T>::outgoing_vertices(size_type vertex_id) {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<size_type>>();
    auto it = outgoing_.find(vertex_id);
    if (it != outgoing_.end()) {
        vec->assign(it->second.begin(), it->second.end());
    }

    return { AdjacentVertexIterator(vec, vec->begin()),
            AdjacentVertexIterator(vec, vec->end()) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::AdjacentVertexIterator,
    typename DirectedGraph<T>::AdjacentVertexIterator>
    DirectedGraph<T>::incoming_vertices(size_type vertex_id) {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<size_type>>();
    auto it = incoming_.find(vertex_id);
    if (it != incoming_.end()) {
        vec->assign(it->second.begin(), it->second.end());
    }

    return { AdjacentVertexIterator(vec, vec->begin()),
            AdjacentVertexIterator(vec, vec->end()) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::AdjacentVertexIterator,
    typename DirectedGraph<T>::AdjacentVertexIterator>
    DirectedGraph<T>::adjacent_vertices(size_type vertex_id) {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    std::set<size_type> adjacent_set;
    auto it_out = outgoing_.find(vertex_id);
    if (it_out != outgoing_.end()) {
        adjacent_set.insert(it_out->second.begin(), it_out->second.end());
    }
    auto it_in = incoming_.find(vertex_id);
    if (it_in != incoming_.end()) {
        adjacent_set.insert(it_in->second.begin(), it_in->second.end());
    }

    auto vec = std::make_shared<std::vector<size_type>>(adjacent_set.begin(), adjacent_set.end());
    return { AdjacentVertexIterator(vec, vec->begin()),
            AdjacentVertexIterator(vec, vec->end()) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ConstAdjacentVertexIterator,
    typename DirectedGraph<T>::ConstAdjacentVertexIterator>
    DirectedGraph<T>::outgoing_vertices(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<size_type>>();
    auto it = outgoing_.find(vertex_id);
    if (it != outgoing_.end()) {
        vec->assign(it->second.begin(), it->second.end());
    }

    return { ConstAdjacentVertexIterator(vec, vec->begin()),
            ConstAdjacentVertexIterator(vec, vec->end()) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ConstAdjacentVertexIterator,
    typename DirectedGraph<T>::ConstAdjacentVertexIterator>
    DirectedGraph<T>::incoming_vertices(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    auto vec = std::make_shared<std::vector<size_type>>();
    auto it = incoming_.find(vertex_id);
    if (it != incoming_.end()) {
        vec->assign(it->second.begin(), it->second.end());
    }

    return { ConstAdjacentVertexIterator(vec, vec->begin()),
            ConstAdjacentVertexIterator(vec, vec->end()) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ConstAdjacentVertexIterator,
    typename DirectedGraph<T>::ConstAdjacentVertexIterator>
    DirectedGraph<T>::adjacent_vertices(size_type vertex_id) const {
    if (!has_vertex(vertex_id)) {
        throw std::out_of_range("Vertex does not exist");
    }

    std::set<size_type> adjacent_set;
    auto it_out = outgoing_.find(vertex_id);
    if (it_out != outgoing_.end()) {
        adjacent_set.insert(it_out->second.begin(), it_out->second.end());
    }
    auto it_in = incoming_.find(vertex_id);
    if (it_in != incoming_.end()) {
        adjacent_set.insert(it_in->second.begin(), it_in->second.end());
    }

    auto vec = std::make_shared<std::vector<size_type>>(adjacent_set.begin(), adjacent_set.end());
    return { ConstAdjacentVertexIterator(vec, vec->begin()),
            ConstAdjacentVertexIterator(vec, vec->end()) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ReverseAdjacentVertexIterator,
    typename DirectedGraph<T>::ReverseAdjacentVertexIterator>
    DirectedGraph<T>::routgoing_vertices(size_type vertex_id) {
    auto [begin, end] = outgoing_vertices(vertex_id);
    return { ReverseAdjacentVertexIterator(end), ReverseAdjacentVertexIterator(begin) };
}

template<typename T>
std::pair<typename DirectedGraph<T>::ReverseAdjacentVertexIterator,
    typename DirectedGraph<T>::ReverseAdjacentVertexIterator>
    DirectedGraph<T>::rincoming_vertices(size_type vertex_id) {
    auto [begin, end] = incoming_vertices(vertex_id);
    return { ReverseAdjacentVertexIterator(end), ReverseAdjacentVertexIterator(begin) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ReverseAdjacentVertexIterator,
    typename DirectedGraph<T>::ReverseAdjacentVertexIterator>
    DirectedGraph<T>::radjacent_vertices(size_type vertex_id) {
    auto [begin, end] = adjacent_vertices(vertex_id);
    return { ReverseAdjacentVertexIterator(end), ReverseAdjacentVertexIterator(begin) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ConstReverseAdjacentVertexIterator,
    typename DirectedGraph<T>::ConstReverseAdjacentVertexIterator>
    DirectedGraph<T>::croutgoing_vertices(size_type vertex_id) const {
    auto [begin, end] = outgoing_vertices(vertex_id);
    return { ConstReverseAdjacentVertexIterator(end), ConstReverseAdjacentVertexIterator(begin) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ConstReverseAdjacentVertexIterator,
    typename DirectedGraph<T>::ConstReverseAdjacentVertexIterator>
    DirectedGraph<T>::crincoming_vertices(size_type vertex_id) const {
    auto [begin, end] = incoming_vertices(vertex_id);
    return { ConstReverseAdjacentVertexIterator(end), ConstReverseAdjacentVertexIterator(begin) };
}
template<typename T>
std::pair<typename DirectedGraph<T>::ConstReverseAdjacentVertexIterator,
    typename DirectedGraph<T>::ConstReverseAdjacentVertexIterator>
    DirectedGraph<T>::cradjacent_vertices(size_type vertex_id) const {
    auto [begin, end] = adjacent_vertices(vertex_id);
    return { ConstReverseAdjacentVertexIterator(end), ConstReverseAdjacentVertexIterator(begin) };
}
template<typename T>
void DirectedGraph<T>::remove_vertex(VertexIterator it) {
    remove_vertex(it.get_index());
}
template<typename T>
void DirectedGraph<T>::remove_edge(EdgeIterator it) {
    const Edge& edge = *it;
    remove_edge(edge.from, edge.to);
}
template<typename T>
bool DirectedGraph<T>::operator==(const DirectedGraph& other) const {
    return vertices_ == other.vertices_ && edges_ == other.edges_;
}
template<typename T>
bool DirectedGraph<T>::operator!=(const DirectedGraph& other) const {
    return !(*this == other);
}
template<typename T>
bool DirectedGraph<T>::operator<(const DirectedGraph& other) const {
    if (vertices_.size() != other.vertices_.size()) {
        return vertices_.size() < other.vertices_.size();
    }
    if (edges_.size() != other.edges_.size()) {
        return edges_.size() < other.edges_.size();
    }
    return vertices_ < other.vertices_;
}
template<typename T>
bool DirectedGraph<T>::operator>(const DirectedGraph& other) const {
    return other < *this;
}
template<typename T>
bool DirectedGraph<T>::operator<=(const DirectedGraph& other) const {
    return !(other < *this);
}
template<typename T>
bool DirectedGraph<T>::operator>=(const DirectedGraph& other) const {
    return !(*this < other);
}
template<typename T>
void DirectedGraph<T>::rebuild_auxiliary_structures() {
    outgoing_.clear();
    incoming_.clear();

    for (const auto& edge : edges_) {
        outgoing_[edge.from].insert(edge.to);
        incoming_[edge.to].insert(edge.from);
    }
}

#endif
