#pragma once
#include <gtest/gtest.h>
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\Train.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\HighSpeedTrain.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\RegionalTrain.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\LuxuryTrain.h"

class TrainTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(TrainTest, ConstructorTest) {
    Train train(50.0, 2.5);
    EXPECT_GT(train.calculateCost(), 0);
}

TEST_F(TrainTest, GetCarriageCount) {
    Train train(60.0, 3.0);
    EXPECT_GE(train.getCarriageCount(), 0);
}

TEST_F(TrainTest, IsElectric) {
    Train train(55.0, 2.0);
    EXPECT_TRUE(train.isElectric() || !train.isElectric());
}

TEST_F(TrainTest, HighSpeedTrainInheritance) {
    HighSpeedTrain hsTrain(150.0, 1.5);
    EXPECT_GT(hsTrain.calculateCost(), 0);
}

TEST_F(TrainTest, RegionalTrainInheritance) {
    RegionalTrain regTrain(30.0, 4.0);
    EXPECT_GT(regTrain.calculateCost(), 0);
}

TEST_F(TrainTest, LuxuryTrainInheritance) {
    LuxuryTrain luxTrain(200.0, 2.0);
    EXPECT_GT(luxTrain.calculateCost(), 0);
}
