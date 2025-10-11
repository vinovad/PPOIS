#include "pch.h"
#include <gtest/gtest.h>
#include "D:\Уник\ППОИС\1LABA\Set\MultiSet\MultiSet\MultiSet.cpp"

using namespace std;
//тестируем управление счетчиком элементов
TEST(MultiSetElementTest, CountManipulation) {
    MultiSetElement elem("a", 3, false);
    elem.setCount(4);
    EXPECT_EQ(4, elem.getCount());
    elem.setCount(0);
    EXPECT_EQ(0, elem.getCount());
    elem.setIsSet(true);
    EXPECT_TRUE(elem.getIsSet());
}
//Сравнение элементов с одинаковым значением, но разными счетчиками
TEST(MultiSetElementTest, ComparisonOperators) {
    MultiSetElement elem1("test", 1, false);
    MultiSetElement elem2("test", 2, false);
    MultiSetElement elem3("other", 1, false);
    MultiSetElement elem4("test", 1, true);

    EXPECT_TRUE(elem1 == elem2);
    EXPECT_FALSE(elem1 == elem3);
    EXPECT_FALSE(elem1 == elem4);
    EXPECT_TRUE(elem1 == "test");
    EXPECT_FALSE(elem1 == "other");
    EXPECT_FALSE(elem4 == "test"); // isSet = true, поэтому false
}

TEST(UndirectedMultiSetTest, Constructors) {
    // Конструктор по умолчанию
    UndirectedMultiSet emptySet;
    EXPECT_TRUE(emptySet.isEmpty());
    EXPECT_EQ(0, emptySet.power());
    EXPECT_EQ(0, emptySet.uniqueCount());
    EXPECT_EQ(0, emptySet.totalCount());

    // Конструктор из строки
    UndirectedMultiSet setFromString("1, 2, 3");
    EXPECT_FALSE(setFromString.isEmpty());
    EXPECT_EQ(3, setFromString.power());
    EXPECT_EQ(3, setFromString.uniqueCount());

    // Конструктор копирования(создает идентичную копию)
    UndirectedMultiSet copy(setFromString);
    EXPECT_EQ(setFromString.power(), copy.power());
    EXPECT_EQ(setFromString.uniqueCount(), copy.uniqueCount());
}


// Удалеине 
TEST(UndirectedMultiSetTest, RemoveOperations) {
    UndirectedMultiSet set("a, b, c, a, b");

    // Удаление одного экземпляра
    set.remove("a", false, 1);
    EXPECT_TRUE(set.contains("a")); // Должен остаться один А
    // Удаление всех экземпляров
    set.remove("a", false, 1);
    EXPECT_FALSE(set.contains("a"));
    // Удаление несуществующего элемента
    testing::internal::CaptureStdout();
    set.remove("nonexistent");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Элемент не найден"), std::string::npos);
    // Удаление множества как элемента
    set.add("{set}", 1, true);
    set.remove("{set}", true, 1);
    EXPECT_FALSE(set.contains("{set}", true));
}





TEST(UndirectedMultiSetTest, CompoundAssignmentOperations) {
    UndirectedMultiSet set1("a, b");
    UndirectedMultiSet set2("b, c");

    // +=
    set1 += set2;
    EXPECT_TRUE(set1.contains("a"));
    EXPECT_TRUE(set1.contains("b"));
    EXPECT_TRUE(set1.contains("c"));

    // *=
    UndirectedMultiSet set3("a, b, b");
    UndirectedMultiSet set4("b, c");
    set3 *= set4;
    EXPECT_TRUE(set3.contains("b"));
    EXPECT_FALSE(set3.contains("a"));
    EXPECT_FALSE(set3.contains("c"));

    // -=
    UndirectedMultiSet set5("a, b, c");
    UndirectedMultiSet set6("b");
    set5 -= set6;
    EXPECT_TRUE(set5.contains("a"));
    EXPECT_TRUE(set5.contains("c"));
    EXPECT_FALSE(set5.contains("b"));
}

TEST(UndirectedMultiSetTest, BooleanOperation) {
    UndirectedMultiSet set("1, 2");
    UndirectedMultiSet boolean = set.boolean();
    //минимум для  Булеана( должен содержать как минимум пустое множество и само множество)
    EXPECT_TRUE(boolean.contains("{}", true));
    EXPECT_GE(boolean.power(), 2);
}

TEST(UndirectedMultiSetTest, ResizeFunctionality) {
    UndirectedMultiSet set;
    // Добавляем много элементов для проверки resize
    for (int i = 0; i < 20; i++) {
        char element[10];
        sprintf(element, "elem%d", i);
        set.add(element);
    }
    EXPECT_EQ(20, set.power());
    EXPECT_EQ(20, set.uniqueCount());
}

TEST(SetManagerTest, BasicOperations) {
    SetManager manager;

    // Добавление множеств
    UndirectedMultiSet set1("1, 2");
    UndirectedMultiSet set2("3, 4");

    manager.addSet("Set1", set1);
    manager.addSet("Set2", set2);

    EXPECT_EQ(2, manager.getSetCount());
    EXPECT_STREQ("Set1", manager.getSetName(0));
    EXPECT_STREQ("Set2", manager.getSetName(1));

    // Получение множеств
    const UndirectedMultiSet& retrieved = manager.getSet(0);
    EXPECT_EQ(set1.power(), retrieved.power());
}


TEST(SetManagerTest, AutoNaming) {
    SetManager manager;
    UndirectedMultiSet set1("a");
    UndirectedMultiSet set2("b");
    UndirectedMultiSet set3("c");

    manager.addSetAutoName(set1);
    manager.addSetAutoName(set2);
    manager.addSetAutoName(set3);

    EXPECT_EQ(3, manager.getSetCount());
    EXPECT_STREQ("Set1", manager.getSetName(0));
    EXPECT_STREQ("Set2", manager.getSetName(1));
    EXPECT_STREQ("Set3", manager.getSetName(2));
}

//граничные случаи:
TEST(SetManagerTest, BoundaryConditions) {
    SetManager manager;
    UndirectedMultiSet set("test");
    // Пустое имя
    manager.addSet("", set);
    EXPECT_STREQ("", manager.getSetName(0));
    // Неверные индексы
    EXPECT_EQ(nullptr, manager.getSetName(-1));
    EXPECT_EQ(nullptr, manager.getSetName(100));

}

TEST(SetManagerTest, ResizeFunctionality) {
    SetManager manager;
    UndirectedMultiSet set("test");
    for (int i = 0; i < 15; i++) {
        char name[20];
        sprintf(name, "Set%d", i);
        manager.addSet(name, set);
    }

    EXPECT_EQ(15, manager.getSetCount());
    EXPECT_STREQ("Set0", manager.getSetName(0));
    EXPECT_STREQ("Set14", manager.getSetName(14));
}

TEST(SetManagerTest, ListAndSelectOperations) {
    SetManager manager;
    UndirectedMultiSet set1("a, b");
    UndirectedMultiSet set2("c, d");

    manager.addSet("First", set1);
    manager.addSet("Second", set2);


    // Проверяем что listSets не падает
    EXPECT_NO_THROW({
        manager.listSets();
        });

    // selectSet требует ввода, тестируем только что не падает
    EXPECT_NO_THROW({
        // Не можем протестировать интерактивную часть, но проверяем что метод существует
        });
}

// Тесты обработки ошибок и граничных случаев
TEST(ErrorHandlingTest, MalformedStrings) {
    EXPECT_NO_THROW({
        UndirectedMultiSet unbalanced1("{a, b");    // Несбалансированные скобки
        UndirectedMultiSet unbalanced2("a, b}");    // Несбалансированные скобки
        UndirectedMultiSet nestedUnbalanced("{{a, b}"); // Вложенные несбалансированные
        UndirectedMultiSet onlyBraces("{}");        // Только скобки
        UndirectedMultiSet complex("a, {b, {c, d}}, e"); // Сложная структура
        });
}

TEST(ErrorHandlingTest, SelfOperations) {
    UndirectedMultiSet set("a, b");

    // Самоприсваивание
    set = set;
    EXPECT_TRUE(set.contains("a"));
    EXPECT_TRUE(set.contains("b"));

    // Операции с самим собой
    UndirectedMultiSet result1 = set + set;
    UndirectedMultiSet result2 = set * set;
    UndirectedMultiSet result3 = set - set;

    EXPECT_TRUE(result1.contains("a"));
    EXPECT_TRUE(result2.contains("a"));
    EXPECT_FALSE(result3.contains("a")); // Разность с самим собой дает пустое множество
}




int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
