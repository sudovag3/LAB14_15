#include<iostream>
using namespace std;

int f(int p) {
    if(p<0) throw 1;
    return 2+p;
}

class MyType {
    int i; double d;
public:
    MyType(int ii, double dd) {
        try {
            i = f(ii);
            d = dd;
            cout << "hello" << endl;
        }
        catch (...) {
            cout << "error" << endl;
            throw; // Решение 1: Обрабатываем исключение в теле конструктора
        }
    }
};

int main() {
    try {
        MyType obj(-1, 2.0); // Создание объекта с недопустимым значением i
    }
    catch (int e) {
        cout << "Caught an exception in main: " << e << endl;
    }
}



// class MyType {
//     int i; double d;

//     void handleException() {
//         cout << "Handling exception" << endl;
//     }

// public:

//     MyType(int ii, double dd) try : i(f(ii)), d(dd) {
//         cout << "hello" << endl;
//     }
//     catch (...) {
//         cout << "error" << endl;
//         handleException();
//     }
// };

// int main() {
//     MyType obj(-1, 1.0);
// }