#include "pch.h"
#include "D:\Уник\ППОИС\1LABA\Set1\Set1\Set1\Set.cpp"

using namespace std;

TEST(SetManagerTest, InteractiveMethodsNoCrash) {
    SetManager manager;

    EXPECT_NO_THROW({
        manager.createNewSet();
        manager.createNewSet();
        manager.addElement();
        manager.removeElement();
        manager.performUnion();
        manager.performIntersection();
        manager.performDifference();
        manager.printSetCardinality();
        manager.printSetCardinality();
        manager.checkElementMembership();
        manager.convertToCantorSet();
        manager.convertToCantorSet();
        manager.printPowerSet();
        });
}
TEST(SetManagerTest, ShowSyntaxErrorsVariousCases) {
    SetManager manager;

    EXPECT_NO_THROW({
        manager.showSyntaxErrors("{a,b,}");
        manager.showSyntaxErrors("{a,,b}");
        manager.showSyntaxErrors("{a,b");
        manager.showSyntaxErrors("a,b}");
        manager.showSyntaxErrors("{}");
        manager.showSyntaxErrors("");
        });
}
TEST(SetTest, EdgeCases) {
    Set emptySet("Empty");
    EXPECT_EQ(emptySet.cardinality(), 0);
    EXPECT_FALSE(emptySet.contains("anything"));
    emptySet.add("");
    emptySet.add("   ");
    EXPECT_EQ(emptySet.cardinality(), 0);
    // Удаление из пустого множества
    bool removed = emptySet.remove("nonexistent");
    EXPECT_FALSE(removed);
}

TEST(SetTest, SpecialOperations) {
    Set set("SpecialOps");
    set.add("a");
    set.add("b");
    set.add("c");
    //проверяем что не падает(бул)
    testing::internal::CaptureStdout();
    set.printPowerSet();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    Set cantorSet = set.toCantorSet();
    EXPECT_TRUE(cantorSet.cardinality() > 0);
    EXPECT_TRUE(cantorSet.cardinality() <= set.cardinality());
}
// конструк и копирование
TEST(SetTest, ConstructorsAndCopy) {
    Set set1("Set1");
    set1.add("element1");
    Set set2(set1);
    EXPECT_STREQ(set2.getName(), "Set1");
    EXPECT_TRUE(set2.contains("element1"));
    Set set3("Temp");
    set3 = set1;
    EXPECT_STREQ(set3.getName(), "Set1");
    EXPECT_TRUE(set3.contains("element1"));
}

TEST(SetTest, EdgeCases) {
    Set emptySet("Empty");
    EXPECT_EQ(emptySet.cardinality(), 0);
    EXPECT_FALSE(emptySet.contains("anything"));
    // Пустые элементы не добавляются
    emptySet.add("");
    emptySet.add("   ");
    EXPECT_EQ(emptySet.cardinality(), 0);
    // Удаление из пустого множества
    bool removed = emptySet.remove("nonexistent");
    EXPECT_FALSE(removed);
}
TEST(SetManagerTest, SyntaxErrorHandling) {
    SetManager manager;
    testing::internal::CaptureStdout();
    manager.showSyntaxErrors("{a,b,}");
    manager.showSyntaxErrors("{a,,b}");
    manager.showSyntaxErrors("{a,b");
    manager.showSyntaxErrors("");
    string output = testing::internal::GetCapturedStdout();
    // Не проверяем конкретный вывод, главное что не упало
}
TEST(SetTest, ConstructorWithElementsString) {
    Set set("{apple, banana, cherry}", "Fruits");

    EXPECT_EQ(set.cardinality(), 3);
    EXPECT_TRUE(set.contains("apple"));
    EXPECT_TRUE(set.contains("banana"));
    EXPECT_TRUE(set.contains("cherry"));
    EXPECT_STREQ(set.getName(), "Fruits");
    Set nestedSet("{{1,2}, {3,4}, {5}}", "NestedSets");
    EXPECT_TRUE(nestedSet.cardinality() > 0);
    Set emptySet("", "EmptyConstructor");
    EXPECT_EQ(emptySet.cardinality(), 0);
}

TEST(SetTest, DataIntegrityAfterMultipleOperations) {
    Set set("IntegrityTest");
    set.add("first");
    set.add("second");
    set.add("third");
    set.add("second");
    EXPECT_EQ(set.cardinality(), 3);

    Set tempSet("Temp");
    tempSet.add("second");
    tempSet.add("fourth");

    Set unionSet = set.unionWith(tempSet);
    EXPECT_EQ(unionSet.cardinality(), 4);

    Set intersectionSet = set.intersectionWith(tempSet);
    EXPECT_EQ(intersectionSet.cardinality(), 1);
    EXPECT_TRUE(intersectionSet.contains("second"));

    Set differenceSet = set.differenceWith(tempSet);
    EXPECT_EQ(differenceSet.cardinality(), 2);
    EXPECT_TRUE(differenceSet.contains("first"));
    EXPECT_TRUE(differenceSet.contains("third"));

    EXPECT_EQ(set.cardinality(), 3);
    EXPECT_TRUE(set.contains("first"));
    EXPECT_TRUE(set.contains("second"));
    EXPECT_TRUE(set.contains("third"));

    Set cantorSet = unionSet.toCantorSet();
    EXPECT_TRUE(cantorSet.cardinality() > 0);
    testing::internal::CaptureStdout();
    set.printPowerSet();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
