#include <iostream>
#include <list>

#include <list>

template <typename T>
void insertionSort(std::list<T>& lst) {
    if (lst.empty() || lst.size() == 1)
        return;

    typename std::list<T>::iterator it, j;

    for (it = lst.begin(); it != lst.end(); it++) {
        T key = *it;
        j = it;

        // Перемещаем элементы списка, которые больше ключа,
        // вверх по позициям
        while (j != lst.begin() && *(--j) > key) {
            *it = *j;
        }

        // Вставляем ключ на правильную позицию
        *it = key;
    }
     for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> myList;
    // Заполняем список случайными числами
    myList.push_back(3);
    myList.push_back(1);
    myList.push_back(5);
    myList.push_back(2);
    myList.push_back(4);

    // Сортируем список
    insertionSort(myList);

    // Выводим отсортированный список
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
