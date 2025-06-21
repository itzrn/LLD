// Interface Segmented Principle

// Interfaces shouled be such, that client should  not implement unnecessary functions they do not need

#include <iostream>
using namespace std;

// class RestaurantEmployee{
// public:
//     virtual void washDishes()=0;
//     virtual void serveCustomer()=0;
//     virtual void CookFood()=0;
// };

// class Waiter : public RestaurantEmployee{
// public:
//     void washDishes(){
//         // not a job
//     }
//     void serveCustomer(){
//         cout<<"Serving The Customer"<<endl;
//     }
//     void CookFood(){
//         // not a job
//     }

//     /*
//         we can see above there are two function which is unnecessary in use
//         its much better to make independent virtual class
//     */
// };

class WaiterVirtual{
public:
    virtual void serveCustomer()=0;
    virtual void takeOrder()=0;
};

class ChefVirtualClass{
public:
    virtual void cookFood()=0;
    virtual void decideMenu()=0;
};

class Waiter : public WaiterVirtual{
public:
    void serveCustomer() override {
        cout<<"Serving the customer"<<endl;
    }
    void takeOrder(){
        cout<<"taking Order"<<endl;
    }
};