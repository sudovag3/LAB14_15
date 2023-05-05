#include <iostream>

using namespace std;

template <typename T>
class TD;

// Объявление перегруженного оператора << для класса TD
template <typename T>
ostream& operator<<(ostream &s, TD<T> &t);

// Определение класса TD
template <typename T>
class TD{ 
    T x;  
public:
    TD(const T &t): x(t){}    
    // Объявление дружественной функции перегруженного оператора << для класса TD
    friend ostream& operator<<  <T>(ostream &s, TD<T> &t);
    
    // Перегруженный оператор сложения для класса TD
    friend  TD<T> operator+(TD<T> a,  TD<T> b) {
        TD<T> t=a; 
        t.x += b.x; 
        return t;
    }
};

// Определение перегруженного оператора << для класса TD
template <typename T> 
ostream& operator<<(ostream &s, TD<T> &t) {
    return s << t.x;
}

// Функция main
int main() {
    // Создание объектов класса TD
    TD<int> t(5), z(7);
    TD<int> y = z + 1;
    
    // Вывод значения объекта y на экран
    cout << y;
    
    return 0;
}
