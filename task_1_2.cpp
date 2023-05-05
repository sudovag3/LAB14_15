// Во втором варианте мы предварительно объявляем шаблон класса TD и шаблон функции operator+. 
// Это позволяет нам использовать одинаковый параметр шаблона T для класса и функции сложения. 
// В этом случае функция operator+ будет работать только с объектами класса TD, которые имеют одинаковый тип данных.

// Этот подход делает код более строгим и непосредственно связывает функцию operator+ с классом TD. 
// Здесь нет необходимости использовать operator+<>, так как компилятор автоматически определит, 
// что это шаблонная функция для класса TD.

#include <iostream>

using namespace std;

template <typename T>
class TD;

template <typename T>
ostream& operator<<(ostream &s, TD<T> &t);

template <typename T>
TD<T> operator+(TD<T> a,  TD<T> b);

template <typename T>
class TD{ 
    T x;  
public:
    TD(const T &t): x(t){}    
    friend ostream& operator<<  <T>(ostream &s, TD<T> &t);
    friend TD<T> operator+ <T>(TD<T> a,  TD<T> b);
};

template <typename T> 
ostream& operator<<(ostream &s, TD<T> &t) {
    return s << t.x;
}

template <typename T>
TD<T> operator+(TD<T> a,  TD<T> b) {
    TD<T> t=a; 
    t.x += b.x; 
    return t;
}

int main() {
    TD<int> t(5), z(7);
    TD<int> y = z + 1;
    
    cout << y;
    
    return 0;
}
