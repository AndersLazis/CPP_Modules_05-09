/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:10 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/18 10:51:24 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "includes/Bureaucrat.hpp"
#include "includes/Colors.hpp"

/*  ================*= Constructors =*================= */

Bureaucrat::Bureaucrat() : _Name("noname bureaucrat"), _Grade(_minGrade)
{
    this->_checkGrade(_Grade);
    std::cout << GREEN << "Bureaucrat \"" << _Name << "\" was created\n" << RESET;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name), _Grade(grade) 
{
    std::cout << GREEN << "Bureaucrat \"" << name << "\" was created\n" << RESET;
    this->_checkGrade(_Grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const & source) : _Name(source._Name)
{
    std::cout << BG_GREEN << "Bureaucrat copy constructor was called" << RESET << std::endl;
    *this = source;
}

/*  ================*=  Destructor: =*================= */

Bureaucrat::~Bureaucrat()
{
    std::cout << RED << "Bureaucrat \"" << this->_Name << "\" was deleted\n" << RESET;
}

/*  ===========*=  Overload "=" operator: =*=========== */

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & source)
{
    std::cout << YELLOW << "Bureaucrat \"=\" operator overload was called \n" << RESET;
    if(this != &source)
    {
        this->_Grade = source._Grade;
    }
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << PURPLE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl << RESET;
    return os;
}

/*  =================*=  Functions: =*================= */

std::string const Bureaucrat::getName() const
{
    return this->_Name;
}

int Bureaucrat::getGrade() const
{
    return this->_Grade;
}

void Bureaucrat::incrementGrade()
{   
    if(this->_Grade - 1 < this->_maxGrade)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_Grade--;    
    std::cout << BLUE << "Level of " << this->_Name << " was increased to " << this->_Grade << std::endl << RESET;
}

void Bureaucrat::decrementGrade()
{   
    if(this->_Grade + 1 > this->_minGrade)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_Grade++;    
    std::cout << BLUE << "Level of " << this->_Name << " was decreased to " << this->_Grade << std::endl << RESET;
}

void Bureaucrat::_checkGrade(int grade)
{
    if(grade < this->_maxGrade)
        throw Bureaucrat::GradeTooHighException();
    else if(grade > this->_minGrade)
        throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what()const throw()
{
    return "Grade of bureaucrat is too high!";
}

const char* Bureaucrat::GradeTooLowException::what()const throw()
{
    return "Grade of bureaucrat is too low!";
}

void Bureaucrat::signForm(Form & form) const
{
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}