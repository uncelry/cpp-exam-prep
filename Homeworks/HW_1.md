# ДЗ к занятию #2

---

### **1️⃣ Задание — литералы, типы и вывод**

Создай три переменные разных типов:

* `int`
* `double`
* `char`

Присвой им значения **через литералы**, затем:

1. создай выражение, где `int` и `double` участвуют вместе
2. выведи результат вместе с поясняющим текстом
3. выведи символ из `char` как символ и как его числовой код

### Решение 
```cpp
    #include <iostream>

    int main() {
        int a = 12;
        double b = 1.23;
        char c = 'A';
        double result = a + b;
        std::cout << "Результат выражения: " << result << std::endl;
        std::cout << "Символ: " << c << ", код: " << (int)c << std::endl;
        return 0;
    }
```

---

### **2️⃣ Задание — const + выражения + форматирование**

Создай:

* константу `TAX = 0.13`
* переменную `salary = 45678.9`

Найди:

* сумму налога
* «чистую» зарплату после вычета

Выведи:

* с точностью 2 знака после запятой
* красиво, с подписями

### Решение 
```cpp
    #include <iostream>
    #include <iomanip>

    int main() {
        const double Tax = 0.13;
        double Salary = 45678.9;
        double taxAmount = Salary * Tax;
        double leftSalary = Salary - taxAmount;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Налог: " << taxAmount << std::endl;
        std::cout << "Чистая зарплата: " << leftSalary << std::endl;
        return 0;
    }
```

---

### **3️⃣ Задание — логические, сравнения, составные операторы**

Есть переменная:

```
int x = 15;
```

Сделай:

1. увеличь `x` на 10 через `+=`
2. проверь:

* больше ли `x` 20
* находится ли `x` в диапазоне 10–40
* НЕ равен ли он 25

Выведи результаты (true / false как 1 / 0).

### Решение 
```cpp
    #include <iostream>

    int main() {
        int x = 15;
        x += 10;
        bool condition1 = x > 20;
        bool condition2 = (x >= 10) && (x <= 40);
        bool condition3 = x != 25;
        std::cout << condition1 << std::endl;
        std::cout << condition2 << std::endl;
        std::cout << condition3 << std::endl;
        return 0;
    }
```

---

### **4️⃣ Задание — пространство имён + несколько сущностей**

Создай пространство имён `Config`, в нём:

* константу `APP_NAME`
* целочисленную переменную `version`
* функцию, которая выводит оба значения

В `main()` вызови функцию.

### Решение 
```cpp
    #include <iostream>
    #include <string> 

    namespace Config {
        const std::string APP_NAME = "MyApp";
        int version = 2;

        void printInfo() {
            std::cout << "App: " << APP_NAME << ", Version: " << version << std::endl;
        }
    }
    int main() {
        Config::printInfo();
        return 0;
    }
```

---

### **5️⃣ Задание — структура программы, объявления и определения**

Сделай программу, где:

* есть `#include <iostream>`
* **сначала объявлена функция** `printInfo()`
* потом определена **после main**
* в `main()` она вызывается
* внутри функции идёт вывод `"Function works!"`

Используй комментарии, чтобы пояснить структуру.

### Решение 
```cpp
    #include <iostream>

    void printInfo(); // Объявление функции
    int main() {
        printInfo(); // вызов функции
        return 0;
    }
    void printInfo() {
        std::cout << "Function works!"; // Определение функции
    }
```
---
