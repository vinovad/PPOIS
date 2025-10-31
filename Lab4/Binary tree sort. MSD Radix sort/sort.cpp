#include <iostream>
#include <vector>
#include <string>
#include "binary_tree_sort.h" 
#include "msd_radix_sort.h"     

using namespace sortlib;
// ���������������� ����� ��� ������������
class Userclass {
public:
    std::string name;
    int age;
    double grade;

    Userclass(const std::string& n, int a, double g) : name(n), age(a), grade(g) {}

    bool operator<(const Userclass& other) const {
        return grade < other.grade;
    }

    friend std::ostream& operator<<(std::ostream& os, const Userclass& s) {
        os << s.name << " (�������: " << s.age << ", ������: " << s.grade << ")";
        return os;
    }
};

int main() {
    setlocale(0, "rus");
    // ===== ������������ ���������� �������� ������� =====
    // � ������ �������
    std::vector<int> numbers = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    std::cout << "�� BST ����������: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(numbers);
    std::cout << "����� BST ����������: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // � ��������
    std::vector<std::string> words = { "banana", "apple", "cherry", "date" };
    std::cout << "\n�� BST ���������� �����: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(words);
    std::cout << "����� BST ���������� �����: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << std::endl;

    // � C-��������
    int arr[] = { 10, 5, 8, 1, 7 };
    std::cout << "\n�� BST ���������� �������: ";
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(arr);
    std::cout << "\n����� BST ���������� �������: ";
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    // ===== ������������ MSD ����������� ���������� =====
    // � ������ �������
    std::vector<int> radix_numbers = { 170, 45, 75, 90, 2, 802, 24, 66 };
    std::cout << "\n\n�� MSD ����������: ";
    for (int n : radix_numbers) std::cout << n << " ";
    std::cout << std::endl;
    sortlib::msd_radix_sort(radix_numbers);
    std::cout << "����� MSD ����������: ";
    for (int n : radix_numbers) std::cout << n << " ";
    std::cout << std::endl;

    // �� ��������
    std::vector<std::string> radix_words = { "word", "test", "hello", "world", "abc", "abcd" };
    std::cout << "\n�� MSD ���������� �����: ";
    for (const auto& w : radix_words) std::cout << w << " ";
    std::cout << std::endl;
    sortlib::msd_radix_sort(radix_words);
    std::cout << "����� MSD ���������� �����: ";
    for (const auto& w : radix_words) std::cout << w << " ";
    std::cout << std::endl;

    // ===== ���� � ���������������� ������� =====
    std::vector<Userclass> students = {
        {"����", 20, 8.5},
        {"����", 18, 6.8},
        {"�����", 4, 7.9},
        {"���", 30, 5.2},
        {"�����", 21, 9.5}
    };

    std::cout << "\n�� BST ���������� ���������:\n";
    for (const auto& s : students) std::cout << "  " << s << std::endl;

    sortlib::binary_tree_sort(students);
    std::cout << "\n����� BST ���������� ��������� (�� ������):\n";
    for (const auto& s : students) std::cout << "  " << s << std::endl;

    auto ageComparator = [](const Userclass& a, const Userclass& b) {
        return a.age < b.age;
        };
    sortlib::binary_tree_sort(students, ageComparator);
    std::cout << "\n����� BST ���������� ��������� (�� ��������):\n";
    for (const auto& s : students) std::cout << "  " << s << std::endl;

    return 0;
}