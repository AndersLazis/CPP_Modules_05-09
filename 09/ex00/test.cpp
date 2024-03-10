#include <iostream>

int main() {
    float float_num = 123456789.123456789f; // Число с плавающей точкой типа float
    float float_num = float_num; // Преобразование типа float в тип float

    std::cout << "Значение float_num в типе float: " << std::fixed << float_num << std::endl;
    std::cout << "Значение float_num после преобразования в тип float: " << std::fixed << float_num << std::endl;

    return 0;
}