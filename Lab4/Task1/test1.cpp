#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>   
#include <random>
#include <cstdint>
#include "D:/Уник/ППОИС/4LABA/1задание/1задание/task1.h"
using namespace sortlib;
struct User {
    std::string name;
    int score{};
    bool operator<(const User& other) const {
        if (score != other.score) return score < other.score;
        return name < other.name;
    }
    bool operator==(const User& other) const {
        return name == other.name && score == other.score;
    }
};
template <class Container, class Compare = std::less<>>
static void expect_sorted_equal(Container c1, Compare comp = {}) {
    Container c2 = c1;
    std::sort(c2.begin(), c2.end(), comp);
    // Вызываем нашу сортировку и сверяемся со стандартной
    sortlib::binary_tree_sort(c1, comp);
    EXPECT_EQ(c1, c2);
}
TEST(BinaryTreeSort, IntVectorDefault) {
    std::vector<int> v = { 5, 1, 7, 2, 2, -3, 10, 0 };
    expect_sorted_equal(v);
}
TEST(BinaryTreeSort, IntArrayWithComparatorDesc) {
    int a[] = { 3, 1, 4, 1, 5, 9, 2 };
    auto comp = [](int x, int y) { return x > y; };
    std::array<int, 7> cpy = { 3,1,4,1,5,9,2 };
    std::sort(cpy.begin(), cpy.end(), comp);
    sortlib::binary_tree_sort(a, comp);
    EXPECT_TRUE(std::equal(cpy.begin(), cpy.end(), std::begin(a)));
}
TEST(BinaryTreeSort, CustomObjectsVector) {
    std::vector<User> st = {
        {"Ann", 90}, {"Bob", 75}, {"Carl", 90}, {"Dina", 60}, {"Eve", 75}
    };
  expect_sorted_equal(st);
}
TEST(BinaryTreeSort, EmptyAndSingle) {
    std::vector<int> empty;
    sortlib::binary_tree_sort(empty);
    EXPECT_TRUE(empty.empty());
    std::vector<int> one = { 42 };
    sortlib::binary_tree_sort(one);
    ASSERT_EQ(one.size(), 1u);
    EXPECT_EQ(one[0], 42);
}
TEST(MSDRadixSort, SignedIntsVector) {
    std::vector<int> v = { 170, 45, 75, -90, 802, 24, 2, 66, -1, 0, -2147483647 - 1, 2147483647 };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    sortlib::msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}
TEST(MSDRadixSort, UnsignedIntsVector) {
    std::vector<uint32_t> v = { 4000000000u, 0u, 1u, 4294967295u, 123456789u, 255u, 256u };
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    sortlib::msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}
TEST(MSDRadixSort, IntCArray) {
    int a[] = { 9,8,7,6,5,4,3,2,1,0, -5, -5 };
    std::array<int, 12> expected = { 9,8,7,6,5,4,3,2,1,0,-5,-5 };
    std::sort(expected.begin(), expected.end());
    sortlib::msd_radix_sort(a);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(a)));
}
TEST(MSDRadixSort, EmptyAndSingle) {
    std::vector<int> empty;
    sortlib::msd_radix_sort(empty);
    EXPECT_TRUE(empty.empty());
    std::vector<int> one = { 7 };
    sortlib::msd_radix_sort(one);
    ASSERT_EQ(one.size(), 1u);
    EXPECT_EQ(one[0], 7);
}
TEST(MSDRadixSort, RandomLargeDataset) {
    std::mt19937 rng(12345);
    std::uniform_int_distribution<int> dist(-1000000, 1000000);
    std::vector<int> v(5000);
    for (auto& x : v) x = dist(rng);
    auto expected = v;
    std::sort(expected.begin(), expected.end());
    sortlib::msd_radix_sort(v);
    EXPECT_EQ(v, expected);
}
TEST(MSDRadixSortStrings, BasicCasesVector) {
    std::vector<std::string> vs = { "b", "aa", "", "abc", "ab", "b0", "a" };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    sortlib::msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}
TEST(MSDRadixSortStrings, WithCommonPrefixes) {
    std::vector<std::string> vs = { "ab", "", "a", "abc", "abcd", "abca" };
    auto expected = vs;
    std::sort(expected.begin(), expected.end());
    sortlib::msd_radix_sort(vs);
    EXPECT_EQ(vs, expected);
}
TEST(MSDRadixSortStrings, CArray) {
    std::string arr[] = { "z", "y", "x", "xx", "" };
    std::array<std::string, 5> expected = { "z","y","x","xx","" };
    std::sort(expected.begin(), expected.end());
    sortlib::msd_radix_sort(arr);
    EXPECT_TRUE(std::equal(expected.begin(), expected.end(), std::begin(arr)));
}
TEST(CompareAlgorithms, IntsSameAsStdSort) {
    std::vector<int> v = { 5,4,3,2,1,1,2,3,4,5 };
    auto v1 = v; auto v2 = v;
    sortlib::binary_tree_sort(v1);
    sortlib::msd_radix_sort(v2);
    std::sort(v.begin(), v.end());
    EXPECT_EQ(v1, v);
    EXPECT_EQ(v2, v);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
