/*
Abstraction hides unnescessary details form a clint(the person who is using that object) and showcase necessary details.

if the definations of function is exposed there is nothing harm, but in case you dont know, about it also works
*/
#ifndef T01_Abstraction
#define T01_Abstraction

#include <iostream>
#include <string>
using namespace std;
// this denotes a real life Car
class Car{ // this will act like a interface here as all the functions are virtual
public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual ~Car(){}
};

class SportsCar : public Car{
public:
    string brand, model;
    bool isEngineOn;
    int currentSpeed, currentGear;
    SportsCar(string b, string m){
        this->brand=b;
        this->model=m;
        this->isEngineOn=false;
        this->currentSpeed=0;
        this->currentGear=0;
    }
    void startEngine() override{
        isEngineOn=true;
        cout<<brand<<" "<<model<<" :Engine starts with a roar!"<<endl;
    }
    void shiftGear(int gear) override{
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
    void stopEngine() override{
        isEngineOn=false;
        currentGear=0;
        currentSpeed=0;
        cout<<brand<<" "<<model<<" : Engine turned off."<<endl;
    }
};

int main(){
    Car* meraCar = new SportsCar("Ford", "Mustang");
    meraCar->startEngine();
    meraCar->shiftGear(1);
    meraCar->accelerate();
    meraCar->shiftGear(2);
    meraCar->accelerate();
    meraCar->brake();
    meraCar->stopEngine();
    delete meraCar;
    return 0;
}

#endif