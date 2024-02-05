/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:04:50 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/05 14:54:34 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"
#include <iostream>

#include <ctime>

Base* generate(void)
{
      
    static unsigned int seed = 12345;
    seed = (seed * 1103515245 + 12345) % 2147483647;
    int id= seed % 100;
    //std::cout << "Time: " << time << std::endl;
    
    Base *basePtr = NULL;
    if (id%3 == 1)
        basePtr = new A;
    else if(id%3 == 2)
         basePtr = new B;
    else 
         basePtr = new C;
    return basePtr;
}

void identify(Base* p)
{
    
    if(dynamic_cast<A*>(p))
        std::cout << GREEN << "A" << RESET << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << GREEN << "B" << RESET << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << GREEN << "C" << RESET << std::endl;
    else
        std::cout << "Unknown" << std::endl;    
}

void identify(Base& p)
{
    try
    {
        A& ref = dynamic_cast<A&>(p);
        std::cout << GREEN << "A" << RESET << std::endl;
        (void)ref;   
    }
    catch(const std::bad_cast& e)
    {
        try
        {
            B& ref = dynamic_cast<B&>(p);
            std::cout << GREEN << "B" << RESET << std::endl;
            (void)ref; 
        }
         catch(const std::bad_cast& e)
        {
             try
            {
                C& ref = dynamic_cast<C&>(p);
                std::cout << GREEN << "C"  << RESET << std::endl;
                (void)ref;
            }
             catch(const std::bad_cast& e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }        
   }
}