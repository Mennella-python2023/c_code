#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int* p = &a;
    int b = *p; // Dereferencing pointer p to get the value of a
    cout << "Value of b: " << b << endl; // Output should be 10
    cout << "Address of a: " << &a << endl; // Output the address of a
    cout << "Value of p (address of a): " << p << endl; // Output the value of p which is the address of a  
    
    return 0;
}