// void my_func();

// int main() {
  
// }

// void my_func() {
//   std::cout << "Hello world!";
// }

/*

Объявление и определение функций в классах

class MyClass {
int y;  // private
public:
  int x;
  int getX() {
    return x;
  }
};

struct MyClass {
int y; // public
public:
  int x;
  int getX() {
    return x;
  }
};

union MyClass {
public:
  int x;
  int getX() {
    return x;
  }
};

// Объявление функции
// Определение функции

# user.h ---
template <typename T>
class User {
public:
  User(int age);  // Объвеление конструктора
  int getAge() const;  // Объвеление функции класса
  void setAge(int age);  // Объвеление функции класса
  ~User();
  T get() const {
    return value_;
  }
private:
  int age_;
  T value_;
};
---

# user.cpp ---
User::User(int age) : age_(age) {}

int User::getAge() const {
  return age_;
}

void User::setAge(int age) {
  age_ = age;
}

User::~User() {
  std::cout << "Destructor\n";
}
---


// сигнатура функции в определении и объявлении должна точно совпадать
// const, &, && - все должно совпадать

// Определение функции внутри класса имеет место быть, когда функция небольшая
// Функции, определенные внутри класса являются inline (встроенными). 

// Шаблонные функции почти всегда определяют в заголовке

*/

/*

Конструктор копирования

class A {
public:
  A(const A& other);
};

// Такой конструктор создает новый объект на основе предыдущего (копирует его)

A a;
A b = a;  // copy конструктор
A c(a); // copy конструктор
A d{a}; // copy конструктор

void f(A x) {...};
A a;
f(a); // copy конструктор

class Point {
public:
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
  Poin(const Point& other) : x(other.x), y(other.y) {
    std::cout << "Copy\n";
  }
};

Point p1(1, 2);
Point p2 = p1; // copy

// Конструктор копирования есть и по-умолчанию

class Point {
public:
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
  Point(const Point& other) = default;  // эта запись ничего не меняет, просто показываем явно, что используем конструктор копирования по-умолчанию
};
Point p1(1, 2);
Point p2 = p1; // copy

// Копирует все поля поэлементно
// Работает корректно только если нет владения ресурсами

class Buffer {
  int* data;
public:
  Buffer(int n){
    data = new int[n];
  }

  ~Buffer() {
    delete[] data;
  }
};
Buffer b1(16);
Buffer b2 = b1; // data просто скопируется как указатель (и получим UB при попытке повторно очистить память)
// такая ситуация с копированием называется shallow copy

// Можем исправить реализовав свой конструктор копирования (deep copy)
class Buffer {
  int* data;
  size_t size;
  
public:
  Buffer(size_t n) : size(n), data(new int[n]) {}
  Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
    std::copy(other.data, other.data + size, data);
  }

  ~Buffer() {
    delete[] data;
  }
};

// Запрет копирования
class NonCopybale {
public:
  NonCopybale(const NonCopybale&) = delete;
};
NonCopybale a;
NonCopybale b = a; // ошибка компиляции

*/

/*

Константные объекты и функции
const int x = 10;

class Point{
public:
  int x, y;
  void foo() {} // нет const -> не константная
};

const Point p{1, 2};
p.foo(); // ошибка

// const объекты могут использовать только const функции класса

class Point{
public:
  int x, y;
  void foo() const {}
};
const Point p{1, 2};
p.foo(); // ok


// Перегрузка функций по const
class A{
public:
  int x;

  int& get() {return x;}
  const int& get() const {return x;}
};

A a;
const A b;

a.get() = 5;  // non-const
b.get();  // const

// mutable - исключение из правил
// mutable позволяет изменять поле даже в const-функции

class A {
  mutable int value = 0;

public:
  int change() const {
    value = compute();
    return value;
  }
};


// все методы, не меняющие состояние - const
// все геттеры - const
// реализация позволяет работать с const объектами

*/
