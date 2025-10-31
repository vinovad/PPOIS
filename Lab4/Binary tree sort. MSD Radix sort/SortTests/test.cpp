#include "pch.h"
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <random>
#include <cstdint>
#include "D:\Уник\ППОИС\4LABA\task1\task1\sort.h"
using namespace sortlib; //поудалять ненужные

// Вспомогательный класс для проверки сортировки пользовательских типов
struct Student {
    std::string name;
    int score{};
    bool operator<(const Student& other) const {
        if (score != other.score) return score < other.score;
        return name < other.name;
    }
    bool operator==(const Student& other) const {
        return name == other.name && score == other.score;
    }
};
// Универсальная проверка совпадения со std::sort

template <class Container, class Compare = std::less<>>
static void expect_sorted_equal(Container c1, Compare comp = {}) {
    Container c2 = c1;
    std::sort(c2.begin(), c2.end(), comp);
    // Вызываем нашу сортировку и сверяемся со стандартной
    binary_tree_sort(c1, comp);
    EXPECT_EQ(c1, c2);
}

// -------- Binary Tree Sort ---------

TEST(BinaryTreeSort, IntVectorDefault) {
    std::vector<int> v = { 5, 1, 7, 2, 2, -3, 10, 0 };
    expect_sorted_equal(v);
}

TEST(BinaryTreeSort, IntArrayWithComparatorDesc) {
    int a[] = { 3, 1, 4, 1, 5, 9, 2 };
    auto comp = [](int x, int y) { return x > y; };
    std::array<int, 7> cpy = { 3,1,4,1,5,9,2 };
    std::sort(cpy.begin(), cpy.end(), comp);
    binary_tree_sort(a, comp);
    EXPECT_TRUE(std::equal(cpy.begin(), cpy.end(), std::begin(a)));
}

TEST(BinaryTreeSort, CustomObjectsVector) {
    std::vector<Student> st = {
        {"Ann", 90}, {"Bob", 75}, {"Carl", 90}, {"Dina", 60}, {"Eve", 75}, {"Ann", 90}
    };
    // Ожидаем совпадения со std::sort
    expect_sorted_equal(st);
}

TEST(BinaryTreeSort, EmptyAndSingle) {
    std::vector<int> empty;
    binary_tree_sort(empty);
    EXPECT_TRUE(empty.empty());

    std::vector<int> one = { 42 };
    binary_tree_sort(one);
    ASSERT_EQ(one.size(), 1u);
    EXPECT_EQ(one[0], 42);
}

TEST(BinaryTreeSort, ContainerOverload) {
    std::vector<int> v = { 9, 3, 7, 1, 5 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, LongType) {
    std::vector<long> v = { 100000L, -100000L, 0L, 50000L, -50000L };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, DoubleType) {
    std::vector<double> v = { 3.14, 2.71, 1.41, 0.0, -1.5, 2.71 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, StringType) {
    std::vector<std::string> v = { "zebra", "apple", "banana", "apple" };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, CArrayInt) {
    int arr[] = { 5, 2, 8, 1, 9 };
    std::vector<int> expected = { 5, 2, 8, 1, 9 };
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(arr)));
}

TEST(BinaryTreeSort, CArrayLong) {
    long arr[] = { 50L, 20L, 80L, 10L };
    std::vector<long> expected = { 50L, 20L, 80L, 10L };
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(arr)));
}

TEST(BinaryTreeSort, CArrayDouble) {
    double arr[] = { 3.14, 1.41, 2.71 };
    std::vector<double> expected = { 3.14, 1.41, 2.71 };
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(arr)));
}

TEST(BinaryTreeSort, IteratorOverload) {
    std::vector<int> v = { 4, 2, 7, 1, 9, 3 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, CustomComparator) {
    std::vector<int> v = { 1, 5, 3, 9, 2 };
    std::vector<int> expected = { 9, 5, 3, 2, 1 };
    binary_tree_sort(v, std::greater<>());
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, DuplicateElements) {
    std::vector<int> v = { 5, 5, 5, 5, 5 };
    binary_tree_sort(v);
    std::vector<int> expected = { 5, 5, 5, 5, 5 };
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, TwoElements) {
    std::vector<int> v = { 2, 1 };
    binary_tree_sort(v);
    std::vector<int> expected = { 1, 2 };
    EXPECT_EQ(v, expected);
}

// -------- MSD Radix Sort (integral) ---------

TEST(MSDRadixSort, SignedIntsVector) {
    std::vector<int> v = { 170, 45, 75, -90, 802, 24, 2, 66, -1, 0, INT32_MIN, INT32_MAX };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, UnsignedIntsVector) {
    std::vector<uint32_t> v = { 4000000000u, 0u, 1u, 4294967295u, 123456789u, 255u, 256u };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, IntCArray) {
    int a[] = { 9,8,7,6,5,4,3,2,1,0, -5, -5 };
    std::array<int, 12> expected = { 9,8,7,6,5,4,3,2,1,0,-5,-5 };
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(a);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(a)));
}

TEST(MSDRadixSort, EmptyAndSingle) {
    std::vector<int> empty;
    msd_radix_sort(empty);
    EXPECT_TRUE(empty.empty());

    std::vector<int> one = { 7 };
    msd_radix_sort(one);
    ASSERT_EQ(one.size(), 1u);
    EXPECT_EQ(one[0], 7);
}

TEST(MSDRadixSort, LongType) {
    std::vector<long> v = { 1000000L, -1000000L, 0L, 500L, -500L };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, LongLongType) {
    std::vector<long long> v = { 9223372036854775807LL, -9223372036854775807LL - 1, 0LL, 1LL, -1LL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, UnsignedLongType) {
    std::vector<unsigned long> v = { 0UL, 1UL, 1000UL, 999999UL, 500000UL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}


TEST(MSDRadixSort, UnsignedLongLongType) {
    std::vector<unsigned long long> v = { 0ULL, 1ULL, 18446744073709551615ULL, 5000ULL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ShortType) {
    std::vector<short> v = { 32767, -32768, 0, 100, -100 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, UnsignedShortType) {
    std::vector<unsigned short> v = { 0, 65535, 100, 200 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, SignedCharType) {
    std::vector<signed char> v = { 127, -128, 0, 50, -50 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, UnsignedCharType) {
    std::vector<unsigned char> v = { 0, 255, 128, 64 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerOverloadInt) {
    std::vector<int> v = { 9, 3, 7, 1, 5 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerOverloadLong) {
    std::vector<long> v = { 900L, 300L, 700L, 100L, 500L };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerOverloadUnsigned) {
    std::vector<unsigned> v = { 9u, 3u, 7u, 1u, 5u };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, CArrayLong) {
    long arr[] = { 50L, 20L, 80L, 10L, 90L };
    std::vector<long> expected = { 50L, 20L, 80L, 10L, 90L };
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(arr)));
}

TEST(MSDRadixSort, CArrayUnsigned) {
    unsigned arr[] = { 500u, 200u, 800u, 100u };
    std::vector<unsigned> expected = { 500u, 200u, 800u, 100u };
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(arr)));
}

TEST(MSDRadixSort, AllSameValue) {
    std::vector<int> v = { 42, 42, 42, 42, 42 };
    msd_radix_sort(v);
    std::vector<int> expected = { 42, 42, 42, 42, 42 };
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, TwoElements) {
    std::vector<int> v = { 2, 1 };
    msd_radix_sort(v);
    std::vector<int> expected = { 1, 2 };
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, AlreadySorted) {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    msd_radix_sort(v);
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ReverseSorted) {
    std::vector<int> v = { 5, 4, 3, 2, 1 };
    msd_radix_sort(v);
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, RandomLargeDataset) {
    // Детеминированный генератор
    std::mt19937 rng(12345);
    std::uniform_int_distribution<int> dist(-1000000, 1000000);
    std::vector<int> v(5000);
    for (auto& x : v) x = dist(rng);

    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

// -------- MSD Radix Sort (strings) ---------

TEST(MSDRadixSortStrings, BasicCasesVector) {
    std::vector<std::string> vs = { "b", "aa", "", "abc", "ab", "b0", "a", "\xff", "\x00" };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, WithCommonPrefixes) {
    std::vector<std::string> vs = { "ab", "", "a", "abc", "abcd", "abca", "ab\x01" };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, CArray) {
    std::string arr[] = { "z", "y", "x", "xx", "" };
    std::array<std::string, 5> expected = { "z","y","x","xx","" };
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(arr)));
}

TEST(MSDRadixSortStrings, EmptyString) {
    std::vector<std::string> vs = { "", "", "" };
    msd_radix_sort(vs);
    std::vector<std::string> expected = { "", "", "" };
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, SingleString) {
    std::vector<std::string> vs = { "hello" };
    msd_radix_sort(vs);
    std::vector<std::string> expected = { "hello" };
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, EmptyVector) {
    std::vector<std::string> vs;
    msd_radix_sort(vs);
    EXPECT_TRUE(vs.empty());
}

TEST(MSDRadixSortStrings, TwoStrings) {
    std::vector<std::string> vs = { "world", "hello" };
    msd_radix_sort(vs);
    std::vector<std::string> expected = { "hello", "world" };
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, AllSameStrings) {
    std::vector<std::string> vs = { "test", "test", "test" };
    msd_radix_sort(vs);
    std::vector<std::string> expected = { "test", "test", "test" };
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, LongStrings) {
    std::vector<std::string> vs = {
        "verylongstringwithmanychars",
        "anotherlongstring",
        "shortstr",
        "verylongstringwithmanycharsandmore"
    };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, SpecialCharacters) {
    std::vector<std::string> vs = { "\x01", "\x02", "\x00", "\xff", "\xfe" };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, MixedLengths) {
    std::vector<std::string> vs = { "a", "aa", "aaa", "aaaa", "" };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, ContainerOverload) {
    std::vector<std::string> vs = { "delta", "alpha", "charlie", "bravo" };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, IteratorOverload) {
    std::vector<std::string> vs = { "gamma", "beta", "alpha" };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs.begin(), vs.end());
    EXPECT_EQ(vs, expected);
}

// -------- Сравнение алгоритмов на одном наборе ---------

TEST(CompareAlgorithms, IntsSameAsStdSort) {
    std::vector<int> v = { 5,4,3,2,1,1,2,3,4,5 };
    auto v1 = v; auto v2 = v;
    binary_tree_sort(v1);
    msd_radix_sort(v2);
    std::sort(v.begin(), v.end());
    EXPECT_EQ(v1, v);
    EXPECT_EQ(v2, v);
}

// Дополнительные граничные случаи

TEST(BinaryTreeSort, LargeDataset) {
    std::mt19937 rng(54321);
    std::uniform_int_distribution<int> dist(-10000, 10000);
    std::vector<int> v(2000);
    for (auto& x : v) x = dist(rng);

    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, NegativeNumbers) {
    std::vector<int> v = { -5, -1, -10, -3, -7 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, MixedSignNumbers) {
    std::vector<int> v = { 5, -5, 0, 10, -10, 3, -3 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, UnsignedType) {
    std::vector<unsigned> v = { 5u, 2u, 8u, 1u, 9u };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ExtremeValues) {
    std::vector<int> v = { INT32_MIN, INT32_MAX, 0, -1, 1 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ManyDuplicates) {
    std::vector<int> v(100, 42);
    v.insert(v.begin(), { 1, 2, 3 });
    v.insert(v.end(), { 50, 60, 70 });
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ThreeElements) {
    std::vector<int> v = { 3, 1, 2 };
    msd_radix_sort(v);
    std::vector<int> expected = { 1, 2, 3 };
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, PowersOfTwo) {
    std::vector<int> v = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };
    auto copy = v;
    std::reverse(copy.begin(), copy.end());
    msd_radix_sort(copy);
    EXPECT_EQ(copy, v);
}

TEST(MSDRadixSortStrings, LargeDataset) {
    std::mt19937 rng(98765);
    std::uniform_int_distribution<int> len_dist(1, 20);
    std::uniform_int_distribution<int> char_dist('a', 'z');

    std::vector<std::string> vs(500);
    for (auto& s : vs) {
        int len = len_dist(rng);
        s.resize(len);
        for (int i = 0; i < len; ++i) {
            s[i] = static_cast<char>(char_dist(rng));
        }
    }

    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(BinaryTreeSort, StringWithNumbers) {
    std::vector<std::string> v = { "10", "2", "1", "20", "3" };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, NegativeLargeNumbers) {
    std::vector<long long> v = { -1000000000000LL, -999999999999LL, -1LL, 0LL, 1LL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

// Дополнительные тесты для повышения покрытия до 85%+

TEST(MSDRadixSort, IteratorOverloadInt) {
    std::vector<int> v = { 99, 88, 77, 66, 55 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, IteratorOverloadUnsigned) {
    std::vector<unsigned> v = { 999u, 888u, 777u, 666u, 555u };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, PointerOverloadInt) {
    int arr[] = { 15, 25, 35, 45, 5 };
    std::vector<int> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    msd_radix_sort<int*>(arr, arr + 5);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(MSDRadixSort, PointerOverloadLong) {
    long arr[] = { 150L, 250L, 350L, 450L, 50L };
    std::vector<long> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    msd_radix_sort<long*>(arr, arr + 5);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(MSDRadixSort, PointerOverloadUnsigned) {
    unsigned arr[] = { 1500u, 2500u, 3500u, 4500u, 500u };
    std::vector<unsigned> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    msd_radix_sort<unsigned*>(arr, arr + 5);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(MSDRadixSortStrings, PointerOverload) {
    std::string arr[] = { "zebra", "yankee", "xray", "whiskey", "victor" };
    std::vector<std::string> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    msd_radix_sort<std::string*>(arr, arr + 5);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(BinaryTreeSort, PointerOverloadInt) {
    int arr[] = { 15, 25, 35, 45, 5 };
    std::vector<int> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    binary_tree_sort<int*, std::less<>>(arr, arr + 5);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(BinaryTreeSort, PointerOverloadLong) {
    long arr[] = { 150L, 250L, 350L, 450L, 50L };
    std::vector<long> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    binary_tree_sort<long*, std::less<>>(arr, arr + 5);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(BinaryTreeSort, PointerOverloadDouble) {
    double arr[] = { 15.5, 25.5, 35.5, 45.5, 5.5 };
    std::vector<double> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    binary_tree_sort<double*, std::less<>>(arr, arr + 5);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(MSDRadixSort, VectorIteratorLongLong) {
    std::vector<long long> v = { 1000000000LL, 2000000000LL, 500000000LL, -1000000000LL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, VectorIteratorUnsignedLong) {
    std::vector<unsigned long> v = { 10000000UL, 20000000UL, 5000000UL, 1UL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, VectorIteratorUnsignedLongLong) {
    std::vector<unsigned long long> v = { 10000000000ULL, 20000000000ULL, 5000000000ULL, 1ULL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, VectorIteratorShort) {
    std::vector<short> v = { 1000, 2000, 500, -1000, -2000 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, VectorIteratorUnsignedShort) {
    std::vector<unsigned short> v = { 10000, 20000, 5000, 1, 65000 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, VectorIteratorSignedChar) {
    std::vector<signed char> v = { 100, -100, 50, -50, 0, 127, -128 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, VectorIteratorUnsignedChar) {
    std::vector<unsigned char> v = { 100, 200, 50, 1, 255, 0 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, VectorIteratorUnsigned) {
    std::vector<unsigned> v = { 100u, 200u, 50u, 1u, 255u, 0u };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, VectorIteratorString) {
    std::vector<std::string> v = { "foo", "bar", "baz", "qux" };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, MediumSizeDatasetInt) {
    std::mt19937 rng(99999);
    std::uniform_int_distribution<int> dist(-50000, 50000);
    std::vector<int> v(1000);
    for (auto& x : v) x = dist(rng);

    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, MediumSizeDatasetLong) {
    std::mt19937 rng(88888);
    std::uniform_int_distribution<long> dist(-50000L, 50000L);
    std::vector<long> v(800);
    for (auto& x : v) x = dist(rng);

    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, MediumSizeDatasetDouble) {
    std::mt19937 rng(77777);
    std::uniform_real_distribution<double> dist(-100.0, 100.0);
    std::vector<double> v(600);
    for (auto& x : v) x = dist(rng);

    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSortStrings, MediumSizeDataset) {
    std::mt19937 rng(66666);
    std::uniform_int_distribution<int> len_dist(3, 15);
    std::uniform_int_distribution<int> char_dist('A', 'z');

    std::vector<std::string> vs(300);
    for (auto& s : vs) {
        int len = len_dist(rng);
        s.resize(len);
        for (int i = 0; i < len; ++i) {
            s[i] = static_cast<char>(char_dist(rng));
        }
    }

    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

// Дополнительные тесты для покрытия всех явных инстанцирований

TEST(BinaryTreeSort, IteratorLong) {
    std::vector<long> v = { 500L, 300L, 700L, 100L, 900L };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, IteratorDouble) {
    std::vector<double> v = { 5.5, 3.3, 7.7, 1.1, 9.9 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, IteratorStringWithComparator) {
    std::vector<std::string> v = { "delta", "alpha", "charlie", "bravo" };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v.begin(), v.end(), std::less<>());
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerLongLong) {
    std::vector<long long> v = { 5000000000LL, 3000000000LL, 7000000000LL, -1000000000LL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerUnsignedLong) {
    std::vector<unsigned long> v = { 5000000UL, 3000000UL, 7000000UL, 1000000UL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerUnsignedLongLong) {
    std::vector<unsigned long long> v = { 5000000000ULL, 3000000000ULL, 7000000000ULL };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerShort) {
    std::vector<short> v = { 5000, 3000, 7000, -1000, -5000 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerUnsignedShort) {
    std::vector<unsigned short> v = { 50000, 30000, 10000, 60000 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerSignedChar) {
    std::vector<signed char> v = { 50, -50, 100, -100, 0, 127 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerUnsignedChar) {
    std::vector<unsigned char> v = { 50, 100, 200, 255, 0, 128 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ContainerStrings) {
    std::vector<std::string> v = { "zebra", "alpha", "beta", "gamma" };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, CArrayInt) {
    int arr[] = { 50, 30, 70, 10, 90 };
    std::vector<int> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(MSDRadixSort, CArrayLongWithSize) {
    long arr[] = { 500L, 300L, 700L, 100L };
    std::vector<long> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(MSDRadixSort, CArrayUnsignedWithSize) {
    unsigned arr[] = { 5000u, 3000u, 7000u, 1000u };
    std::vector<unsigned> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(MSDRadixSortStrings, CArrayWithSize) {
    std::string arr[] = { "zulu", "alpha", "bravo", "charlie" };
    std::vector<std::string> expected(std::begin(arr), std::end(arr));
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

TEST(BinaryTreeSort, ContainerOverloadDouble) {
    std::vector<double> v = { 9.9, 3.3, 7.7, 1.1, 5.5 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, ContainerOverloadString) {
    std::vector<std::string> v = { "zoo", "apple", "mango", "banana" };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, ContainerOverloadWithComparator) {
    std::vector<int> v = { 5, 3, 7, 1, 9 };
    std::vector<int> expected = { 9, 7, 5, 3, 1 };
    binary_tree_sort(v, std::greater<>());
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, CArrayWithComparator) {
    int arr[] = { 5, 3, 7, 1, 9 };
    std::vector<int> expected = { 9, 7, 5, 3, 1 };
    binary_tree_sort(arr, std::greater<>());
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), arr));
}

// Тесты для покрытия методов BinarySearchTree

TEST(BinaryTreeSort, ManyDuplicatesTree) {
    std::vector<int> v = { 5, 5, 5, 3, 3, 7, 7, 5, 3 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, RightHeavyTree) {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto expected = v;
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, LeftHeavyTree) {
    std::vector<int> v = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, BalancedTree) {
    std::vector<int> v = { 5, 3, 7, 2, 4, 6, 8, 1, 9 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

// Дополнительные тесты для увеличения покрытия рекурсивных путей

TEST(MSDRadixSort, DeepRecursion) {
    std::vector<int> v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i % 256);
    }
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSortStrings, DeepRecursionStrings) {
    std::vector<std::string> vs;
    for (int i = 0; i < 200; ++i) {
        vs.push_back(std::string(10, 'a' + (i % 26)));
    }
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSort, SingleByteRange) {
    std::vector<signed char> v;
    for (signed char i = -128; i < 127; ++i) {
        v.push_back(i);
    }
    v.push_back(127);
    std::reverse(v.begin(), v.end());

    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, UnsignedByteRange) {
    std::vector<unsigned char> v;
    for (int i = 0; i < 256; ++i) {
        v.push_back(static_cast<unsigned char>(255 - i));
    }

    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

// Дополнительные тесты для покрытия всех веток рекурсии

TEST(MSDRadixSort, MultiByteRecursion) {
    std::vector<int> v;
    // Создаем числа с разными байтами для глубокой рекурсии
    for (int i = 0; i < 256; ++i) {
        v.push_back(i << 24);
        v.push_back(i << 16);
        v.push_back(i << 8);
        v.push_back(i);
    }
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSortStrings, VeryLongCommonPrefix) {
    std::vector<std::string> vs = {
        std::string(100, 'a') + "z",
        std::string(100, 'a') + "y",
        std::string(100, 'a') + "x",
        std::string(100, 'a') + "w",
        std::string(100, 'a')
    };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSortStrings, AllSameLengthDifferentChars) {
    std::vector<std::string> vs;
    for (char c = 'z'; c >= 'a'; --c) {
        vs.push_back(std::string(5, c));
    }
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(MSDRadixSort, LargeNumbersAllBytes) {
    std::vector<long long> v;
    for (int i = 0; i < 100; ++i) {
        v.push_back(static_cast<long long>(i) * 1000000000LL);
        v.push_back(-static_cast<long long>(i) * 1000000000LL);
    }
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, VeryDeepTree) {
    std::vector<int> v;
    for (int i = 1000; i >= 1; --i) {
        v.push_back(i);
    }
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(BinaryTreeSort, MoveSemantics) {
    std::vector<std::string> v = { "delta", "alpha", "charlie", "bravo" };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ZeroesAndOnes) {
    std::vector<int> v(500, 0);
    v.insert(v.end(), 500, 1);
    std::reverse(v.begin(), v.end());
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSortStrings, OnlyEmptyStrings) {
    std::vector<std::string> vs(100, "");
    msd_radix_sort(vs);
    EXPECT_EQ(vs.size(), 100u);
    for (const auto& s : vs) {
        EXPECT_TRUE(s.empty());
    }
}

TEST(MSDRadixSortStrings, SingleCharStrings) {
    std::vector<std::string> vs;
    for (char c = 'z'; c >= 'a'; --c) {
        vs.push_back(std::string(1, c));
    }
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(BinaryTreeSort, AllNegative) {
    std::vector<int> v = { -1, -5, -3, -10, -2, -8 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    binary_tree_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, AlternatingSignBits) {
    std::vector<int> v;
    for (int i = -128; i <= 127; ++i) {
        v.push_back(i);
    }
    std::reverse(v.begin(), v.end());
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, ShortTypeFullRange) {
    std::vector<short> v;
    for (int i = -1000; i <= 1000; ++i) {
        v.push_back(static_cast<short>(i));
    }
    std::reverse(v.begin(), v.end());
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSort, UnsignedShortFullRange) {
    std::vector<unsigned short> v;
    for (unsigned i = 0; i <= 2000; ++i) {
        v.push_back(static_cast<unsigned short>(i));
    }
    std::reverse(v.begin(), v.end());
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}

TEST(MSDRadixSortStrings, AllPrintableASCII) {
    std::vector<std::string> vs;
    for (int i = 32; i < 127; ++i) {
        vs.push_back(std::string(1, static_cast<char>(i)));
    }
    std::reverse(vs.begin(), vs.end());
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}

TEST(BinaryTreeSort, WithDuplicatesAndComparator) {
    std::vector<double> v = { 5.5, 5.5, 3.3, 3.3, 7.7, 7.7 };
    std::vector<double> expected = { 7.7, 7.7, 5.5, 5.5, 3.3, 3.3 };
    binary_tree_sort(v, std::greater<>());
    EXPECT_EQ(v, expected);
}




int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
