#pragma once
#include "pch.h"
#include "D:/Óíèê/ÏÏÎÈÑ/2LABA/Books/Books/Book.h"
TEST(BookSeriesTests, BookSeries_Complete) {
    BookSeries series;
    EXPECT_EQ(series.get_series_name(), "Harry Potter");

    BookSeries customSeries("The Witcher");
    EXPECT_EQ(customSeries.get_series_name(), "The Witcher");
}