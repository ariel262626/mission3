//
// Created by ariel on 30/11/16.
//

#include <gtest/gtest.h>
#include "CabBase.h"
#include "Matrix2d.h"

using namespace std;
class TestCabBase : public ::testing::Test{
    //the variables we want to use
protected:
    CabBase*  standartCab1;
    CabBase* luxuryCab;
    Point p1;
    Passenger passenger;
    int x, y;

    //setup-intialize the variables
    virtual void SetUp() {

        cout << "set up" << endl;
        standartCab1 = new CabBase(555, 1, 'h', 'r', NULL, NULL);
        luxuryCab = new CabBase(262, 2, 'f', 'r', NULL, NULL);
    }
//delete the all alloction memory
    virtual void TearDown() {
        cout<<"TearDown"<<endl;
        delete standartCab1;
        delete luxuryCab;
    }
};
//check if the check of the kind is ok
TEST_F(TestCabBase, amILuxuryCheck) {
    EXPECT_EQ(1, standartCab1->amILuxury());
    EXPECT_EQ(2, luxuryCab->amILuxury());
}
//get cab id
TEST_F(TestCabBase, getCabIdCheck) {
    x = standartCab1->getCabId();
    EXPECT_EQ(x, 555);
}
//get
TEST_F(TestCabBase, getKilometersOfCabCheck) {
    y = standartCab1->getKilometersOfCab();
    EXPECT_EQ(y, 0);
}
//if update kilometers work
TEST_F(TestCabBase, updateKilometersCheck) {
    standartCab1->updateKilometers(10);
    y = standartCab1->getKilometersOfCab();
    EXPECT_EQ(y, 10);
}
//get tarrif check
TEST_F(TestCabBase, getTarrifCheck) {
    standartCab1->setTarrif(4);
    double d1 = standartCab1->getTarrif();
    EXPECT_EQ(d1, 4);
    luxuryCab->setTarrif(8);
    double d2 = luxuryCab->getTarrif();
    EXPECT_EQ(d2, 8);
}