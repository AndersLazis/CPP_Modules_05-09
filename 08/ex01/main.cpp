/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:12:08 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/08 12:46:18 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <algorithm>
#include "includes/Span.hpp"
#include <vector>
#include <list>
#include <deque>
#include <stack>


/*
====== EXPLANATION OF SPANS =====

numbers: 3_6_9_11_17
spans:    3 3 2  6

*/


int main(void) {
    std::cout << YELLOW << "\n ---------------------- #1 SUBJECT TEST  ---------------------- " << RESET << std::endl;
    try
    {
        Span sp(100000);
        /* Add one by one */
                
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
       // std::cout << sp;
        std::cout << GREEN << "Shortest span:\t[" << sp.shortestSpan() << "]" << RESET << std::endl;
        std::cout << RED <<  "Longest span:\t[" << sp.longestSpan() << "]" << RESET <<  std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }


// std::cout << YELLOW << "\n ---------------------- #2  TEST WITH RANGE ITERATORS ---------------------- " << RESET << std::endl;
//     try
//     {
//         Span sp(10000);

//         /* Add on range */    
        
//         int qty = 10000;
//         std::vector<int> vec(qty);        
//         for (int i = 0; i < qty; i++)
//             vec[i] = i;
            
//         sp.addRange(vec.begin(), vec.end());
//         std::cout << sp;
//         std::cout << GREEN << "Shortest span:\t[" << sp.shortestSpan() << "]" << RESET << std::endl;
//         std::cout << RED <<  "Longest span:\t[" << sp.longestSpan() << "]" << RESET <<  std::endl;
//     }
//     catch(const std::exception & e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
}
