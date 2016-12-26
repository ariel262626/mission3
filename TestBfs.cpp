//
// Created by ariel on 30/11/16.
//

#include <gtest/gtest.h>
#include <stack>
#include <queue>
#include "Point.h"
#include "Node.h"
#include "Grid.h"
#include "Matrix2d.h"
#include "Bfs.h"

using namespace std;
class TestBfs : public ::testing::Test{
    //the variables we want to use
protected:
    Bfs bfs;
    Grid* matrix2d;
    Node* currentNode;
    Node* n1;
    Node* n2;
    Node* n3;
    Node* n4;
    Node startNode, endNode;
    Point currentP, p1, p2, p3, p4;
    queue<Node*> queue1;
    stack<Node*> stack1;

    //setup-intialize the variables
    virtual void SetUp() {
        cout << "set up" << endl;
        currentP = Point(0,0);
        currentNode = new Node(currentP, false);
        p1 = Point(-1, -1);
        p2 = Point(0, 1);
        p3 = Point(1, 0);
        p4 = Point(-1, -1);
        n1 = new Node(p1, false);
        n2 = new Node(p2, true);
        n3 = new Node(p3, true);
        n4 = new Node(p4, false);
        startNode = Node(Point(0,0), false);
        endNode = Node(Point(1,1), true);
        vector<Point> lo;
        matrix2d  = new Matrix2d(10, 10, lo);


    }
//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown"<<endl;
        delete n1;
        delete n2;
        delete n3;
        delete n4;
        delete currentNode;
        delete matrix2d;
    }
};

//test if the running of the bfs work good
TEST_F(TestBfs, runBfsCheck) {
    bfs = Bfs(startNode, endNode, 2, matrix2d);
    vector<Node*> traj = bfs.runBfs(&startNode, &endNode);
    EXPECT_TRUE(*(traj.at(1)) == *n2);
}

//check if our manage queue is right
TEST_F(TestBfs, manageQueueCheck) {
    bfs = Bfs(startNode, endNode, 2, matrix2d);
    bfs.manageQueue(queue1, stack1, currentNode);
    EXPECT_TRUE(*(stack1.top()) == *n3);
    stack1.pop();
    EXPECT_TRUE(*(stack1.top()) == *n2);
    stack1.pop();
    EXPECT_TRUE(stack1.empty());
    EXPECT_TRUE(*(queue1.front()) == *n2);
    queue1.pop();
    EXPECT_TRUE(*(queue1.front()) == *n3);
    queue1.pop();
    EXPECT_TRUE(queue1.empty());
}