// using interfaces
#include <iostream>
using namespace std;


class DriveStrategy{
public:
    virtual void drive()=0;
};

class NormalDriveStrategy : public DriveStrategy{
public:
    void drive() override {
        cout<<"Normal drive capability"<<endl;
    }
};

class SportDriveStrategy : public DriveStrategy{
public:
    void drive() override {
        cout<<"Sports drive capability"<<endl;
    }
};

class Vehicle{
    DriveStrategy* driveObject;
public:
    Vehicle(DriveStrategy* driveObject){
        this->driveObject=driveObject;
    }

    void drive(){
        driveObject->drive();
    }

};

class OffRoadVehicle : public Vehicle{
public:
    OffRoadVehicle():Vehicle(new SportDriveStrategy()){}
};

class SportsVehicle: public Vehicle{
public:
    SportsVehicle() : Vehicle(new SportDriveStrategy()){}
};

class GoodsVehicle : public Vehicle{
public:
    GoodsVehicle() : Vehicle(new NormalDriveStrategy()){}
};


int main(int argc, char const *argv[])
{
    Vehicle* v = new SportsVehicle();
    v->drive();
    return 0;
}

