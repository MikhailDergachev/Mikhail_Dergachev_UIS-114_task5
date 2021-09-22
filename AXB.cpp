#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class exception_one {};
 
class exception_second {
private:
    string msg;

public:
    exception_second(const string& s)
        : msg(s) {}

    const char *message() const { 
        return msg.c_str(); 
    }
};
 
class exception_third : public invalid_argument {
private:
    double num;

public:
    exception_third(const string msg, double n) 
        : invalid_argument(msg), num(n) {}

    double arg() const { 
        return num; 
    }
};
 
double root1(double a, double b) {
    return -b / a;
}
 
double root2(double a, double b) throw() {
    return -b / a;
}
 
double root3(double a, double b) throw(invalid_argument) {
    if (a == 0.0)
        throw invalid_argument("Division by 0");
    return -b / a;
}
 
double root4_1(double a, double b) throw (exception_one) {
    if (a == 0.0)
        throw exception_one();
    return -b / a;
}
 
double root4_2(double a, double b) throw(exception_second) {
    if (a == 0.0)
        throw exception_second("Division by 0");
    return -b / a;
}
 
double root4_3(double a, double b) throw(exception_third) {
    if (a == 0.0)
        throw exception_third("Invalid argument", a);
    return -b / a;
}
 
void launcher(double (*func)(double, double)) {
    double a, b;
    cout << "Enter a = ";
    cin >> a;
    cout << "Enter b = ";
    cin >> b;
    cout << "Linear equation root: " << func(a, b) << endl;
}
 
