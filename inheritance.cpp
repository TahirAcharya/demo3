#include <iostream>
using namespace std;

class Base {
public:
    int publicMember = 1;
protected:
    int protectedMember = 2;
private:
    int privateMember = 3;
};

// Public inheritance
class PublicDerived : public Base {
public:
    void show() {
        cout << "Public inheritance: publicMember = " << publicMember << endl;
        cout << "Public inheritance: protectedMember = " << protectedMember << endl;
        // cout << "Private member not accessible" << privateMember; // Error
    }
};

// Protected inheritance
class ProtectedDerived : protected Base {
public:
    void show() {
        cout << "Protected inheritance: publicMember = " << publicMember << endl;
        cout << "Protected inheritance: protectedMember = " << protectedMember << endl;
        // cout << "Private member not accessible" << privateMember; // Error
    }
};

// Private inheritance
class PrivateDerived : private Base {
public:
    void show() {
        cout << "Private inheritance: publicMember = " << publicMember << endl;
        cout << "Private inheritance: protectedMember = " << protectedMember << endl;
        // cout << "Private member not accessible" << privateMember; // Error
    }
};

int main() {
    PublicDerived publicObj;
    publicObj.show();
    cout << "Accessing publicMember from outside: " << publicObj.publicMember << endl;

    ProtectedDerived protectedObj;
    protectedObj.show();
    // cout << protectedObj.publicMember; // Error: publicMember is protected

    PrivateDerived privateObj;
    privateObj.show();
    // cout << privateObj.publicMember; // Error: publicMember is private

    return 0;
}
