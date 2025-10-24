#pragma once
#include <iterator>  
#include <type_traits>
#include <memory> 
#include <vector>
#include <string>
#include <cstring>

namespace sortlib {

      // ================================
      // Сортировка бинарным деревом (BST)
      // ================================
    
      // Сортировка через бинарное дерево (по итераторам)
    template <class RandomIt, class Compare = std::less<>>
    void binary_tree_sort(RandomIt first, RandomIt last, Compare comp = Compare{}) {
        using T = typename std::iterator_traits<RandomIt>::value_type;
        using Category = typename std::iterator_traits<RandomIt>::iterator_category;
        static_assert(std::is_base_of_v<std::random_access_iterator_tag, Category>,
            "binary_tree_sort требует итераторы произвольного доступа (array/vector)");

        struct Node {
            T value;
            std::size_t count{ 1 };
            std::unique_ptr<Node> left;
            std::unique_ptr<Node> right;
            explicit Node(const T& v) : value(v) {}
            explicit Node(T&& v) : value(std::move(v)) {}
        };

        std::unique_ptr<Node> root;

        auto insert_val = [&](auto&& self, std::unique_ptr<Node>& node, const T& val) -> void {
            if (!node) {
                node = std::make_unique<Node>(val);
                return;
            }
            if (comp(val, node->value)) {
                self(self, node->left, val);
            }
            else if (comp(node->value, val)) {
                self(self, node->right, val);
            }
            else {
                ++node->count; // дубликат значения
            }
            };

        for (auto it = first; it != last; ++it) {
            insert_val(insert_val, root, *it);
        }

        auto out = first;
        auto inorder = [&](auto&& self, const std::unique_ptr<Node>& node) -> void {
            if (!node) return;
            self(self, node->left);
            for (std::size_t i = 0; i < node->count; ++i) {
                *out++ = node->value;
            }
            self(self, node->right);
            };

        inorder(inorder, root);
    }

    // Перегрузка для контейнера
    template <class Container, class Compare = std::less<>>
    void binary_tree_sort(Container& c, Compare comp = Compare{}) {
        binary_tree_sort(std::begin(c), std::end(c), comp);
    }

    // Перегрузка для C-массива
    template <class T, std::size_t N, class Compare = std::less<>>
    void binary_tree_sort(T(&arr)[N], Compare comp = Compare{}) {
        binary_tree_sort(arr, arr + N, comp);
    }

    // ================================
    // MSD поразрядная сортировка (целые)
    // ================================

    template <class T>
    using make_unsigned_t = std::make_unsigned_t<std::remove_cv_t<T>>;

    // Преобразователь ключа для беззнаковых целых
    template <class T>
    struct IntegralKeyerUnsigned {
        using U = make_unsigned_t<T>;
        constexpr U operator()(const T& v) const noexcept { return static_cast<U>(v); }
    };

    // Преобразователь ключа для знаковых целых (смещение знака в старший бит)
    template <class T>
    struct IntegralKeyerSigned {
        using U = make_unsigned_t<T>;
        static constexpr int BITS = static_cast<int>(sizeof(U) * 8);
        static constexpr U SIGN = U(1) << (BITS - 1);
        constexpr U operator()(const T& v) const noexcept { return static_cast<U>(v) ^ SIGN; }
    };

    // Ядро MSD для целых типов с пользовательским извлечением ключа (в беззнаковом представлении)
    template <class RandomIt, class Keyer>
    void msd_radix_sort_integral_impl(RandomIt first, RandomIt last, int byteIndex,
        std::vector<typename std::iterator_traits<RandomIt>::value_type>& buffer,
        const Keyer& keyer) {
        using T = typename std::iterator_traits<RandomIt>::value_type;
        using U = make_unsigned_t<T>;
        auto n = static_cast<std::size_t>(last - first);
        if (n <= 1 || byteIndex < 0) return;

        constexpr std::size_t K = 256; // алфавит = 1 байт
        std::size_t count[K]{};

        // Подсчёт частот
        for (auto it = first; it != last; ++it) {
            U key = keyer(*it);
            auto d = static_cast<unsigned char>((key >> (byteIndex * 8)) & 0xFFu);
            ++count[d];
        }

        // Префиксные суммы -> стартовые индексы бакетов
        std::size_t start[K];
        start[0] = 0;
        for (std::size_t i = 1; i < K; ++i) start[i] = start[i - 1] + count[i - 1];

        // Текущие позиции для распределения
        std::size_t pos[K];
        std::memcpy(pos, start, sizeof(start));

        // Распределение по буферу
        for (auto it = first; it != last; ++it) {
            U key = keyer(*it);
            auto d = static_cast<unsigned char>((key >> (byteIndex * 8)) & 0xFFu);
            buffer[pos[d]++] = std::move(*it);
        }

        // Копир-е обратно
        std::move(buffer.begin(), buffer.begin() + n, first);

        // Рекурсия для каждого бакета на следующий байт
        for (std::size_t i = 0; i < K; ++i) {
            std::size_t sz = count[i];
            if (sz > 1 && byteIndex > 0) {
                auto subFirst = first + start[i];
                auto subLast = subFirst + sz;
                msd_radix_sort_integral_impl(subFirst, subLast, byteIndex - 1, buffer, keyer);
            }
        }
    }

    //  перегрузка по итераторам для целочисленных типов
    template <class RandomIt>
    std::enable_if_t<std::is_integral_v<typename std::iterator_traits<RandomIt>::value_type>, void>
        msd_radix_sort(RandomIt first, RandomIt last) {
        using T = typename std::iterator_traits<RandomIt>::value_type;
        using U = make_unsigned_t<T>;

        std::vector<T> buffer(static_cast<std::size_t>(last - first));
        if constexpr (std::is_signed_v<T>) {
            msd_radix_sort_integral_impl(first, last, static_cast<int>(sizeof(U)) - 1, buffer, IntegralKeyerSigned<T>{});
        }
        else {
            msd_radix_sort_integral_impl(first, last, static_cast<int>(sizeof(U)) - 1, buffer, IntegralKeyerUnsigned<T>{});
        }
    }

    // Перегрузка для контейнера (целые)
    template <class Container>
    std::enable_if_t<std::is_integral_v<typename Container::value_type>, void>
        msd_radix_sort(Container& c) {
        msd_radix_sort(std::begin(c), std::end(c));
    }

    // Перегрузка для C-массива (целые)
    template <class T, std::size_t N>
    std::enable_if_t<std::is_integral_v<T>, void>
        msd_radix_sort(T(&arr)[N]) {
        msd_radix_sort(arr, arr + N);
    }

    // ================================
    // MSD поразрядная сортировка (строки)
    // ================================

    template <class T>
    struct is_basic_string : std::false_type {};

    template <class CharT, class Traits, class Alloc>
    struct is_basic_string<std::basic_string<CharT, Traits, Alloc>> : std::true_type {};

    // Вспомогательная: возвращает 0..256, где 0 — конец строки, 1..256 — байты +1
    inline int char_at_unsigned(const std::string& s, std::size_t d) {
        if (d >= s.size()) return 0;
        auto c = static_cast<unsigned char>(s[d]);
        return static_cast<int>(c) + 1;
    }

    // перегрузка по итераторам для std::string (char)
    template <class RandomIt>
    std::enable_if_t<is_basic_string<typename std::iterator_traits<RandomIt>::value_type>::value&&
        std::is_same_v<typename std::iterator_traits<RandomIt>::value_type::value_type, char>, void>
        msd_radix_sort(RandomIt first, RandomIt last) {
        using S = typename std::iterator_traits<RandomIt>::value_type;
        auto n = static_cast<std::size_t>(last - first);
        if (n <= 1) return;

        constexpr int R = 256; // мощность алфавита байтов

        std::vector<S> buffer(n);

        // Рекурсивная лямбда для MSD по разряду d
        auto sort_rec = [&](auto&& self, RandomIt lo, RandomIt hi, std::size_t d) -> void {
            auto m = static_cast<std::size_t>(hi - lo);
            if (m <= 1) return;

            std::vector<std::size_t> count(R + 2, 0);
            // Подсчёт частот символов
            for (auto it = lo; it != hi; ++it) {
                int c = char_at_unsigned(*it, d); // 0..R
                ++count[c + 1];
            }
            // Преобразование к индексам (префиксные суммы)
            for (int r = 0; r <= R; ++r) count[r + 1] += count[r];

            // Копия стартовых позиций для рекурсии по бакетам
            std::vector<std::size_t> starts = count;

            // Распределение по буферу
            for (auto it = lo; it != hi; ++it) {
                int c = char_at_unsigned(*it, d);
                buffer[count[c]++] = std::move(*it);
            }
            // Копирование обратно
            std::move(buffer.begin(), buffer.begin() + m, lo);

            // Рекурсия для непустых бакетов, кроме c==0 (конец строки)
            for (int r = 1; r <= R; ++r) {
                std::size_t begin = starts[r];
                std::size_t end = starts[r + 1];
                if (end > begin + 1) {
                    self(self, lo + begin, lo + end, d + 1);
                }
            }
            };

        sort_rec(sort_rec, first, last, 0);
    }

    // Перегрузка для контейнера (строки)
    template <class Container>
    std::enable_if_t<is_basic_string<typename Container::value_type>::value&&
        std::is_same_v<typename Container::value_type::value_type, char>, void>
        msd_radix_sort(Container& c) {
        msd_radix_sort(std::begin(c), std::end(c));
    }

    // Перегрузка для C-массива (строки)
    template <std::size_t N>
    void msd_radix_sort(std::string(&arr)[N]) {
        msd_radix_sort(arr, arr + N);
    }

}