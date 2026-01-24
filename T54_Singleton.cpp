#include <iostream>
using namespace std;
class Singleton{

private:
    // making this default contructor as private so there be no access of making the object from outside
    Singleton(){
        cout<<"Singleton Constructor called. New Object created."<<endl;
    }
    static Singleton* instance;
    // static Singleton* instance = nullptr; in java we can initialize it directly here
public:
    static Singleton* getInstance(){ 
        // to use this function directly without making the object of it to access it, make this function static
        // static method are those methods belongs to class not to object

        if(instance == nullptr){
            instance=new Singleton();   
        }
        return instance;
    }
};

// initializing the class valriable, which we do here in cpp
Singleton* Singleton::instance = nullptr;

int main(int argc, char const *argv[])
{
    Singleton* s1 = Singleton :: getInstance();
    Singleton* s2 = Singleton :: getInstance();

    cout<<(s1==s2)<<endl;

    return 0;
}
