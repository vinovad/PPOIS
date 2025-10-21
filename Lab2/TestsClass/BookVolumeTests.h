#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"


TEST(BookVolumeCountTests, BookVolumeCount_Complete) {
    BookVolumeCount volumeCount;
    EXPECT_EQ(volumeCount.get_volume_number(), 7);
    EXPECT_EQ(volumeCount.get_AssociatedSeries(), "Harry Potter");

    BookVolumeCount customVolumeCount(3, BookSeries("The Witcher"));
    EXPECT_EQ(customVolumeCount.get_volume_number(), 3);
    EXPECT_EQ(customVolumeCount.get_AssociatedSeries(), "The Witcher");
}