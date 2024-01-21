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
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

/*  ================*= Constructors =*================= */

Intern::Intern()
{
    std::cout << GREEN << "Intern was created\n" << RESET;
}

Intern::Intern(Intern const & source)
{
    if(this == &source)
        return ;
    std::cout << YELLOW << "Intern copy constructor was called \n" << RESET;
}

/*  ================*=  Destructor: =*================= */

Intern::~Intern()
{
    std::cout << RED << "Intern was deleted\n" << RESET;
}

/*  ===========*=  Overload "=" operator: =*=========== */

Intern & Intern::operator=(Intern const & source)
{
    if(this == &source)
        return *this;
    std::cout << YELLOW << "Intern \"=\" operator overload was called \n" << RESET;
    return *this;
}

/*  =================*=  Functions: =*================= */

    AForm* createFormSchrubbery(const std::string &formTarget)
    {
        return new ShrubberyCreationForm(formTarget);        
    }
    
    AForm* createFormRobotomy(const std::string &formTarget)
    {
        return new RobotomyRequestForm(formTarget);
    }

    AForm* createFormPresidential(const std::string &formTarget)
    {
        return new PresidentialPardonForm(formTarget);
    }

    AForm*   Intern::makeForm(const std::string formName, const std::string formTarget)
    {
        enum formType {SCHRUBBERY, ROBOTOMY, PARDON};
           std::string formNames[4] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm", ""};
            AForm* (*formPtr[4])(const std::string&);
           // formPtr = createFormSchrubbery;
            formPtr[SCHRUBBERY] = createFormSchrubbery;
            formPtr[ROBOTOMY] = createFormRobotomy;
            formPtr[PARDON] = createFormPresidential;
                        
            for (int i = 0; i < 4; ++i) 
            {
                if (formNames[i] == "")
                {
                    throw std::invalid_argument("Invalid form name");
                    break;
                }
                if (formNames[i] == formName)
                {
                    std::cout << PURPLE << "Intern creates form : " << formNames[i] << " The form applied to: " <<  formTarget << std::endl;
                    return formPtr[i](formTarget);
                }
            }
        return NULL;
    }