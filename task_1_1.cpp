// В данном варианте мы используем отдельный параметр шаблона U для функции сложения operator+. 
// Это значит, что функция operator+ будет работать независимо от параметра шаблона класса T. 
// Это позволяет определить операцию сложения для объектов класса TD с разными типами данных.

// Важно отметить, что в данном случае мы должны явно указать, что функция operator+ 
// является шаблонной функцией для класса TD. Для этого используется синтаксис operator+<>. 
// Это позволяет компилятору корректно обрабатывать и выводить функцию сложения.


#include <iostream>

using namespace std;

template <typename T>
class TD;

template <typename T>
ostream& operator<<(ostream &s, TD<T> &t);

template <typename U>
TD<U> operator+(TD<U> a,  TD<U> b);

template <typename T>
class TD{ 
    T x;  
public:
    TD(const T &t): x(t){}    
    friend ostream& operator<<  <T>(ostream &s, TD<T> &t);
    template <typename U>
    friend TD<U> operator+<>(TD<U> a,  TD<U> b);
};

template <typename T> 
ostream& operator<<(ostream &s, TD<T> &t) {
    return s << t.x;
}

template <typename U>
TD<U> operator+(TD<U> a,  TD<U> b) {
    TD<U> t=a; 
    t.x += b.x; 
    return t;
}

int main() {
    TD<int> t(5), z(7);
    TD<int> y = z + 1;
    
    cout << y;
    
    return 0;
}
