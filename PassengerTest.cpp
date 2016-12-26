//
// Created by ariel on 30/11/16.
//

#include <gtest/gtest.h>
#include "Point.h"
#include "Passenger.h"
#include "Driver.h"

using namespace std;
class TestPassenger : public ::testing::Test{
    //the variables we want to use
protected:
    Driver driver;
    Passenger passenger;
    Point p1,p2;

    //setup-intialize the variables
    virtual void SetUp() {
        cout << "set up\n" << endl;
        p1 = Point(0,0);
        p2 = Point(1,1);
        driver = Driver();
    }
//like the delete-if we are doing new
    virtual void TearDown() {
        cout<<"TearDown\n"<<endl;
    }
//constuctor
public:
    TestPassenger() : passenger(p1,p2){}
};

/**
 * test to check the method of setRateSatistification
 */
TEST_F(TestPassenger, setRateSatistificationCheck) {
    // change the staisfication of the passenger and update it of the driver
    int x = passenger.setRateSatistification(2);
    driver.setStatisfication(x);
    // we expect the rate will be between 0-5
    EXPECT_EQ(2, driver.getStatisfication());
    EXPECT_GE(driver.getStatisfication(), 0);
    EXPECT_LE(driver.getStatisfication(), 5);
}