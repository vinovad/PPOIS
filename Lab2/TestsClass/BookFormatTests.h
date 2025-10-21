#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"

TEST(BookFormatTests, BookFormat_Complete) {
    BookFormat format;
    EXPECT_EQ(format.get_bookformat(), "A5");
    EXPECT_EQ(format.get_AssociatedPageCount(), 400);

    BookFormat customFormat("A4", PageCount(200));
    EXPECT_EQ(customFormat.get_bookformat(), "A4");
    EXPECT_EQ(customFormat.get_AssociatedPageCount(), 200);
}