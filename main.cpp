#include "AXB.cpp"

int main() {

    cout << "The function calculates the root of the linear equation ax + b = 0" << "\n";
 
    try {
        launcher(root1);
    }
    catch (...) {
        cout << "An exception occurred in a function root1" << endl;
    }
 
    try {
        launcher(root2);
    }
    catch (...) {
        cout << "An exception occurred in a function root2" << endl;
    }
 
    try {
        launcher(root3);
    }
    catch (invalid_argument& error) {
        cout << error.what() << endl;
    }
 
    try {
        launcher(root4_1);
    }
    catch (exception_one) {
        cout << "Exception exception_one occurred in function root4_1" << endl;
    }
 
    try {
        launcher(root4_2);
    }
    catch (exception_second& error) {
        cout << error.message() << endl;
    }
 
    try {
        launcher(root4_3);
    }
    catch (exception_third& error) {
        cout << error.what() << " " << error.arg() << endl;
    }
}