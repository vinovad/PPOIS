#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"

TEST(NumberOfBooksTests, NumberOfBooks_Complete) {
    NumberOfBooks books;
    EXPECT_EQ(books.get_quantity(), 50);

    NumberOfBooks customBooks(100);
    EXPECT_EQ(customBooks.get_quantity(), 100);
}