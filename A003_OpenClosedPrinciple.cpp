//Open for extension but closed for modification


#include <iostream>
using namespace std;

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

class Invoice{
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


// lets say we have to save the things in another file and this particular file is hosted live
// to add the implementation of changing file will take more cost

// class InvoiceSaving{
//     Invoice* invoice;
//     public:
//         InvoiceSaving(Invoice* invoice){
//             this->invoice=invoice;
//         }
//         void saveToDB(){
//             // saving data to DB
//         }
//
//         void saveToFile(string filename){
//             // save invoice in the file with the given name
//         }
// };

// now we will use the interface here
class InvoiceSaving{ // this is open for extension
    public:
        virtual void save(Invoice* invoice)=0;
};
class SavingInvoiceToDB: public InvoiceSaving{ // closed for modifications
    public:
        void save(Invoice* invoice) override {
            // save to DB
        }
};

class SavingInvoiceToFile : public InvoiceSaving{// closed for modifications
    public:
    void save(Invoice* invoice) override {
        // save to File
    }
};