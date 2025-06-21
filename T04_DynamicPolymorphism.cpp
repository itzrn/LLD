/*
Poly -> many, morphism-> forms
showing one thing into different for is polymorphism

two types
Dynamic -> runtime -> method overriding
static -> compile time -> method overloading
*/

#ifndef T04_DynamicPolymorphism
#define T04_DynamicPolymorphism

#include <iostream>
#include <string>
using namespace std;

class Car{
protected:
    string brand, model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m){
        this->brand=b;
        this->model=m;
        isEngineOn=false;
        currentSpeed=0;
    }

    void startEngine(){
        isEngineOn=true;
        cout<<brand<<" "<<model<<" : Engine Started."<<endl;
    }
    void stopEngine(){
        isEngineOn=false;
        currentSpeed=0;
        cout<<brand<<" "<<model<<" :Engine turned oFF."<<endl;
    }
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual ~Car(){}
};
class ManulaCar:public Car{
private:
    int currentGear;
public:
    ManulaCar(string b, string m):Car(b, m){
        currentGear=0;
    }
    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" :Engine if off! Cannot Shift Gear."<<endl;
            return;
        }
        currentGear=gear;
        cout<<brand<<" "<<model<<" :shifted to gear "<<currentGear<<endl;
    }

    void accelerate() override{
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" :Engine is Off! cannot accelerate."<<endl;
            return;
        }
        currentSpeed += 20;
        cout<<brand<<" "<<model<<" :Accelerating to "<<currentSpeed<<" km/h"<<endl;
    }

    void brake() override{
        currentSpeed-=20;
        if(currentSpeed<0)currentSpeed=0;
        cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h"<<endl;
    }

};
class ElectricCar:public Car{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m):Car(b, m){
        batteryLevel = 100;
    }
    void chargeBattery(){
        batteryLevel=100;
        cout<<brand<<" "<<model<<" : Battery fully Charged!"<<endl;
    }
    void accelerate() override{
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" :Engine is Off! cannot accelerate."<<endl;
            return;
        }

        if(batteryLevel<=20){
            cout<<brand<<" "<<model<<" : Battery dead! cannot accelerate"<<endl;
            return;
        }
        batteryLevel-=10;
        currentSpeed += 15;
        cout<<brand<<" "<<model<<" :Accelerating to "<<currentSpeed<<" km/h"<<endl;
    }

    void brake() override{
        currentSpeed-=15;
        if(currentSpeed<0)currentSpeed=0;
        cout<<brand<<" "<<model<<" : Braking! Speed is now "<<currentSpeed<<" km/h"<<endl;
    }
};

int main(){
    Car* myManualCar = new ManulaCar("Suzuki", "WangonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;


    cout<<"---------------------"<<endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
    
    return 0;
}

#endif