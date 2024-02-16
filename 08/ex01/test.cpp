#include <iostream>
#include <vector>
#include <numeric> // Для std::adjacent_difference
#include <iostream>
#include <vector>
#include <numeric> // Для std::adjacent_difference

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(9);
    //vec.push_back(9);

    std::vector<int> diff(vec.size());

    // Вычисляем разности между соседними элементами и сохраняем результат в diff
    std::adjacent_difference(vec.begin(), vec.end(), diff.begin());

    // Выводим результаты
    std::cout << "Исходный вектор: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Разности между соседними элементами: ";
    for (int i = 0; i < diff.size(); ++i) {
        std::cout << diff[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
