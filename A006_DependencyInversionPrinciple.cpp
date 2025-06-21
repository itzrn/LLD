// Dependency Inversion Principle

// class should depend on interfaces rather than concrete classes

#include <iostream>
using namespace std;

// ✅ Step 1: Create an abstract interface
class IKeyboard {
public:
    virtual void connect() = 0;  // Pure virtual function
    virtual ~IKeyboard() = default;  // Virtual destructor for safety
};

// ✅ Step 2: Create concrete implementations
class WiredKeyboard : public IKeyboard {
public:
    void connect() override { cout << "Wired Keyboard connected!\n"; }
};

class WirelessKeyboard : public IKeyboard {
public:
    void connect() override { cout << "Wireless Keyboard connected via Bluetooth!\n"; }
};

// ✅ Step 3: High-level module (Computer) depends on abstraction
class Computer {
    IKeyboard* keyboard;  // ✅ Uses interface, not concrete class
public:
    Computer(IKeyboard* kb) : keyboard(kb) {}  // ✅ Dependency Injection

    void start() {
        keyboard->connect();
        cout << "Computer started!\n";
    }
};

int main() {
    WiredKeyboard wiredKeyboard;
    WirelessKeyboard wirelessKeyboard;

    Computer pc1(&wiredKeyboard);
    pc1.start();  // ✅ Works with Wired Keyboard

    cout << "\nSwitching to Wireless Keyboard...\n";

    Computer pc2(&wirelessKeyboard);
    pc2.start();  // ✅ Works with Wireless Keyboard

    return 0;
}
