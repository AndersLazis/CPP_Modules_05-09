/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:12:08 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/12 22:25:27 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <algorithm>
#include "includes/Easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <stack>

int main(void) {

       int value_I_want_to_find = 5; // change this value to test
        
    std::cout << YELLOW << "\n -------------- #1 VECTOR TEST  -------------- " << RESET << std::endl;
        std::vector<int> myvector;

        for (size_t i = 0; i < 8; i++)
            myvector.push_back(i);
        std::cout << PURPLE << "my vector contains: " << RESET << std::endl;
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        try
        {
            easyfind(myvector, value_I_want_to_find);
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }

    
    std::cout << YELLOW << "\n --------------- #2 LIST TEST  --------------- " << RESET << std::endl;
        std::list<int> mylist;
        for (size_t i = 0; i < 8; i++)
            mylist.push_back(i);
        std::cout << PURPLE << "my vector contains:" << RESET << std::endl;
        for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        try
        {
            easyfind(mylist, value_I_want_to_find);
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    
    std::cout << YELLOW << "\n -------------- #3 DEQUE TEST  -------------- " << RESET << std::endl;
        std::deque<int> mydeque;
        for (size_t i = 0; i < 8; i++)
            mydeque.push_back(i);

        std::cout << PURPLE << "my queue contains:" << RESET << std::endl;
        for (std::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        try
        {
            easyfind(mydeque, value_I_want_to_find);
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }
    
    return 0;
}
