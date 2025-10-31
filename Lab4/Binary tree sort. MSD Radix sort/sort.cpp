#include <iostream>
#include <vector>
#include <string>
#include "sort.h" 

using namespace sortlib;
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
        os << s.name << " (âîçðàñò: " << s.age << ", îöåíêà: " << s.grade << ")";
        return os;
    }
};

int main() {
    setlocale(0, "rus");
    // ===== Òåñòèðîâàíèå ñîðòèðîâêè áèíàðíûì äåðåâîì =====
    std::vector<int> numbers = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    std::cout << "Äî BST ñîðòèðîâêè: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(numbers);
    std::cout << "Ïîñëå BST ñîðòèðîâêè: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;
    
    std::vector<std::string> words = { "banana", "apple", "cherry", "date" };
    std::cout << "\nÄî BST ñîðòèðîâêè ñòðîê: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(words);
    std::cout << "Ïîñëå BST ñîðòèðîâêè ñòðîê: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << std::endl;

    int arr[] = { 10, 5, 8, 1, 7 };
    std::cout << "\nÄî BST ñîðòèðîâêè ìàññèâà: ";
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    sortlib::binary_tree_sort(arr);
    std::cout << "\nÏîñëå BST ñîðòèðîâêè ìàññèâà: ";
    for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    // ===== Òåñòèðîâàíèå MSD ïîðàçðÿäíîé ñîðòèðîâêè =====
   
    std::vector<int> radix_numbers = { 170, 45, 75, 90, 2, 802, 24, 66 };
    std::cout << "\n\nÄî MSD ñîðòèðîâêè: ";
    for (int n : radix_numbers) std::cout << n << " ";
    std::cout << std::endl;
    sortlib::msd_radix_sort(radix_numbers);
    std::cout << "Ïîñëå MSD ñîðòèðîâêè: ";
    for (int n : radix_numbers) std::cout << n << " ";
    std::cout << std::endl;

    std::vector<std::string> radix_words = { "word", "test", "hello", "world", "abc", "abcd" };
    std::cout << "\nÄî MSD ñîðòèðîâêè ñòðîê: ";
    for (const auto& w : radix_words) std::cout << w << " ";
    std::cout << std::endl;
    sortlib::msd_radix_sort(radix_words);
    std::cout << "Ïîñëå MSD ñîðòèðîâêè ñòðîê: ";
    for (const auto& w : radix_words) std::cout << w << " ";
    std::cout << std::endl;

    // ===== Òåñò ñ ïîëüçîâàòåëüñêèì êëàññîì =====
    std::vector<Userclass> students = {
        {"Àííà", 20, 8.5},
        {"Äàíà", 18, 6.8},
        {"Ìàðèÿ", 4, 7.9},
        {"Þëÿ", 30, 5.2},
        {"Êñþøà", 21, 9.5}
    };

    std::cout << "\nÄî BST ñîðòèðîâêè ñòóäåíòîâ:\n";
    for (const auto& s : students) std::cout << "  " << s << std::endl;

    sortlib::binary_tree_sort(students);
    std::cout << "\nÏîñëå BST ñîðòèðîâêè ñòóäåíòîâ (ïî îöåíêå):\n";
    for (const auto& s : students) std::cout << "  " << s << std::endl;

    auto ageComparator = [](const Userclass& a, const Userclass& b) {
        return a.age < b.age;
        };
    sortlib::binary_tree_sort(students, ageComparator);
    std::cout << "\nÏîñëå BST ñîðòèðîâêè ñòóäåíòîâ (ïî âîçðàñòó):\n";
    for (const auto& s : students) std::cout << "  " << s << std::endl;

    return 0;

}

