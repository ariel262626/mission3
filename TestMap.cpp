//
// Created by ariel on 30/11/16.
/*
#include <vector>
#include "Point.h"
#include "Map.h"
#include "Matrix2d.h"
#include <gtest/gtest.h>
using namespace std;
class TestMap : public ::testing::Test{
    //the variables we want to use
protected:
    Matrix2d map;
    Point p1;
    Point p2;
    int x, y;
    vector<Point> obstacleList;
    //setup-intialize the variables
    virtual void SetUp() {
        cout << "set up" << endl;
        x = 3;
        y = 3;
        p1 = Point(1,1);
        p2 = Point(2,2);
        obstacleList.push_back(p1);
        obstacleList.push_back(p2);
        map = Matrix2d(x, y, obstacleList);
    }

//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown"<<endl;
    }

//check if i get the right points of obstacles.
TEST_F(TestMap, getObstaclesListCheck) {
    vector<Point> ol = map.getObstaclesList();
    for(int i = 0; i <= obstacleList.size() - 1; i++) {
        EXPECT_TRUE(ol.at(i) == obstacleList.at(i)); //check if the 2 vector have the same values.
    }
}*/