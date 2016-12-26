//
// Created by ariel on 30/11/16.
//

#include "Point.h"
#include "Driver.h"
#include "Bfs.h"
#include "Matrix2d.h"
#include <gtest/gtest.h>
using namespace std;
class TestDriver : public ::testing::Test{
    //the variables we want to use
protected:
    Driver driver0, driver1;
    CabBase standartCab, luxuryCab;
    Point p1, p2,p3;
    Node start,end;
    Trip trip;
    Matrix2d grid;
    Bfs bfs;
    vector<Node*> pathOfBfs;
    vector <Point> listObs;
    //setup-intialize the variables
    virtual void SetUp() {
        cout << "set up" << endl;
        p1 = Point(0,0);
        p2 = Point(2,2);
        start = Node (Point (0,0), false);
        end = Node (Point (0,2), true);
        listObs.push_back(Point(0,1));
        grid = Matrix2d (4,4, listObs);
        // set the obstacle point on the map to know how to arrive to the end point
        grid.setobstaclePoint(listObs);

        Passenger passenger = Passenger (start.getPointOfnode(), end.getPointOfnode());
        standartCab = CabBase (0,1,'h','r', &grid, &passenger);
        luxuryCab = CabBase (1,2,'h','b', &grid, &passenger);
        driver0 = Driver(203,18,'s', 0, 3, standartCab, trip);
        driver1 = Driver(198,20,'s', 0, 8, luxuryCab, trip);
        bfs = Bfs (start, end, 2, &grid);
        pathOfBfs = bfs.runBfs(&start, &end);
    }

//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown"<<endl;
    }
};

// check get
TEST_F(TestDriver, getLocationCheck) {
    p3 = driver0.getLocation();
    EXPECT_TRUE(p1 == p3);
}

//check set
TEST_F(TestDriver, setLocationCheck) {
    driver0.setLocation(p2);
    EXPECT_TRUE(driver0.getLocation() == p2);
}

TEST_F(TestDriver, checkMoveStep) {
    // for standart cab. because the obstacle the next step will be to (1,0)
    driver0.moveStep(pathOfBfs);
    EXPECT_EQ(driver0.getLocation().GetX(), 1);
    // for Luxury cab
    driver1.moveStep(pathOfBfs);
    EXPECT_EQ(driver1.getLocation().GetY(), 1);
    EXPECT_EQ(driver1.getLocation().GetX(), 1);
}

TEST_F(TestDriver, checkGetIndexCurrentLocationPoint) {
    int index = driver0.getIndexCurrentLocationPoint(pathOfBfs, Point (1,1));
    // this point suppose to be in the theard place of the vector
    EXPECT_EQ(index, 2);
}