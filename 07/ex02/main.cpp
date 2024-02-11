/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:52:14 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/09 22:19:57 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Array.hpp"
#include <string>

int main(int ac, char **av)
{   
 
    if(ac != 2)
        Array<int> a;
    else
    {
        int n = std::atol(av[1]);
        Array<int> b(n);
        std::cout << "size " << b.size() << std::endl;
        b[2] = 42;
        std::cout << "b[2] " << b[2] << std::endl;
        Array<int> c(b);
        Array<int> d = c;
        std::cout << "c[2] " << c[2] << std::endl;
        c[2] = 21;
        std::cout << "c[2] " << c[2] << std::endl;
        std::cout << "d[2] " << d[2] << std::endl;
    }
    

    return 0; 
}

// #include <iostream>


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }