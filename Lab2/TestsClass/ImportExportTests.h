#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"

TEST(ImportExportTests, ImportExportCountry_Complete) {
    ImportCountry importCountry;
    EXPECT_EQ(importCountry.get_import_country(), "United Kingdom");
    EXPECT_FALSE(importCountry.get_AssociatedProhibitedStatus());
    EXPECT_EQ(importCountry.get_AssociatedProhibitedCountry(), "Belarus");

    ExportCountry exportCountry;
    EXPECT_EQ(exportCountry.get_export_country(), "United Kingdom");
    EXPECT_FALSE(exportCountry.get_AssociatedProhibitedStatus());
    EXPECT_EQ(exportCountry.get_AssociatedProhibitedCountry(), "Belarus");
}