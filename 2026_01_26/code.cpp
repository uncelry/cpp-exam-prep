#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// v.size() - размер вектора
// v.capacity() - выделенная память
// v.push_back() - добавить элемент в конец вектора

// v.push_back() - может инвалидировать итераторы/указатели/ссылки

// v.begin() - итератор на начало
// v.end() - итератор на начало

// Ввод и вывод векторов
// int main() {
//   // Ввод если известно кол-во элементов
//   int n;
//   std::cin >> n;

//   std::vector<int> v(n);
//   for (int i = 0; i < n; ++i) {
//     std::cin >> v[i];
//   }
// }

// int main() {
//   // Ввод если кол-во не известно
//   std::vector<int> v;
//   int x;
//   while (std::cin >> x) {
//     v.push_back(x);
//   }
// }

// int main() {
//   std::vector<int> v = {1, 2, 3};

//   // index
//   for (size_t i = 0; i < v.size(); ++i) {
//     std::cout << v[i] << " ";
//   }

//   // range based for
//   for (int x: v) {
//     std::cout << x << " ";
//   }

//   // iterator
//   for (auto it = v.begin(); it != v.end(); ++it) {
//     std::cout << *it << " ";
//   }
// }

// Считать n чисел с консоли, и вывести в консоль в обратном порядке
// Считываем из консоли числа в вектор, после чего выводим вектор в консоль
// через reverse_iterator v.rbegin() v.rend()

// Вектор и алгоритмы STL

// Алгоритмы STL
// #include <algorithm>

// Сами алгоритмы:
// - не знают что такое vector (или любая другая структура данных)
// - они могут работать с любым объектом, у которого реализованы определенные
// итераторы
// - универсальны
// - работают через итераторы

// int main() {
//   std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};

//   // Сортировка
//   std::sort(v.begin(), v.end()); // по возрастанию
//   std::sort(v.begin(), v.end(), std::greater<int>()); // по убыванию

//   // Поиск
//   auto it = std::find(v.begin(), v.end(), 5);
//   if (it != v.end()) {
//     std::cout << "Found!";
//   }

//   // Подсчет кол-ва значений
//   int cnt = std::count(v.begin(), v.end(), 6);

//   // Подсчет элементов, удовлетворяющих условию
//   int even =
//       std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });

//   // Удаление элементов (на самом деле - перемещение в конец)
//   std::remove(v.begin(), v.end(),
//               5); // НЕ удаляет, а перемещает все элементы со значение 5 в
//               конец

//   // Идиома erase-remove
//   v.erase(std::remove(v.begin(), v.end(), 5), v.end());

//   // Изменение элементов
//   std::transform(v.begin(), v.end(), v.begin(), [](int x) { return x * x; });

//   // Посчитать сумму всех элементов
//   int sum = std::accumulate(v.begin(), v.end(), 0);
// }

// Векторы строк
// int main() {
//   int n;
//   std::cin >> n;
//   std::cin.ignore();

//   std::vector<std::string> v(n);
//   for (std::string& s : v) {
//     std::getline(std::cin, s);
//   }

//   v[0].size();
// }

// Двумерные векторы (матрицы)

// int main() {
//   // NxM; N - строк, M - столбцов
//   const int N = 3;
//   const int M = 5;
//   std::vector<std::vector<int>> matrix(N, std::vector<int>(M));

//   // Доступ к элементам
//   // matrix[i][j]; i - номер строки, j - номер столбца

//   // Ввод и вывод
//   for (int i = 0; i < N; ++i) {
//     for (int j = 0; j < M; ++j) {
//       std::cin >> matrix[i][j];
//     }
//   }

//   for (int i = 0; i < matrix.size(); ++i) {
//     for (int j = 0; j < matrix[i].size(); ++j) {
//       std::cout << matrix[i][j];
//     }
//   }
// }

// Считать с консоли N и M, считать для них значения с консоли, и заполнить ими
// матрицу. Найти строку с максимальной суммой элементов и вывести ее номер и
// сумму в консоль
int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  int max_sum = -1e9; // Лучше использовать не магическое значение, а минимально
                      // возможное значение для данного типа
  int max_i = 0;

  for (int i = 0; i < n; ++i) {
    // int sum = 0;
    int sum = std::accumulate(matrix[i].begin(), matrix[i].end(), 0);
    // for (int j = 0; j < m; ++j) {
    //   sum += matrix[i][j];
    // }

    // max_sum = std::max({max_sum, sum});
    
    if (sum > max_sum) {
      max_sum = sum;
      max_i = i;
    }
  }

  std::cout << max_sum << " " << max_i;
}
