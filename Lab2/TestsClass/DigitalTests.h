#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h" 

TEST(DigitalTests, DigitalFormats_Complete) {
    Audiobook audio;
    EXPECT_TRUE(audio.has_audiobook_version());

    ElectronicPDF pdf;
    EXPECT_TRUE(pdf.has_pdf_version());
    EXPECT_TRUE(pdf.get_AssociatedAudiobook());
}