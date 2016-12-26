//
// Created by ariel on 30/11/16.
//

#include <gtest/gtest.h>
#include "Point.h"
#include "Trip.h"
#include "Driver.h"
#include "Passenger.h"
#include "TexiCenter.h"
#include "Matrix2d.h"


using namespace std;
class TestTexiCenter : public ::testing::Test{
    //the variables we want to use
protected:
    Bfs bfs;
    TexiCenter texiCenter;
    Trip trip1, trip2;
    Passenger* passenger1;
    Passenger* passenger2;
    Passenger* passenger3;
    Driver* driver1;
    Driver* driver2;
    CabBase* standartCab1;
    CabBase* standartCab2;
    Point p1;
    Point p2;
    vector<Passenger*> passengersList;
    Matrix2d matrix2d;
    int x;


    //setup-intialize the variables
    virtual void SetUp() {
        cout << "set up" << endl;
        p1 = Point (0,0);
        p2 = Point(1,1);
        trip1 = Trip(111, 0,0,2,2,3,4.8);
        trip2 = Trip(012,0,0,2,1,4,4.8);
        texiCenter.addTripToTripLIst(trip1);
        texiCenter.addTripToTripLIst(trip2);
        passenger1 = new Passenger(p1, p2);
        passenger2 = new Passenger(Point(2,2), Point(0,1));
        passenger3 = new Passenger(Point(1,1), Point(0,1));
        passengersList.push_back(passenger1);
        passengersList.push_back(passenger2);
        passengersList.push_back(passenger3);
        standartCab1 = new CabBase(111, 55,'h', 'b', NULL, passenger1);
        standartCab2 = new CabBase(222, 32,'f', 'b', NULL, passenger2);
        texiCenter.addCabToCabsLIst(standartCab1);
        texiCenter.addCabToCabsLIst(standartCab2);
        driver1 = new  Driver(5101, 21,'s', 1, 0, *standartCab1, trip1);
        driver2 = new  Driver(76, 21,'s', 1, 0, *standartCab2, trip2);
        texiCenter.addDriverToDriverLIst(driver1);
        texiCenter.addDriverToDriverLIst(driver2);
        vector<Point> lo;
        matrix2d = Matrix2d(10,10,lo);
        texiCenter.setMap(matrix2d);
        x = 0;
    }
// delete the all allocation memory
    virtual void TearDown() {
        cout<<"TearDown"<<endl;
        delete passenger1;
        delete passenger2;
        delete passenger3;
        delete standartCab1;
        delete standartCab2;
        delete driver1;
        delete driver2;
    }
//constuctor
public:
    TestTexiCenter() : texiCenter() {}
};
//check if start driving takes all drivers to end point.
TEST_F(TestTexiCenter, startDrivingCheck) {
    texiCenter.startDriving();
    Point pS = texiCenter.getDriverInIndex(0)->getLocation();
    Point pE = Point(2,2);
    EXPECT_TRUE(pS == pE);
    // check it on another point
    pS = texiCenter.getDriverInIndex(1)->getLocation();
    pE = Point(2,1);
    EXPECT_TRUE(pS == pE);
}

/*
 * we check if we get the right driver from the list- we need to get
 * the closest driver to the passenger.
 */
TEST_F(TestTexiCenter, findDriverCheck) {
   Point o1 = Point(3,2);
    vector<Point> obstacle;
    obstacle.push_back(o1);
    Driver closestDriver(0,0,'s',0,0,*standartCab1,trip1);
    Node startNode = Node(passenger1->getStartPoint(), false);
    //the end node need to be true.
    Node endNode = Node(passenger1->getEndPoint(), true);
   bfs = Bfs(startNode, endNode, 2, &matrix2d);
   closestDriver = texiCenter.findDriver(*passenger2);
    EXPECT_EQ(closestDriver.getId(), 76);
}

/*
 * check the method that find location according id.
 */
TEST_F(TestTexiCenter, findLocationOfDriverCheck) {
    Point p = Point(2,2);
    Driver* dr = texiCenter.getDriverInIndex(0);
    dr->setLocation(p);
    Point location = texiCenter.findLocationOfDriver(5101);
    EXPECT_TRUE(location == p);
}

/*
 * check the method that add driver to the list.
 */
TEST_F(TestTexiCenter, addDriverToDriverLIstCheck) {
    Driver driver3 = Driver(121,17,'s',2,222, *standartCab1, trip1);
    // add driver to taxi center
    texiCenter.addDriverToDriverLIst(&driver3);
    int id = texiCenter.getDriverInIndex(2)->getId();
    EXPECT_EQ(id, 121);
}

/*
 * check the method that add cab to the list.
 */
TEST_F(TestTexiCenter, addCabToCabsLIstCheck) {
    CabBase standartCab3 = CabBase(555,1,'h','R',NULL,NULL);
    texiCenter.addCabToCabsLIst(&standartCab3);
    int id = texiCenter.getCabInIndex(2)->getCabId();
    EXPECT_EQ(id, 555);
}

/*
 * check the method that add trip to the list.
 */
TEST_F(TestTexiCenter, addTripToTripLIstCheck) {
    Trip trip3 = Trip(333, 0, 0, 1, 2, 2, 4);
    texiCenter.addTripToTripLIst(trip3);
    int id = texiCenter.getTripInIndex(2).getRideId();
    EXPECT_EQ(id, 333);
}