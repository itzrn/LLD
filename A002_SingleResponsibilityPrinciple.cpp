//Single Responsibility Prinicple
// A class should have only 1 reason to change

#include <iostream>
using namespace std;
#if !defined(A002_SingleResponsibilityPrinciple)
#define A002_SingleResponsibilityPrinciple




// let we have a Marker Entity
class Marker{
    string name, color;
    int year, price;
    public:
        Marker(string name, string color, int year, int price){
            this->name, this->color=color, this->year=year, this->price=price;
        }
        string getName(){
            return this->name;
        }
        string getColor(){
            return this->color;
        }
        int getPrice(){
            return this->price;
        }
        int getYear(){
            return this->year;
        }
};


// let we have to generate invoice for the marker

// class Invoice{
//     private:
//         Marker* marker;
//         int quantity;

//     public:
//         Invoice(Marker* marker, int quantity){
//             this->marker=marker;
//             this->quantity=quantity;
//         }

//         int calculateTotal(){
//             // let if we add GST, then calculation of price will get change
//             // change 1
//             return marker->getPrice() * this->quantity;
//         }
//         void printInvoice(){
//             // print the invoice

//             // same if we add gst printing logic will get change
//             // change 2
//         }

//         void saveToDb(){
//             // save the data into DB

//             // here also, DB table will get change and the structure of theis function will get change
//             // change 3
//         }


//         // in this class we have 3 reasons to change therefore this is not following Single Responsibility Prinicple.
// };


// let make class which follows Single Responsibility Prinicple

class Invoice{ // now this class is have only 1 reason to change
    private:
        Marker* marker;
        int quantity;
    public:
        Invoice(Marker* marker, int quantity){
            this->marker=marker;
            this->quantity=quantity;
        }
        int calculateTotal(){
            return this->marker->getPrice()*this->quantity;
        }
};

class InvoicePrinter{ // now this class is have only 1 reason to change
    private:
        Invoice* invoice;
    public:
        InvoicePrinter(Invoice* invoice){
            this->invoice=invoice;
        }
        void print(){
            // print
        }
};

class InvoiceSaving{ // now this class is have only 1 reason to change
    Invoice* invoice;
    public:
        InvoiceSaving(Invoice* invoice){
            this->invoice=invoice;
        }
        void saveToDB(){
            // saving data to DB
        }
};




#endif // A002_SingleResponsibilityPrinciple