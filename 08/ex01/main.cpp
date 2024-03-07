/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:12:08 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/16 21:00:56 by aputiev          ###   ########.fr       */
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
numbers: 3_6_9_11_17
spans:    3 3 2  6
*/


int main(void) {
    std::cout << YELLOW << "\n ---------------------- #1  TEST  ---------------------- " << RESET << std::endl;
    try
    {
        Span sp(INT_MAX);
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        sp.addManyNumbers(  2000000000, 5);
                        //  2147483647
       // sp.addManyNumbers(100, 20);

       // std::cout << sp;
        std::cout << GREEN << "Shortest span:\t[" << sp.shortestSpan() << "]" << RESET << std::endl;
        std::cout << RED <<  "Longest span:\t[" << sp.longestSpan() << "]" << RESET <<  std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
