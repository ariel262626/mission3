//
// Created by ariel on 29/11/16.

#include "Point.h"
#include <gtest/gtest.h>
using namespace std;
class TestPoint : public ::testing::Test{
    //the variables we want to use
protected:
    Point p1;
    Point p2;
    int x, y;

    //setup-intialize the variables
virtual void SetUp() {
    cout << "set up" << endl;
    x = p1.GetX();
    y = p1.GetY();
}

//like the delete-if we are doing new
virtual void TearDown() {
    cout<<"TearDown"<<endl;
}

//constuctor
public:
TestPoint() : p1(1,2), p2(0,0) {}
};

//get
TEST_F(TestPoint, GetXCheck) {
    EXPECT_EQ(x,p1.GetX());
}
//get
TEST_F(TestPoint, GetYCheck) {
    EXPECT_EQ(y,p1.GetY());
}
//set
TEST_F(TestPoint, SetXCheck) {
    p1.SetX(p2.GetX());
    EXPECT_EQ(p2.GetX(),p1.GetX());
}
//set
TEST_F(TestPoint, SetYCheck) {
    p1.SetY(p2.GetY());
    EXPECT_EQ(p2.GetY(),p1.GetY());
}
//overloading check of == operator
TEST_F(TestPoint, EqualsPointCheck) {
    p1 = p2;
    EXPECT_TRUE(p1 == p2);
}
//check the print
TEST_F(TestPoint, PrintPointCheck) {
    testing::internal::CaptureStdout();
    std::cout<<p1;
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "(1,2)");
}