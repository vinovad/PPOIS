#include "pch.h"

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <sstream>
#include "D:\Уник\ППОИС\4LABA\task2\task2\task2\directed_graph.h"
#include "D:\Уник\ППОИС\4LABA\task2\task2\task2\directed_graph.cpp"

TEST(DirectedGraph, EmptyAndAddVertices) {
    DirectedGraph<int> g;
    EXPECT_TRUE(g.empty());
    auto v0 = g.add_vertex(10);
    auto v1 = g.add_vertex(20);
    EXPECT_FALSE(g.empty());
    EXPECT_EQ(g.vertex_count(), 2u);
    EXPECT_EQ(v0, 0u);
    EXPECT_EQ(v1, 1u);
    EXPECT_EQ(g.get_vertex(0), 10);
    EXPECT_EQ(g.get_vertex(1), 20);
}

TEST(DirectedGraph, AddAndQueryEdges) {
    DirectedGraph<std::string> g;
    auto a = g.add_vertex("A");
    auto b = g.add_vertex("B");
    auto c = g.add_vertex("C");

    g.add_edge(a, b);
    g.add_edge(b, c);
    g.add_edge(a, c);

    EXPECT_EQ(g.edge_count(), 3u);
    EXPECT_TRUE(g.has_edge(a, b));
    EXPECT_TRUE(g.has_edge(b, c));
    EXPECT_TRUE(g.has_edge(a, c));
    EXPECT_FALSE(g.has_edge(c, a));

    EXPECT_EQ(g.out_degree(a), 2u);
    EXPECT_EQ(g.in_degree(a), 0u);
    EXPECT_EQ(g.vertex_degree(a), 2u);
    EXPECT_EQ(g.out_degree(b), 1u);
    EXPECT_EQ(g.in_degree(b), 1u);
    EXPECT_EQ(g.vertex_degree(b), 2u);
    EXPECT_EQ(g.out_degree(c), 0u);
    EXPECT_EQ(g.in_degree(c), 2u);
}

TEST(DirectedGraph, RemoveEdge) {
    DirectedGraph<int> g;
    auto v0 = g.add_vertex(1);
    auto v1 = g.add_vertex(2);
    g.add_edge(v0, v1);
    ASSERT_TRUE(g.has_edge(v0, v1));
    g.remove_edge(v0, v1);
    EXPECT_FALSE(g.has_edge(v0, v1));
    EXPECT_EQ(g.edge_count(), 0u);
}

TEST(DirectedGraph, RemoveVertexReindexesEdges) {
    DirectedGraph<int> g;
    auto v0 = g.add_vertex(1); // 0
    auto v1 = g.add_vertex(2); // 1
    auto v2 = g.add_vertex(3); // 2

    g.add_edge(v0, v1);
    g.add_edge(v1, v2);
    g.add_edge(v0, v2);
    ASSERT_EQ(g.edge_count(), 3u);

    // Удаляем среднюю вершину (1). Индексы >1 должны сдвинуться на -1
    g.remove_vertex(1);
    EXPECT_EQ(g.vertex_count(), 2u);

    // Рёбра, инцидентные 1, исчезают. Оставшееся ребро было (0->2) => (0->1)
    EXPECT_EQ(g.edge_count(), 1u);
    EXPECT_TRUE(g.has_edge(0, 1));

    // Проверим значения вершин после сдвига
    EXPECT_EQ(g.get_vertex(0), 1);
    EXPECT_EQ(g.get_vertex(1), 3);
}

TEST(DirectedGraph, VertexIterators) {
    DirectedGraph<char> g;
    g.add_vertex('a');
    g.add_vertex('b');
    g.add_vertex('c');

    // Прямой обход
    std::vector<std::pair<size_t, char>> forward;
    for (auto it = g.begin_vertices(); it != g.end_vertices(); ++it) {
        auto p = *it; // value copy (index, value)
        forward.push_back(p);
    }
    ASSERT_EQ(forward.size(), 3u);
    EXPECT_EQ(forward[0].first, 0u); EXPECT_EQ(forward[0].second, 'a');
    EXPECT_EQ(forward[1].first, 1u); EXPECT_EQ(forward[1].second, 'b');
    EXPECT_EQ(forward[2].first, 2u); EXPECT_EQ(forward[2].second, 'c');

    // Обратный обход
    std::vector<std::pair<size_t, char>> backward;
    for (auto it = g.rbegin_vertices(); it != g.rend_vertices(); ++it) {
        auto p = *it;
        backward.push_back(p);
    }
    ASSERT_EQ(backward.size(), 3u);
    EXPECT_EQ(backward[0].first, 2u); EXPECT_EQ(backward[0].second, 'c');
    EXPECT_EQ(backward[1].first, 1u); EXPECT_EQ(backward[1].second, 'b');
    EXPECT_EQ(backward[2].first, 0u); EXPECT_EQ(backward[2].second, 'a');
}

TEST(DirectedGraph, EdgeAndAdjacentIterators) {
    DirectedGraph<int> g;
    auto v0 = g.add_vertex(0);
    auto v1 = g.add_vertex(1);
    auto v2 = g.add_vertex(2);

    g.add_edge(v0, v1);
    g.add_edge(v0, v2);
    g.add_edge(v1, v2);

    // Глобальные рёбра
    std::vector<std::pair<size_t, size_t>> edges;
    for (auto it = g.begin_edges(); it != g.end_edges(); ++it) {
        const auto& e = *it;
        edges.emplace_back(e.from, e.to);
    }
    EXPECT_EQ(edges.size(), 3u);

    // Исходящие
    size_t out_cnt = 0;
    auto out = g.outgoing_edges(v0);
    for (auto it = out.first; it != out.second; ++it) {
        const auto& e = *it;
        EXPECT_EQ(e.from, v0);
        ++out_cnt;
    }
    EXPECT_EQ(out_cnt, 2u);

    // Смежные вершины
    auto adj = g.adjacent_vertices(v2);
    std::vector<size_t> adj_v;
    for (auto it = adj.first; it != adj.second; ++it) {
        adj_v.push_back(*it);
    }
    // Для v2 смежны те, кто соединён с ним: входящие (0,1)
    EXPECT_EQ(adj_v.size(), 2u);
    EXPECT_EQ(adj_v[0], 0u);
    EXPECT_EQ(adj_v[1], 1u);
}

TEST(DirectedGraph, ComparisonOperators) {
    DirectedGraph<int> a;
    DirectedGraph<int> b;

    a.add_vertex(1);
    b.add_vertex(1);
    EXPECT_TRUE(a == b);

    a.add_vertex(2);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b < a || a > b);
}

TEST(DirectedGraph, ExceptionsAndBounds) {
    DirectedGraph<int> g;
    // Нет вершин
    EXPECT_TRUE(g.empty());
    EXPECT_THROW(g.get_vertex(0), std::out_of_range);
    EXPECT_THROW(g.remove_vertex(0), std::out_of_range);
    // Добавим одну вершину
    auto v0 = g.add_vertex(42);
    EXPECT_NO_THROW(g.get_vertex(v0));
    // Ошибочные рёбра/степени/итераторы для несуществующей вершины
    EXPECT_THROW(g.add_edge(0, 5), std::out_of_range);
    EXPECT_THROW(g.add_edge(5, 0), std::out_of_range);
    EXPECT_THROW({ [[maybe_unused]] auto d = g.out_degree(5); }, std::out_of_range);
    EXPECT_THROW({ [[maybe_unused]] auto d = g.in_degree(5); }, std::out_of_range);
    EXPECT_THROW({ [[maybe_unused]] auto d = g.vertex_degree(5); }, std::out_of_range);
    EXPECT_THROW({ auto p = g.outgoing_edges(5); (void)p; }, std::out_of_range);
    EXPECT_THROW({ auto p = g.incoming_edges(5); (void)p; }, std::out_of_range);
    EXPECT_THROW({ auto p = g.incident_edges(5); (void)p; }, std::out_of_range);
    EXPECT_THROW({ auto p = g.outgoing_vertices(5); (void)p; }, std::out_of_range);
    EXPECT_THROW({ auto p = g.incoming_vertices(5); (void)p; }, std::out_of_range);
    EXPECT_THROW({ auto p = g.adjacent_vertices(5); (void)p; }, std::out_of_range);
    // edge_degree для несуществующего ребра
    EXPECT_THROW({ [[maybe_unused]] auto d = g.edge_degree(0, 0); }, std::out_of_range);
    // remove_edge для отсутствующего ребра
    EXPECT_THROW(g.remove_edge(0, 0), std::out_of_range);
}

TEST(DirectedGraph, DuplicateEdgesAndIdempotency) {
    DirectedGraph<int> g;
    auto a = g.add_vertex(1);
    auto b = g.add_vertex(2);
    g.add_edge(a, b);
    g.add_edge(a, b); // дубликат не должен увеличивать количество
    EXPECT_EQ(g.edge_count(), 1u);
    EXPECT_TRUE(g.has_edge(a, b));
}

TEST(DirectedGraph, RemoveByIterators) {
    DirectedGraph<int> g;
    auto a = g.add_vertex(10);
    auto b = g.add_vertex(20);
    auto c = g.add_vertex(30);
    g.add_edge(a, b);
    g.add_edge(b, c);
    ASSERT_EQ(g.edge_count(), 2u);

    // Удаление ребра по итератору
    auto eit = g.begin_edges();
    g.remove_edge(eit);
    EXPECT_EQ(g.edge_count(), 1u);

    // Удаление вершины по итератору
    auto vit = g.begin_vertices(); // указывает на вершину с индексом 0
    g.remove_vertex(vit);
    EXPECT_EQ(g.vertex_count(), 2u);
}

TEST(DirectedGraph, ConstAndReverseIterators) {
    DirectedGraph<int> g;
    auto a = g.add_vertex(1); // 0
    auto b = g.add_vertex(2); // 1
    auto c = g.add_vertex(3); // 2
    g.add_edge(a, b);
    g.add_edge(a, c);
    g.add_edge(b, c);

    const DirectedGraph<int>& cg = g;

    // Const edge итераторы
    size_t ec = 0;
    for (auto it = cg.cbegin_edges(); it != cg.cend_edges(); ++it) { ++ec; }
    EXPECT_EQ(ec, g.edge_count());

    // Reverse edges
    size_t rec = 0;
    for (auto it = g.rbegin_edges(); it != g.rend_edges(); ++it) { ++rec; }
    EXPECT_EQ(rec, g.edge_count());

    // Incident edges: исходящие/входящие/все + реверс + const
    auto out = g.outgoing_edges(a);
    size_t out_n = 0; for (auto it = out.first; it != out.second; ++it) { ++out_n; }
    EXPECT_EQ(out_n, 2u);

    auto in = g.incoming_edges(c);
    size_t in_n = 0; for (auto it = in.first; it != in.second; ++it) { ++in_n; }
    EXPECT_EQ(in_n, 2u);

    auto inc = g.incident_edges(b);
    size_t inc_n = 0; for (auto it = inc.first; it != inc.second; ++it) { ++inc_n; }
    EXPECT_EQ(inc_n, 2u);

    auto rout = g.routgoing_edges(a);
    size_t rout_n = 0; for (auto it = rout.first; it != rout.second; ++it) { ++rout_n; }
    EXPECT_EQ(rout_n, 2u);

    auto rin = g.rincoming_edges(c);
    size_t rin_n = 0; for (auto it = rin.first; it != rin.second; ++it) { ++rin_n; }
    EXPECT_EQ(rin_n, 2u);

    auto rinc = g.rincident_edges(b);
    size_t rinc_n = 0; for (auto it = rinc.first; it != rinc.second; ++it) { ++rinc_n; }
    EXPECT_EQ(rinc_n, 2u);

    // const-версии
    auto coutp = cg.outgoing_edges(a);
    size_t cout_n = 0; for (auto it = coutp.first; it != coutp.second; ++it) { ++cout_n; }
    EXPECT_EQ(cout_n, 2u);

    auto cinp = cg.incoming_edges(c);
    size_t cin_n = 0; for (auto it = cinp.first; it != cinp.second; ++it) { ++cin_n; }
    EXPECT_EQ(cin_n, 2u);

    auto cincp = cg.incident_edges(b);
    size_t cinc_n = 0; for (auto it = cincp.first; it != cincp.second; ++it) { ++cinc_n; }
    EXPECT_EQ(cinc_n, 2u);

    auto crout = cg.croutgoing_edges(a);
    size_t crout_n = 0; for (auto it = crout.first; it != crout.second; ++it) { ++crout_n; }
    EXPECT_EQ(crout_n, 2u);

    auto crin = cg.crincoming_edges(c);
    size_t crin_n = 0; for (auto it = crin.first; it != crin.second; ++it) { ++crin_n; }
    EXPECT_EQ(crin_n, 2u);

    auto crinc = cg.crincident_edges(b);
    size_t crinc_n = 0; for (auto it = crinc.first; it != crinc.second; ++it) { ++crinc_n; }
    EXPECT_EQ(crinc_n, 2u);
}

TEST(DirectedGraph, AdjacentVerticesVariants) {
    DirectedGraph<int> g;
    auto a = g.add_vertex(1); // 0
    auto b = g.add_vertex(2); // 1
    auto c = g.add_vertex(3); // 2
    g.add_edge(a, b);
    g.add_edge(b, c);
    g.add_edge(c, a);

    // Стандартные
    auto ov = g.outgoing_vertices(a);
    std::vector<size_t> ovv; for (auto it = ov.first; it != ov.second; ++it) ovv.push_back(*it);
    ASSERT_EQ(ovv.size(), 1u); EXPECT_EQ(ovv[0], (size_t)b);

    auto iv = g.incoming_vertices(a);
    std::vector<size_t> ivv; for (auto it = iv.first; it != iv.second; ++it) ivv.push_back(*it);
    ASSERT_EQ(ivv.size(), 1u); EXPECT_EQ(ivv[0], (size_t)c);

    auto av = g.adjacent_vertices(a);
    std::vector<size_t> avv; for (auto it = av.first; it != av.second; ++it) avv.push_back(*it);
    EXPECT_EQ(avv.size(), 2u);

    // Реверс
    auto rov = g.routgoing_vertices(a);
    size_t rov_n = 0; for (auto it = rov.first; it != rov.second; ++it) ++rov_n;
    EXPECT_EQ(rov_n, 1u);

    auto riv = g.rincoming_vertices(a);
    size_t riv_n = 0; for (auto it = riv.first; it != riv.second; ++it) ++riv_n;
    EXPECT_EQ(riv_n, 1u);

    auto rav = g.radjacent_vertices(a);
    size_t rav_n = 0; for (auto it = rav.first; it != rav.second; ++it) ++rav_n;
    EXPECT_EQ(rav_n, 2u);

    // const-версии
    const DirectedGraph<int>& cg = g;
    auto cov = cg.outgoing_vertices(a);
    size_t cov_n = 0; for (auto it = cov.first; it != cov.second; ++it) ++cov_n;
    EXPECT_EQ(cov_n, 1u);

    auto civ = cg.incoming_vertices(a);
    size_t civ_n = 0; for (auto it = civ.first; it != civ.second; ++it) ++civ_n;
    EXPECT_EQ(civ_n, 1u);

    auto cav = cg.adjacent_vertices(a);
    size_t cav_n = 0; for (auto it = cav.first; it != cav.second; ++it) ++cav_n;
    EXPECT_EQ(cav_n, 2u);

    auto crOv = cg.croutgoing_vertices(a);
    size_t crOv_n = 0; for (auto it = crOv.first; it != crOv.second; ++it) ++crOv_n;
    EXPECT_EQ(crOv_n, 1u);

    auto crIv = cg.crincoming_vertices(a);
    size_t crIv_n = 0; for (auto it = crIv.first; it != crIv.second; ++it) ++crIv_n;
    EXPECT_EQ(crIv_n, 1u);

    auto crAv = cg.cradjacent_vertices(a);
    size_t crAv_n = 0; for (auto it = crAv.first; it != crAv.second; ++it) ++crAv_n;
    EXPECT_EQ(crAv_n, 2u);
}

TEST(DirectedGraph, CopyAssignClearAndPrint) {
    DirectedGraph<std::string> g;
    auto a = g.add_vertex("A");
    auto b = g.add_vertex("B");
    g.add_edge(a, b);

    // Копирование/присваивание
    DirectedGraph<std::string> g2(g); // copy-ctor
    EXPECT_TRUE(g2 == g);

    DirectedGraph<std::string> g3;
    g3 = g; // operator=
    EXPECT_TRUE(g3 == g);

    // Self-assignment (намеренный тест)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wself-assign-overloaded"
    g3 = g3;
#pragma GCC diagnostic pop
    EXPECT_TRUE(g3 == g);

    // edge_degree для существующего ребра
    EXPECT_EQ(g.edge_degree(a, b), g.vertex_degree(a) + g.vertex_degree(b));

    // Оператор вывода
    std::ostringstream oss;
    oss << g;
    auto s = oss.str();
    EXPECT_NE(s.find("DirectedGraph with 2 vertices and 1 edges"), std::string::npos);
    EXPECT_NE(s.find("[0: A]"), std::string::npos);
    EXPECT_NE(s.find("[1: B]"), std::string::npos);
    EXPECT_NE(s.find("(0->1)"), std::string::npos);

    // clear
    g.clear();
    EXPECT_TRUE(g.empty());
    EXPECT_EQ(g.vertex_count(), 0u);
    EXPECT_EQ(g.edge_count(), 0u);
}

// Дополнительные тесты для увеличения покрытия

TEST(DirectedGraph, AllComparisonOperators) {
    DirectedGraph<int> g1, g2, g3;

    g1.add_vertex(1);
    g1.add_vertex(2);

    g2.add_vertex(1);
    g2.add_vertex(2);

    g3.add_vertex(1);
    g3.add_vertex(3);

    // ==, !=
    EXPECT_TRUE(g1 == g2);
    EXPECT_FALSE(g1 != g2);
    EXPECT_TRUE(g1 != g3);
    EXPECT_FALSE(g1 == g3);

    // <, >, <=, >=
    EXPECT_TRUE(g1 < g3 || g3 < g1);
    if (g1 < g3) {
        EXPECT_TRUE(g3 > g1);
        EXPECT_TRUE(g1 <= g3);
        EXPECT_TRUE(g3 >= g1);
        EXPECT_FALSE(g1 > g3);
        EXPECT_FALSE(g3 < g1);
    }
    else {
        EXPECT_TRUE(g1 > g3);
        EXPECT_TRUE(g3 < g1);
        EXPECT_TRUE(g3 <= g1);
        EXPECT_TRUE(g1 >= g3);
        EXPECT_FALSE(g3 > g1);
        EXPECT_FALSE(g1 < g3);
    }

    // <= и >= с равными
    EXPECT_TRUE(g1 <= g2);
    EXPECT_TRUE(g1 >= g2);
    EXPECT_TRUE(g2 <= g1);
    EXPECT_TRUE(g2 >= g1);
}

TEST(DirectedGraph, VertexIteratorOperations) {
    DirectedGraph<int> g;
    g.add_vertex(10);
    g.add_vertex(20);
    g.add_vertex(30);

    auto it = g.begin_vertices();

    // Проверяем get_index
    EXPECT_EQ(it.get_index(), 0u);

    // Префиксный инкремент
    ++it;
    EXPECT_EQ(it.get_index(), 1u);
    EXPECT_EQ((*it).second, 20);

    // Постфиксный инкремент
    auto it2 = it++;
    EXPECT_EQ(it2.get_index(), 1u);
    EXPECT_EQ(it.get_index(), 2u);

    // Префиксный декремент
    --it;
    EXPECT_EQ(it.get_index(), 1u);

    // Постфиксный декремент
    auto it3 = it--;
    EXPECT_EQ(it3.get_index(), 1u);
    EXPECT_EQ(it.get_index(), 0u);

    // Оператор !=
    auto end = g.end_vertices();
    EXPECT_TRUE(it != end);

    // Const итераторы
    const DirectedGraph<int>& cg = g;
    auto cit = cg.cbegin_vertices();
    EXPECT_EQ(cit.get_index(), 0u);

    ++cit;
    EXPECT_EQ(cit.get_index(), 1u);

    auto cit2 = cit++;
    EXPECT_EQ(cit2.get_index(), 1u);
    EXPECT_EQ(cit.get_index(), 2u);

    --cit;
    EXPECT_EQ(cit.get_index(), 1u);

    auto cit3 = cit--;
    EXPECT_EQ(cit3.get_index(), 1u);
    EXPECT_EQ(cit.get_index(), 0u);
}

TEST(DirectedGraph, ConstReverseVertexIterators) {
    DirectedGraph<char> g;
    g.add_vertex('x');
    g.add_vertex('y');
    g.add_vertex('z');

    const DirectedGraph<char>& cg = g;

    // crbegin/crend
    std::vector<char> chars;
    for (auto it = cg.crbegin_vertices(); it != cg.crend_vertices(); ++it) {
        chars.push_back((*it).second);
    }

    ASSERT_EQ(chars.size(), 3u);
    EXPECT_EQ(chars[0], 'z');
    EXPECT_EQ(chars[1], 'y');
    EXPECT_EQ(chars[2], 'x');
}

TEST(DirectedGraph, EdgeIteratorPostfixOperators) {
    DirectedGraph<int> g;
    auto a = g.add_vertex(1);
    auto b = g.add_vertex(2);
    auto c = g.add_vertex(3);

    g.add_edge(a, b);
    g.add_edge(b, c);
    g.add_edge(a, c);

    auto it = g.begin_edges();

    // Постфиксный инкремент
    auto it2 = it++;
    EXPECT_TRUE(it2 != it);

    // Оператор ->
    EXPECT_TRUE(it->from < 3);
    EXPECT_TRUE(it->to <= 3);

    // Префиксный декремент
    --it;

    // Постфиксный декремент
    auto it3 = it--;
    EXPECT_TRUE(it3 != it);

    // Const версия
    const DirectedGraph<int>& cg = g;
    auto cit = cg.cbegin_edges();
    auto cit2 = cit++;
    EXPECT_TRUE(cit2 != cit);

    EXPECT_TRUE(cit->from < 3);

    --cit;
    auto cit3 = cit--;
    EXPECT_TRUE(cit3 != cit);
}

TEST(DirectedGraph, MoreEdgeCases) {
    DirectedGraph<double> g;

    // Граф с одной вершиной без ребер
    auto v0 = g.add_vertex(3.14);
    EXPECT_EQ(g.out_degree(v0), 0u);
    EXPECT_EQ(g.in_degree(v0), 0u);
    EXPECT_EQ(g.vertex_degree(v0), 0u);

    // Добавляем петлю (самоссылка)
    g.add_edge(v0, v0);
    EXPECT_TRUE(g.has_edge(v0, v0));
    EXPECT_EQ(g.out_degree(v0), 1u);
    EXPECT_EQ(g.in_degree(v0), 1u);

    // Удаляем петлю
    g.remove_edge(v0, v0);
    EXPECT_FALSE(g.has_edge(v0, v0));
    EXPECT_EQ(g.edge_count(), 0u);
}

TEST(DirectedGraph, LargeGraph) {
    DirectedGraph<int> g;

    // Создаем граф с 100 вершинами
    for (int i = 0; i < 100; ++i) {
        g.add_vertex(i);
    }

    EXPECT_EQ(g.vertex_count(), 100u);

    // Добавляем рёбра: каждая вершина соединена со следующей
    for (size_t i = 0; i < 99; ++i) {
        g.add_edge(i, i + 1);
    }

    EXPECT_EQ(g.edge_count(), 99u);
    EXPECT_EQ(g.out_degree(0), 1u);
    EXPECT_EQ(g.in_degree(99), 1u);

    // Удаляем среднюю вершину
    g.remove_vertex(50);
    EXPECT_EQ(g.vertex_count(), 99u);
    // Рёбра инцидентные вершине 50 должны быть удалены
    EXPECT_EQ(g.edge_count(), 97u); // 99 - 2 (ребра 49->50 и 50->51)
}



TEST(DirectedGraph, VertexRemovalEdgeCases) {
    DirectedGraph<int> g;
    auto v0 = g.add_vertex(0);
    auto v1 = g.add_vertex(1);
    auto v2 = g.add_vertex(2);
    auto v3 = g.add_vertex(3);

    g.add_edge(v0, v1);
    g.add_edge(v1, v2);
    g.add_edge(v2, v3);
    g.add_edge(v0, v3);

    EXPECT_EQ(g.edge_count(), 4u);

    // Удаляем первую вершину
    g.remove_vertex(v0);
    EXPECT_EQ(g.vertex_count(), 3u);
    EXPECT_EQ(g.edge_count(), 2u); // Остались только 0->1 и 1->2 (после сдвига индексов)

    // Проверяем что индексы сдвинулись правильно
    EXPECT_EQ(g.get_vertex(0), 1); // бывшая v1
    EXPECT_EQ(g.get_vertex(1), 2); // бывшая v2
    EXPECT_EQ(g.get_vertex(2), 3); // бывшая v3
}

TEST(DirectedGraph, EmptyGraphIterators) {
    DirectedGraph<int> g;

    // Итераторы пустого графа
    EXPECT_TRUE(g.begin_vertices() == g.end_vertices());
    EXPECT_TRUE(g.begin_edges() == g.end_edges());
    EXPECT_TRUE(g.cbegin_vertices() == g.cend_vertices());
    EXPECT_TRUE(g.cbegin_edges() == g.cend_edges());
    EXPECT_TRUE(g.rbegin_vertices() == g.rend_vertices());
    EXPECT_TRUE(g.rbegin_edges() == g.rend_edges());
}

TEST(DirectedGraph, ConstGraphOperations) {
    DirectedGraph<int> g;
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_edge(0, 1);
    g.add_edge(1, 2);

    const DirectedGraph<int>& cg = g;

    // Все const методы
    EXPECT_FALSE(cg.empty());
    EXPECT_TRUE(cg.has_vertex(0));
    EXPECT_EQ(cg.vertex_count(), 3u);
    EXPECT_EQ(cg.get_vertex(0), 1);
    EXPECT_TRUE(cg.has_edge(0, 1));
    EXPECT_EQ(cg.edge_count(), 2u);
    EXPECT_EQ(cg.out_degree(0), 1u);
    EXPECT_EQ(cg.in_degree(2), 1u);
    EXPECT_EQ(cg.vertex_degree(1), 2u);
    EXPECT_EQ(cg.edge_degree(0, 1), 3u); // 1 + 2

    // Const итераторы уже проверены выше, но добавим еще
    auto vit = cg.begin_vertices();
    EXPECT_TRUE(vit != cg.end_vertices());

    auto eit = cg.begin_edges();
    EXPECT_TRUE(eit != cg.end_edges());
}

