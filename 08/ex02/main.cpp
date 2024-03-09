/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:12:08 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/08 18:45:56 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/MutantStack.hpp"
#include <stack>
#include <list>
#include <vector>
#include <iostream>

/*
|17|
|5|

|5| =>  size=1

|0|
|737|
|5|
|3|
|5|


|737|<- ite
|5|
|3|
|5|<--- it

*/
    
int main()
{
    
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// std::cout << YELLOW << "\n -------------- #1 SUBJECT TEST  -------------- " << RESET << std::endl;

//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3); mstack.push(5);
//     mstack.push(737);
//     //[...] mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it; 
//     }
//     std::stack<int> s(mstack);

// std::cout << YELLOW << "\n -------------- #1 SUBJECT REFERENCE LIST PRINT-OUT  -------------- " << RESET << std::endl;

//     std::list<int>standart_list;
//     standart_list.push_back(5);
//     standart_list.push_back(17);
//     std::cout << standart_list.back() << std::endl;
//     standart_list.pop_back();
//     std::cout << standart_list.size() << std::endl;
//     standart_list.push_back(3);
//     standart_list.push_back(5);
//     standart_list.push_back(737);
//     //[...] standart_list.push_back(0);
//     std::list<int>::iterator itlist = standart_list.begin();
//     std::list<int>::iterator itelist = standart_list.end();
//     ++itlist;
//     --itlist;
//     while (itlist != itelist)
//     {
//         std::cout << *itlist << std::endl;
//         ++itlist; 
//     }
//     std::cout << std::endl;
 
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

std::cout << RED << "\n -------------- #2 STACK-VECTOR TEST  -------------- " << RESET << std::endl;

    MutantStack<std::string, std::vector<std::string> > mstack;
    mstack.push("one");
    mstack.push("two");
    mstack.push("three");
    mstack.push("four");
    
    std::cout << "show top: " << mstack.top() << std::endl;
    mstack.pop(); //cut-out "four"
    std::cout << "show size: "<< mstack.size() << std::endl;

    /* ============================= print iterators ============================= */
        std::cout << RED << "\n -------------- #2 print iterators -------------- " << RESET << std::endl;
        MutantStack<std::string, std::vector<std::string> >::const_reverse_iterator it = mstack.rbegin();
        MutantStack<std::string, std::vector<std::string> >::const_reverse_iterator ite = mstack.rend();
        std::cout << BLUE << "reverse print:" << RESET << std::endl;
        while(it != ite)
        {
            std::cout << "reverse iterator: " << *it << std::endl;
            ++it;
        } 
        MutantStack<std::string, std::vector<std::string> >::const_iterator itc = mstack.cbegin();
        MutantStack<std::string, std::vector<std::string> >::const_iterator itec = mstack.cend();
        std::cout << BLUE << "normal print:" << RESET << std::endl;
        while(itc != itec)
        {
            std::cout << "const iterator: " << *itc << std::endl;
            ++itc;
        }  
    /* ============================================================================ */
    std::cout << BLUE << "stack-style print:" << RESET << std::endl;
    while(mstack.empty() == false)
    {
        std::cout << mstack.top() << std::endl;
        mstack.pop();
    }

std::cout << RED << "\n -------------- #2 STACK BY VECTOR REFERENCE LIST PRINT-OUT -------------- " << RESET << std::endl;

    std::stack< std::string, std::vector<std::string> > standart_stack_by_vector;
    standart_stack_by_vector.push("one");
    standart_stack_by_vector.push("two");
    standart_stack_by_vector.push("three");
    standart_stack_by_vector.push("four");
    
    std::cout << "show top: " << standart_stack_by_vector.top() << std::endl;
    standart_stack_by_vector.pop(); //cut-out "four"
    std::cout << "show size: "<< standart_stack_by_vector.size() << std::endl;

    while (standart_stack_by_vector.empty() == false)
    {
        std::cout << standart_stack_by_vector.top() << std::endl;
        standart_stack_by_vector.pop();
    }   
    /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    
    return 0;
}


