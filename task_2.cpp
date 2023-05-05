#include <iostream>

using namespace std;

class A {
public:
    virtual void what() {
        cout << "This is class A" << endl;
    }
};

class B : public A {
public:
    void what() override {
        cout << "This is class B" << endl;
    }
};

int main() {
    try {
        try {
            throw B();
        }
        catch (A &obja) {
            obja.what(); // Выводит "This is class B", так как obja имеет динамический тип B
            throw obja; // Помеченная комментарием строка
        }
    }
    catch (A &obja) {
        obja.what();
    }
}
// Когда мы используем throw; 
// без аргумента, мы "перебрасываем" текущее исключение. 
// В данном случае, это означает, что исключение типа B, 
// которое было сгенерировано оператором throw B(); , будет переброшено во внешний блок catch.