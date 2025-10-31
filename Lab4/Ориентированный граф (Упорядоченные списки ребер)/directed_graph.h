#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <map>
#include <set>
#include <memory>
#include <iterator>

// Øàáëîí îğèåíòèğîâàííîãî ãğàôà ñ èñïîëüçîâàíèåì óïîğÿäî÷åííûõ ñïèñêîâ ğåáåğ
template<typename T>
class DirectedGraph {
public:
    // ==================== TYPEDEF'Û ====================
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;

    // Ñòğóêòóğà äëÿ ïğåäñòàâëåíèÿ ğåáğà
    class Edge {
    public:
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
    std::vector<T> vertices_;  // Âåğøèíû ãğàôà
    std::set<Edge> edges_;     // Óïîğÿäî÷åííîå ìíîæåñòâî ğåáåğ

    // Âñïîìîãàòåëüíûå ñòğóêòóğû äëÿ áûñòğîãî äîñòóïà
    std::map<size_type, std::set<size_type>> outgoing_;  // Èñõîäÿùèå ğåáğà
    std::map<size_type, std::set<size_type>> incoming_;  // Âõîäÿùèå ğåáğà

    void rebuild_auxiliary_structures();

public:
    // ==================== ÊÎÍÑÒĞÓÊÒÎĞÛ È ÄÅÑÒĞÓÊÒÎĞ ====================
    DirectedGraph();
    DirectedGraph(const DirectedGraph& other);
    ~DirectedGraph();
    DirectedGraph& operator=(const DirectedGraph& other);

    // ==================== ÁÀÇÎÂÛÅ ÌÅÒÎÄÛ ====================
    [[nodiscard]] bool empty() const;
    void clear();

    // ==================== ÌÅÒÎÄÛ ÄËß ĞÀÁÎÒÛ Ñ ÂÅĞØÈÍÀÌÈ ====================
    size_type add_vertex(const_reference value);
    [[nodiscard]] bool has_vertex(size_type vertex_id) const;
    [[nodiscard]] size_type vertex_count() const;
    reference get_vertex(size_type vertex_id);
    const_reference get_vertex(size_type vertex_id) const;
    void remove_vertex(size_type vertex_id);

    // ==================== ÌÅÒÎÄÛ ÄËß ĞÀÁÎÒÛ Ñ ĞÅÁĞÀÌÈ ====================
    void add_edge(size_type from, size_type to);
    [[nodiscard]] bool has_edge(size_type from, size_type to) const;
    [[nodiscard]] size_type edge_count() const;
    void remove_edge(size_type from, size_type to);

    // ==================== ÑÒÅÏÅÍÈ ====================
    [[nodiscard]] size_type out_degree(size_type vertex_id) const;
    [[nodiscard]] size_type in_degree(size_type vertex_id) const;
    [[nodiscard]] size_type vertex_degree(size_type vertex_id) const;
    [[nodiscard]] size_type edge_degree(size_type from, size_type to) const;

    // ==================== ÈÒÅĞÀÒÎĞÛ ÄËß ÂÅĞØÈÍ ====================

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

        // added default ctor
        VertexIterator() : it_(), index_(0) {}
        VertexIterator(typename std::vector<T>::iterator it, size_type idx);
        reference operator*() const;
        VertexIterator& operator++();
        VertexIterator operator++(int);
        VertexIterator& operator--();
        VertexIterator operator--(int);
        bool operator==(const VertexIterator& other) const;
        bool operator!=(const VertexIterator& other) const;
        [[nodiscard]] size_type get_index() const;
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

        // added default ctor
        ConstVertexIterator() : it_(), index_(0) {}
        ConstVertexIterator(typename std::vector<T>::const_iterator it, size_type idx);
        reference operator*() const;
        ConstVertexIterator& operator++();
        ConstVertexIterator operator++(int);
        ConstVertexIterator& operator--();
        ConstVertexIterator operator--(int);
        bool operator==(const ConstVertexIterator& other) const;
        bool operator!=(const ConstVertexIterator& other) const;
        [[nodiscard]] size_type get_index() const;
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

    // ==================== ÈÒÅĞÀÒÎĞÛ ÄËß ĞÅÁÅĞ ====================

    class EdgeIterator {
    private:
        typename std::set<Edge>::iterator it_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = Edge;
        using difference_type = std::ptrdiff_t;
        using pointer = const Edge*;
        using reference = const Edge&;

        // added default ctor
        EdgeIterator() : it_() {}
        explicit EdgeIterator(typename std::set<Edge>::iterator it);
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

        // added default ctor
        ConstEdgeIterator() : it_() {}
        explicit ConstEdgeIterator(typename std::set<Edge>::const_iterator it);
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

    // ==================== ÈÒÅĞÀÒÎĞÛ ÄËß ÈÍÖÈÄÅÍÒÍÛÕ ĞÅÁÅĞ ====================

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

        // added default ctor
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

        // added default ctor
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

    // ==================== ÈÒÅĞÀÒÎĞÛ ÄËß ÑÌÅÆÍÛÕ ÂÅĞØÈÍ ====================

    class AdjacentVertexIterator {
    private:
        std::shared_ptr<std::vector<size_type>> vertices_;
        std::vector<size_type>::iterator it_;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = size_type;
        using difference_type = std::ptrdiff_t;
        using pointer = const size_type*;
        using reference = const size_type&;

        // added default ctor
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

        // added default ctor
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

    // ==================== ÓÄÀËÅÍÈÅ ÏÎ ÈÒÅĞÀÒÎĞÀÌ ====================
    void remove_vertex(VertexIterator it);
    void remove_edge(EdgeIterator it);

    // ==================== ÎÏÅĞÀÒÎĞÛ ÑĞÀÂÍÅÍÈß ====================
    bool operator==(const DirectedGraph& other) const;
    bool operator!=(const DirectedGraph& other) const;
    bool operator<(const DirectedGraph& other) const;
    bool operator>(const DirectedGraph& other) const;
    bool operator<=(const DirectedGraph& other) const;
    bool operator>=(const DirectedGraph& other) const;

    // ==================== ÎÏÅĞÀÒÎĞ ÂÛÂÎÄÀ ====================
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


#endif // DIRECTED_GRAPH_H
