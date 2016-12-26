//
// Created by ariel on 30/11/16.
//

#include <gtest/gtest.h>
#include "CabBase.h"
#include "Matrix2d.h"

using namespace std;
class TestStandardCab : public ::testing::Test{
    //the variables we want to use
protected:
    CabBase*  standartCab1;
    CabBase* standartCab2;
    Point p1;
    Point p2;
    //Matrix2d map1;
    Passenger passenger;
    int x, y;

    //setup-intialize the variables
    virtual void SetUp() {

        cout << "set up" << endl;
        standartCab1 = new CabBase(555, 1, 'h', 'r', NULL, NULL);
        standartCab2 = new CabBase(262, 2, 'f', 'r', NULL, NULL);
    }
//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown"<<endl;
        delete standartCab1;
        delete standartCab2;
    }
};
//check if the check of the kind is ok
TEST_F(TestStandardCab, amILuxuryCheck) {
    EXPECT_EQ(1, standartCab1->amILuxury());
    EXPECT_EQ(2, standartCab2->amILuxury());
}
//get cab id
TEST_F(TestStandardCab, getCabIdCheck) {
    x = standartCab1->getCabId();
    EXPECT_EQ(x, 555);
}
//get
TEST_F(TestStandardCab, getKilometersOfCabCheck) {
    y = standartCab1->getKilometersOfCab();
    EXPECT_EQ(y, 0);
}
//if update kilometers work
TEST_F(TestStandardCab, updateKilometersCheck) {
    standartCab1->updateKilometers(10);
    y = standartCab1->getKilometersOfCab();
    EXPECT_EQ(y, 10);
}
//get tarrif check
TEST_F(TestStandardCab, getTarrifCheck) {
    standartCab1->setTarrif(4);
    double d1 = standartCab1->getTarrif();
    EXPECT_EQ(d1, 4);
    standartCab2->setTarrif(8);
    double d2 = standartCab2->getTarrif();
    EXPECT_EQ(d2, 8);
}