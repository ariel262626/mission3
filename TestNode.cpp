//
// Created by dvir on 30/11/16.
//

#include "Point.h"
#include "Node.h"
#include <gtest/gtest.h>
using namespace std;

class TestNode : public ::testing::Test{
    //the variables we want to use
protected:
    Node node1;
    Node node2;
    Point p1, p2;

    //setup-intialize the variables
    virtual void SetUp() {
        cout << "set up" << endl;
        p1 = Point(0,0);
        p2 = Point(1,2);
        Point point1 = Point(1,2);
        Point point2 = Point(0,0);
        node1 = Node(point1, false);
        node2 = Node(point2, false);
        node1.setFather(&node2);
    }
//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown"<<endl;
    }
};

//set flag
TEST_F(TestNode, setFlagCheck) {
    node1.setFlag();
    EXPECT_EQ(node1.getFlag(), true);
}
// check point
TEST_F(TestNode, getPointOfnodeCheck) {
    Point pCheck = node2.getPointOfnode();
    EXPECT_TRUE(pCheck == p1);
}
// check get father
TEST_F(TestNode, getNodeFatherCheck) {
    EXPECT_EQ(node1.getNodeFather(), &node2);

}
// set father
TEST_F(TestNode, setFatherCheck) {
    node1.setFather(&node1);
    EXPECT_EQ(&node1, node1.getNodeFather());
}

// get flag
TEST_F(TestNode, getFlagCheck) {
    p1 = p2;
    EXPECT_FALSE(node2.getFlag());
}

// check overloading of operator ==
TEST_F(TestNode, equalOfCheckPointAndFlag) {
    node2.setNode(Point (1,2));
    EXPECT_TRUE(node2 == node1);
}