#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"

TEST(LocationTests, LocationHierarchy_Complete) {
    PositionLocation position;
    EXPECT_EQ(position.get_position(), 15);

    ShelfLocation shelf;
    EXPECT_EQ(shelf.get_shelf(), "третья");
    EXPECT_EQ(shelf.get_AssociatedPosition(), 15);

    SectionLocation section;
    EXPECT_EQ(section.get_section(), "A");
    EXPECT_EQ(section.get_AssociatedShelf(), "третья");

    HollLocation holl;
    EXPECT_EQ(holl.get_holl(), 1);
    EXPECT_EQ(holl.get_AssociatedSection(), "A");
}