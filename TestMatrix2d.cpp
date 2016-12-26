//
// Created by dvir on 30/11/16.
//


#include "Node.h"
#include "Matrix2d.h"
#include <gtest/gtest.h>
using namespace std;

class TestMatrix2d : public ::testing::Test{
    //the variables we want to use
protected:
    Matrix2d map;
    Node* end;
    vector <Point> obstacles;
    //setup-intialize the variables

virtual void SetUp() {
    cout << "set up\n" << endl;
    obstacles.push_back(Point (1,1));
    map = Matrix2d (5,5,obstacles);
     end = new Node (Point(0,3), true);
}

//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown\n"<<endl;
        delete end;

    }
};

//check the print method
TEST_F(TestMatrix2d, printRealTest){
    vector <Node*> vecToPrint;
    // create 4 nodes and push them to the vector
    Node n1 = Node (Point (0,0), true);
    vecToPrint.push_back(&n1);
    Node n2 = Node (Point (1,0), true);
    vecToPrint.push_back(&n2);
    Node n3 = Node (Point (1,1), true);
    vecToPrint.push_back(&n3);
    Node n4 = Node (Point (1,2), true);
    vecToPrint.push_back(&n4);
    //for get the printed string
    testing::internal::CaptureStdout();
    //print the elements in the vector
    map.printReal(vecToPrint);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(1,2)\n(1,1)\n(1,0)\n(0,0)\n");
}
//check if after setting the matrix updated
TEST_F(TestMatrix2d, setInMatrixTest){
    Node * n = new Node (Point (1,1), false);
    Node * father = new Node (Point (4,4), true);
    n->setFather(father);
    map.setNodeInMatrix(n);
    ASSERT_EQ(map.matrix[1][1].getPointOfnode().GetY(), 1);
    ASSERT_TRUE(*(map.matrix[1][1].getNodeFather()) == *father);
    //first delete the father and then the 'n'
    delete father;
    delete n;
}
//if we get the right neighbours
TEST_F(TestMatrix2d, TestGetNeigbours){
    Node n = Node (Point (1,1), false);
    Node n1 = Node (Point (0,1), false);
    Node n2 = Node (Point (2,1), false);
    vector <Node*> neigbours = map.getNiebours(n);
    ASSERT_TRUE(*(neigbours.at(0)) == n1);
    ASSERT_TRUE(*(neigbours.at(2)) == n2);
}

//check if i get the right points of obstacles.
TEST_F(TestMatrix2d, getObstaclesListCheck) {
    vector<Point> ol = map.getObstaclesList();
    for(int i = 0; i <= obstacles.size() - 1; i++) {
        EXPECT_TRUE(ol.at(i) == obstacles.at(i)); //check if the vector have the same value.
    }
}
//check if we get the obsracles right to matrix2d
TEST_F(TestMatrix2d, setObstaclesListCheck) {
    vector <Point> obstacles;
    obstacles.push_back(Point(0,2));
    obstacles.push_back(Point(1,2));
    map.setobstaclePoint(obstacles);
    EXPECT_TRUE(Point(0,2) == map.getObstaclesList().at(0)); //check if the vector have the same value.
}
