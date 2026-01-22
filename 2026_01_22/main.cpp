#include <iostream>
#include <vector>

/*

#include <vector>

Вектор - это динамический массив, обернутый в класс (для нас это удобно и
безопасно - не надо работать с памятью)

Инициализация:
std::vector<int> v; // пустой
std::vector<int> v(5); // 5 элемнетов - все 0
std::vector<int> v(5, -1); // 5 элементов - все -1
std::vector<int> v = {1, 2, 3, 4, 5};

std::vector<int> v2 = v;  // инициализация копированием
std::vector<int> v2(v.begin() + 1, v.end() - 1); // {2, 3, 4}

Доступ к элементам вектора:
v[i] // без проверки
v.at(i) // с проверкой
v.front() // первый
v.back() // последний
v.data() // указатель на массив

Основные методы:
v.size() // получить размер (кол-во не пустых элементов) вектора
v.capacity() // кол-во элементов, под которые выделено место в векторе на данный
момент v.empty() // проверка на пустоту вектора

v.push_back(val) // добавить элемент в конец
v.emplace_back(val) // добавить элемент в конец создавая объект на месте

v.pop_back() // удаление элемента из конца
v.clear() // очистить вектор

v.insert(pos, val) // вставить новый элемент после позиции
v.erase(pos) // удалить элемент

v.resize(n) // изменить размер вектора, сделав его равным n
v.resize(n, val) // изменить размер вектора, сделав его равным n и заполнить
значением val

v.reserve(n) // разезервировать память под n элементов

Итераторы:
std::vector<int>::iterator
std::vector<int>::const_iterator
std::vector<int>::reverse_iterator

v.begin() // итератор на начало вектора (0-й элемент)
v.cbegin() // то же самое, но const_iterator

v.end() // итератор на элемент после последнего
v.cend() // итератор на элемент после последнего, но const_iterator

v.rbegin() // итератор на начало вектора с точки зрения reverse_iterator (на
последний элемент) v.rend() // итератор на элемент после последнего с точки
зрения reverse_iterator (на элемент перед первым)

Инвалидация итераторов - когда итератор указывает на уже не существующий элемент

Инвалидацию могут вызывать методы:
v.push_back
v.insert
v.erase
v.resize - при увеличении
v.reserve - если значение больше текущей capacity

Как быть с инвалидированными итераторами? Не использовать их => не храним
итераторы дольше одной операции

Проход по вектору в цикле

for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
  std::cout << *it << std::endl;
}

for(auto& el: v) {
  std::cout << el << std::endl;
}
*/

// Задача 1
// Создать вектор из 10 элементов со значением 7 тремя разными способами
std::vector<int> v(10, 7);
std::vector<int> v2 = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
std::vector<int> v3 = v;

// std::vector<int> v(10, 7); // 10 семерок
// std::vector<int> v{10, 7}; // 10, 7

// Задача 2
// Инициализировать вектор и вывести все его элементы в консоль в обратном
// порядке (через цикл)

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  for (int i = v.size() - 1; i >= 0; --i) {
    std::cout << v.at(i) << " ";
  }
  std::cout << std::endl;
  for (std::vector<int>::iterator it = v.end() - 1; it != v.begin() - 1; --it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  for (std::vector<int>::reverse_iterator iter = v.rbegin(); iter != v.rend(); ++iter) {
    std::cout << *iter << " ";
  }
  
}



// size_t - беззнаковый тип
