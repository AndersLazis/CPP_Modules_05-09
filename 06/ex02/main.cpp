/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:52:14 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/06 17:33:24 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"
#include <iostream>
#include <unistd.h>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    
    for (int i = 0; i < 5; i++)
    {
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);
        std::cout  << std::endl;
        if(ptr)
            delete ptr;
    }

    // C* Cptr = new C;
    // identify(*Cptr);
    return 0;   
}
