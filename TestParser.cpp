//
// Created by dvir on 15/12/16.
//

#include "PharserInfo.h"
#include <gtest/gtest.h>
using namespace std;

class TestParser : public ::testing::Test{
    //the variables we want to use
protected:

    //setup-intialize the variables
    virtual void SetUp() {

}

//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown\n"<<endl;
    }
};

//test the pharser of the grid
TEST_F(TestParser, createGridTest){
    PharserInfo pharserInfo = PharserInfo ("4 4");
    Matrix2d* grid= pharserInfo.createGrid();
    EXPECT_EQ(grid->getHigh(),4);
    EXPECT_EQ(grid->getWidth(),4);
    delete grid;
}

//test the pharser of the driver
TEST_F(TestParser, createDriverTest){
    PharserInfo pharserInfo("10,20,S,1,0");
    Driver* driver= pharserInfo.createDriver();
    EXPECT_EQ(driver->getId(), 10);
    delete driver;
}

//test the pharser of the trip
TEST_F(TestParser, createNewRideTest){
    PharserInfo pharserInfo("0,0,0,4,3,1,20");
    Trip trip= pharserInfo.createNewRide();
    Point end = trip.getEndPointOfTrip();
    Point p =  Point (4,3);
    EXPECT_TRUE(end == p);
}

//test the pharser of the cab
TEST_F(TestParser, createVehicleTest){
    PharserInfo pharserInfo("10,2,h,y");
    CabBase* cab = pharserInfo.createVehicle();
    EXPECT_EQ(cab->amILuxury(), 2);
    delete cab;
}

//test the pharser of the pharse of integer input
TEST_F(TestParser, getOneElementIntTest){
    PharserInfo pharserInfo("15,33");
    int elm = pharserInfo.getOneElementInt();
    EXPECT_EQ(elm,15);
}

//test the pharser of the pharse of double input
TEST_F(TestParser, getOneElementDoubleTest){
    PharserInfo pharserInfo = PharserInfo("15.33,33.85");
    double elm = pharserInfo.getOneElementDouble();
    EXPECT_EQ(elm,15.33);
}

//test the pharser of the pharse of char input
TEST_F(TestParser, getOneElementCharTest){
    PharserInfo pharserInfo = PharserInfo("f,g");
    char elm = pharserInfo.getOneElementchar();
    EXPECT_TRUE(elm == 'f');
}
