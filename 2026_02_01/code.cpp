/*
Процедурный подход имеет свои проблемы
1. Данные и функции разбросаны
2. Сложно сопровождать
3. Высокая связность кода

Основная идея ООП - объединить данные и логику работы с ними

Минусы ООП:
1. Усложнение кода
2. Накладные расходы
3. Иногда избыточно

Основные принципы ООП:
1. Инкапсуляция - скрытие внутренней реализации

class Account {
private:
  int balance;
public:
  void deposit(int x) {
    balance += x;
  }
}

2. Абстракция - работа с объектом через интерфейс (без раскрытия его внутренней
логики) account.deposit(100);

3. Наследование - создание класса на основе другого класса
class SavingsAccount : public Account {};

4. Полиморфизм - один интерфейс, но разное поведение


Классы и объекты

Класс - это описание собственного типа данных (чертеж)
Объект - это эксземпляр класса

Объявление класса
class Point {
public:
  int x;
  int y;

  void print() const {
    std::cout << x << " " << y << std::endl;
  }
};

Создание объекта
Point p;
p.x = 10;
p.y = 20;
p.print();

Модификаторы доступа
public: - свойства доступные отовсюда
private: (по-умолчанию) - свойства достпные только внутри этого класса
protected: - свойства доступные изнутри этого класса и из его потомков (при
наследовании)



*/

// Создать класс Person
// Поле имя - приватное
// доступ к имени должен быть реализован через методы getName и setName
#include <iostream>
#include <string>

class Person {
private:
  std::string name;

public:
  std::string getName() const { return name; }
  void setName(std::string new_name) { name = new_name; }
};

int main() {
  Person pers; // создание объекта класса Person
  pers.setName("qwer");
  std::cout << pers.getName() << std::endl;
}

/*

Конструктор - это метод, который вызывется при создании объекта
Его свойства:
- вызывается автоматически
- инициализирует объект
- имя совпадает с именем класса
- нет типа возвращаемого значения

Конструктор по-умолчанию:
class A {
public:
  A() {
    std::cout << "default\n";
  }
}
A a;

Конструктор с параметрами:
class Point {
public:
  int x;
  int y;

  Point(int a, int b) {
    x = a;
    y = b;
  }
};
Point p(10, 20);

Перегруженный конструктор:
class Point {
public:
  int x;
  int y;

  Point() {
    x = 0;
    y = 0;
  }
  Point(int a, int b) {
    x = a;
    y = b;
  }
};
Point p; // p(0, 0)

Делегирующий конструктор
class Point {
public:
  int x;
  int y;

  Point(int a, int b) {
    x = a;
    y = b;
  }
  Point() : Point(0, 0) {}
};
Point p; // p(0, 0)


Списки инициализации
- единственный способ инициализировать const поля объекта, ссылки, а так же он
быстрее и корректнее

class Point {
public:
  int x;
  int y;

  Point(int a, int b) : x(a), y(b) {}
};

Деструктор - метод, который вызывается при уничтожении объекта

class A{
public:
  ~A() {
    std::cout << "Destroyed\n";
  }
}

*/
