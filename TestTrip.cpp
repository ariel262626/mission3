//
// Created by ariel on 30/11/16.
//

#include "Point.h"
#include "Trip.h"
#include <gtest/gtest.h>
using namespace std;
class TestTrip : public ::testing::Test{
    //the variables we want to use
protected:
    Trip trip;
    Matrix2d map;
    int x, y;

    //setup-initialize the variables
    virtual void SetUp() {
        cout << "set up" << endl;
        vector<Point> ol;
        // create a map
        map = Matrix2d(10, 10, ol);
    }

//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown"<<endl;
    }

//constuctor
public:
    TestTrip() : trip(231,0,0,2,2,3,4.8) {}
};

//check get path is ok
TEST_F(TestTrip, getPathOfTripCheck) {
    vector<Node*> pathTest;
    //we get the path of the trip and than check if it's the right path we expected.
    pathTest = trip.getPathOfTrip(map);
    // create some points
//    Point p0 = pathTest.at(4)->getPointOfnode();
    Point p1 = pathTest.at(3)->getPointOfnode();
    Point p2 = pathTest.at(2)->getPointOfnode();
    Point p3 = pathTest.at(1)->getPointOfnode();
    Point p4 = pathTest.at(0)->getPointOfnode();
    Point path0 = Point(0,0);
    Point path1 = Point(0,1);
    Point path2 = Point(0,2);
    Point path3 = Point(1,2);
    Point path4 = Point(2,2);
//    EXPECT_TRUE(p0 == path0);
    EXPECT_TRUE(p1 == path1);
    EXPECT_TRUE(p2 == path2);
    EXPECT_TRUE(p3 == path3);
    EXPECT_TRUE(p4 == path4);
}

//check get ride is ok
TEST_F(TestTrip, getRideIdCheck) {
    x = trip.getRideId();
    EXPECT_EQ(x, 231);
    //not negative
    EXPECT_GT(x, 0);
}
//set and than check if set worked
TEST_F(TestTrip, getMetersPassedCheck) {
    y = trip.getMetersPassed();
    EXPECT_EQ(y, 0);
    trip.setMetersPassed(trip.getMetersPassed() + 1);
    EXPECT_EQ(trip.getMetersPassed(), 1);
}
//get
TEST_F(TestTrip, getPassengersNumberCheck) {
    //assume no more than 4 passenger per taxi.
    EXPECT_LE(trip.getPassengersNumber(), 4);
    EXPECT_EQ(trip.getPassengersNumber(), 3);

}
//set
TEST_F(TestTrip, setPassengersNumberCheck) {
    trip.setPassengersNumber(4);
    EXPECT_EQ(trip.getPassengersNumber(), 4);
}