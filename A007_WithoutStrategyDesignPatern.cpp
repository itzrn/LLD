/*
    -|> - is a relationship (inheritance)
    -> - has a realtionship
*/

#include <bits/stdc++.h>
using namespace std;

/*
    to override any funtion we need to make it virtual
    the reason being all the function by default here is statically bounded

    but in java all the non-static function are by default virtual so there we dont need to explicitly mention virtual
*/

class Vehicle{ // we can create the object of class untill and unless there is pure virtual function
public:
    virtual void drive(){
        // some code
        cout<<"Normal Drive Capability"<<endl;
    }
};

class SportsVehicle : public Vehicle{
public:
    void drive() override {
        // different drive logic
        cout<<"Sports Drive Capabilities"<<endl;
    }
};

class PassengerVehicle : public Vehicle{
};

class OffRoadVehicle : public Vehicle{
public:
    void drive() override { // this is getting duplicate

        // same logic as of SportsVehicle
        cout<<"Sports drive capability"<<endl;
    }
};

class GoodsVehicle : public Vehicle{
};

