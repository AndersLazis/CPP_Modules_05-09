/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:10 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/20 20:49:32 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "includes/Intern.hpp"
#include "includes/Colors.hpp"

/*  ================*= Constructors =*================= */

Intern::Intern()
{
    std::cout << GREEN << "Intern was created\n" << RESET;
}

Intern::Intern(Intern const & source)
{
    std::cout << YELLOW << "Intern copy constructor was called \n" << RESET;
}

/*  ================*=  Destructor: =*================= */

Intern::~Intern()
{
    std::cout << RED << "Intern \"" << this->_Name << "\" was deleted\n" << RESET;
}

/*  ===========*=  Overload "=" operator: =*=========== */

Intern & Intern::operator=(Intern const & source)
{
    std::cout << YELLOW << "Intern \"=\" operator overload was called \n" << RESET;
    return *this;
}

/*  =================*=  Functions: =*================= */

  AForm*   Intern::makeForm(const std::string formName, const std::string formTarget)
{
    try
    {   
        
        std::cout << PURPLE << "Intern creates form :" << formName << " applied to " <<  formTarget << std::endl;
    }
    
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

