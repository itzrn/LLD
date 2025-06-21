/*
    If class B is a subtype of class A, then we should be able to replace
    object of A with B without breaking the behaviour of the program.
*/

// subclass should extend the capability of parent class not narrow it down
// #include <exception>
#include <stdexcept> 
using namespace std;
class Bike{
    public:
        virtual void turningOnEngine()=0;
        virtual void accelerate()=0;
};

class MotorCycle : public Bike{
    
    public:
        bool isEngineOn;
        int speed;
        MotorCycle():isEngineOn(false), speed(0){}

        void turningOnEngine() override{
            // turning on engine
            isEngineOn=true;
        }

        void accelerate() override {
            // increase the speed
            speed += 10;
        }
};

class Bicycle : public Bike{
    public:
        void turningOnEngine() override{ // this capability is break, the capability should not be narrow down
            throw runtime_error("there is no engine");
        } // means this function is need to be used, and to do that the entity should be accordingly

        void acceleratr(){
            // do accelerate
        }
};