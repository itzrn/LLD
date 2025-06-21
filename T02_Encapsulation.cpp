#ifndef T02_Encapsulation
#define T02_Encapsulation

/*
Ecapsulation means make similar kind of things(attribute and functions) at a place or in a class or a box

Encapsulations tells about data security(there are some info which is not need to be exposed at any cost)

there can be threat calls to the object if any outside comes to know about it which can hinder the security.

like car odometer which can not access to outsider

so we use access modifiers to provide security using encapsulation.
public private protected 
*/


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
private:
    string brand, model, tyre;
    bool isEngineOn;
    int currentSpeed, currentGear;

public:
    // getters and setters
    int getCurrentSpeed(){
        return this->currentSpeed;
    }

    // if there is to put getter and setter for an attribute the why its not left public?
    // the resone is using setter we can add some validations to set that attribute.
    string getTyre(){
        return this->tyre;
    }
    void setTyre(string tyre){
        this->tyre=tyre;
    }
    SportsCar(string b, string m){
        this->brand=b;
        this->model=m;
        this->isEngineOn=false;
        this->currentSpeed=0;
        this->currentGear=0;
        this->tyre="MRF";
    }

    // behaviours -> methods
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