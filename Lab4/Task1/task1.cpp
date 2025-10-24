#include <iostream>
#include <vector>
#include <string>
#include "task1.h"
// Пользоват-й класс для демонстрации
class Userclass {
public:
    std::string name;
    int age;
    double grade;
    Userclass(const std::string& n, int a, double g) : name(n), age(a), grade(g) {}
    // Оператор для сортировки по умолчанию
    bool operator<(const Userclass& other) const { return grade < other.grade;}
    friend std::ostream& operator<<(std::ostream& os, const Userclass& s) {
        os << s.name << " (возраст: " << s.age << ", оценка: " << s.grade << ")";
        return os;
    }
};
int main() {
    setlocale(0, "rus");
    // ===== Тестирование сортировки бинарным деревом =====
    // С целыми числами
    std::vector<int> numbers = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    std::cout << "До BST сортировки: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(numbers);
    std::cout << "После BST сортировки: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    // С строками
    std::vector<std::string> words = { "banana", "apple", "cherry", "date" };
    std::cout << "\nДо BST сортировки строк: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(words);
    std::cout << "После BST сортировки строк: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << std::endl;
    // С C-массивом
    int arr[] = { 10, 5, 8, 1, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "\nДо BST сортировки массива: ";
    for (int i = 0; i < arr_size; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(arr);
    std::cout << "После BST сортировки массива: ";
    for (int i = 0; i < arr_size; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
    // ===== Тестирование MSD поразрядной сортировки =====
    // С целыми числами
    std::vector<int> radix_numbers = { 170, 45, 75, 90, 2, 802, 24, 66 };
    std::cout << "\n\nДо MSD сортировки: ";
    for (int n : radix_numbers) std::cout << n << " ";
    std::cout << std::endl;
    sortlib::msd_radix_sort(radix_numbers);
    std::cout << "После MSD сортировки: ";
    for (int n : radix_numbers) std::cout << n << " ";
    std::cout << std::endl;
    // Со строками
    std::vector<std::string> radix_words = { "word", "test", "hello", "world", "abc", "abcd" };
    std::cout << "\nДо MSD сортировки строк: ";
    for (const auto& w : radix_words) std::cout << w << " ";
    std::cout << std::endl;
    sortlib::msd_radix_sort(radix_words);
    std::cout << "После MSD сортировки строк: ";
    for (const auto& w : radix_words) std::cout << w << " ";
    std::cout << std::endl;
    //Тест пользоват класса
    std::vector<Userclass> Userclasss = {
        {"Анна", 20, 8.5},
        {"Дана", 18, 6.8},
        {"Мария", 4, 7.9},
        {"Юля", 30, 5.2},
        {"Ксюша", 21, 9.5}
    };
    std::cout << "\n До BST сортировки студентов:\n";
    for (const auto& s : Userclasss) std::cout << "  " << s << std::endl;
    sortlib::binary_tree_sort(Userclasss);
    std::cout << "\n После BST сортировки студентов (по оценке):\n";
    for (const auto& s : Userclasss) std::cout << "  " << s << std::endl;
    auto ageComparator = [](const Userclass& a, const Userclass& b) {
        return a.age < b.age;
        };
    sortlib::binary_tree_sort(Userclasss, ageComparator);
    std::cout << "\n После BST сортировки студентов (по возрасту):\n";
    for (const auto& s : Userclasss) std::cout << "  " << s << std::endl;
    return 0;
}
