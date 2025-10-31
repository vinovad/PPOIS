#pragma once

#include <vector>
#include <string>
#include <type_traits>
#include <iterator>
#include <memory>
#include <cstring>
#include <algorithm>

namespace sortlib {

    
    inline int char_at_unsigned(const std::string& s, std::size_t d) {
        if (d >= s.size()) return 0;
        auto c = static_cast<unsigned char>(s[d]);
        return static_cast<int>(c) + 1;
    }

    
    template <class T>
    using make_unsigned_t = typename std::make_unsigned<typename std::remove_cv<T>::type>::type;

   
    template <class T>
    class IntegralKeyerUnsigned {
    public:
        using U = make_unsigned_t<T>;
        constexpr U operator()(const T& v) const noexcept { return static_cast<U>(v); }
    };

    template <class T>
    class IntegralKeyerSigned {
    public:
        using U = make_unsigned_t<T>;
        static constexpr int BITS = static_cast<int>(sizeof(U) * 8);
        static constexpr U SIGN = U(1) << (BITS - 1);
        constexpr U operator()(const T& v) const noexcept { return static_cast<U>(v) ^ SIGN; }
    };

    template <class T>
    struct is_basic_string : std::false_type {};

    template <class CharT, class Traits, class Alloc>
    struct is_basic_string<std::basic_string<CharT, Traits, Alloc>> : std::true_type {};

    // ядро MSD дл€ целых
    template <class RandomIt, class Keyer>
    void msd_radix_sort_integral_impl(RandomIt first, RandomIt last, int byteIndex,
        std::vector<typename std::iterator_traits<RandomIt>::value_type>& buffer,
        const Keyer& keyer) {
        using T = typename std::iterator_traits<RandomIt>::value_type;
        using U = make_unsigned_t<T>;
        auto n = static_cast<std::size_t>(last - first);
        if (n <= 1 || byteIndex < 0) return;

        constexpr std::size_t K = 256;
        std::size_t count[K]{};

        for (auto it = first; it != last; ++it) {
            U key = keyer(*it);
            auto d = static_cast<unsigned char>((key >> (byteIndex * 8)) & 0xFFu);
            ++count[d];
        }

        std::size_t start[K];
        start[0] = 0;
        for (std::size_t i = 1; i < K; ++i) {
            start[i] = start[i - 1] + count[i - 1];
        }

        std::size_t pos[K];
        std::memcpy(pos, start, sizeof(start));

        for (auto it = first; it != last; ++it) {
            U key = keyer(*it);
            auto d = static_cast<unsigned char>((key >> (byteIndex * 8)) & 0xFFu);
            buffer[pos[d]++] = std::move(*it);
        }

        std::move(buffer.begin(), buffer.begin() + n, first);

        for (std::size_t i = 0; i < K; ++i) {
            std::size_t sz = count[i];
            if (sz > 1 && byteIndex > 0) {
                auto subFirst = first + start[i];
                auto subLast = subFirst + sz;
                msd_radix_sort_integral_impl(subFirst, subLast, byteIndex - 1, buffer, keyer);
            }
        }
    }

    // ѕубличный API: целые числа
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

    template <class Container>
    std::enable_if_t<std::is_integral_v<typename Container::value_type>, void>
        msd_radix_sort(Container& c) {
        msd_radix_sort(std::begin(c), std::end(c));
    }

    template <class T, std::size_t N>
    std::enable_if_t<std::is_integral_v<T>, void>
        msd_radix_sort(T (&arr)[N]) {
        msd_radix_sort(arr, arr + N);
    }

    // ѕубличный API: строки (только std::string с char)
    template <class RandomIt>
    std::enable_if_t<is_basic_string<typename std::iterator_traits<RandomIt>::value_type>::value&&
        std::is_same_v<typename std::iterator_traits<RandomIt>::value_type::value_type, char>, void>
        msd_radix_sort(RandomIt first, RandomIt last) {
        using S = typename std::iterator_traits<RandomIt>::value_type;
        auto n = static_cast<std::size_t>(last - first);
        if (n <= 1) return;

        constexpr int R = 256;
        std::vector<S> buffer(n);

        auto sort_rec = [&](auto&& self, RandomIt lo, RandomIt hi, std::size_t d) -> void {
            auto m = static_cast<std::size_t>(hi - lo);
            if (m <= 1) return;

            std::vector<std::size_t> count(R + 2, 0);
            for (auto it = lo; it != hi; ++it) {
                int c = char_at_unsigned(*it, d);
                ++count[c + 1];
            }
            for (int r = 0; r <= R; ++r) {
                count[r + 1] += count[r];
            }

            std::vector<std::size_t> starts = count;

            for (auto it = lo; it != hi; ++it) {
                int c = char_at_unsigned(*it, d);
                buffer[count[c]++] = std::move(*it);
            }
            std::move(buffer.begin(), buffer.begin() + m, lo);

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

    template <class Container>
    std::enable_if_t<is_basic_string<typename Container::value_type>::value&&
        std::is_same_v<typename Container::value_type::value_type, char>, void>
        msd_radix_sort(Container& c) {
        msd_radix_sort(std::begin(c), std::end(c));
    }

    template <std::size_t N>
    void msd_radix_sort(std::string(&arr)[N]) {
        msd_radix_sort(arr, arr + N);
    }

} 