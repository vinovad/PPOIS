#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"

TEST(SupplierTests, Supplier_Complete) {
    Supplier supplier;
    EXPECT_EQ(supplier.get_supplier(), "Bloomsbury Publishing");
    EXPECT_EQ(supplier.get_AssociatedImportCountry(), "United Kingdom");
    EXPECT_FALSE(supplier.get_AssociatedImportProhibited());
    EXPECT_EQ(supplier.get_AssociatedBookCondition(), "new");
}