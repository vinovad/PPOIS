#pragma once

#include <vector>
#include <string>
#include <type_traits>
#include <iterator>
#include <memory>
#include <utility>
#include <algorithm>

namespace sortlib {

    template <class T, class Compare = std::less<>>
    class BinarySearchTree {
        struct Node {
            T value;
            std::size_t count{ 1 };
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;

            explicit Node(const T& v) : value(v) {}
            explicit Node(T&& v) : value(std::move(v)) {}
        };

        std::unique_ptr<Node> root_{};
        Compare comp_{};

        void insert_impl(std::unique_ptr<Node>& node, const T& val) {
            if (!node) {
                node = std::make_unique<Node>(val);
                return;
            }
            if (comp_(val, node->value)) {
                insert_impl(node->left, val);
            }
            else if (comp_(node->value, val)) {
                insert_impl(node->right, val);
            }
            else {
                ++node->count;
            }
        }

        template <class OutputIt>
        OutputIt inorder_impl(const std::unique_ptr<Node>& node, OutputIt out) const {
            if (!node) return out;
            out = inorder_impl(node->left, out);
            for (std::size_t i = 0; i < node->count; ++i) {
                *out++ = node->value;
            }
            return inorder_impl(node->right, out);
        }

    public:
        BinarySearchTree() = default;
        explicit BinarySearchTree(Compare comp) : comp_(std::move(comp)) {}

        void insert(const T& val) {
            insert_impl(root_, val);
        }

        template <class OutputIt>
        void inorder(OutputIt out) const {
            (void)inorder_impl(root_, out);
        }
    };
    template <class RandomIt, class Compare = std::less<>>
    void binary_tree_sort(RandomIt first, RandomIt last, Compare comp = {}) {
        using T = typename std::iterator_traits<RandomIt>::value_type;
        using Cat = typename std::iterator_traits<RandomIt>::iterator_category;
        static_assert(std::is_base_of_v<std::random_access_iterator_tag, Cat>,
            "binary_tree_sort òðåáóåò èòåðàòîðû ïðîèçâîëüíîãî äîñòóïà");

        BinarySearchTree<T, Compare> bst(std::move(comp));
        for (auto it = first; it != last; ++it) {
            bst.insert(*it);
        }
        bst.inorder(first);
    }

    template <class Container, class Compare = std::less<>>
    void binary_tree_sort(Container& c, Compare comp = {}) {
        binary_tree_sort(std::begin(c), std::end(c), std::move(comp));
    }

    // Ïåðåãðóçêà äëÿ C-ìàññèâà
    template <class T, std::size_t N, class Compare = std::less<>>
    void binary_tree_sort(T(&arr)[N], Compare comp = Compare()) {
        binary_tree_sort(arr, arr + N, std::move(comp));
    }

} 
