/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:02:46 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/17 13:57:55 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Colors.hpp"
  

/*  ================*= Constructors =*================= */
/* Default */
ShrubberyCreationForm::ShrubberyCreationForm() : _formName("default ShrubberyCreationForm"),                
                _gradeRequiredToSign(145),
                _gradeRequiredToExecute(137),
                _isSigned(false),
                _target("default target")
{
    std::cout << BG_YELLOW << "ShrubberyCreationForm \"" << _formName << "\" with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << " was created" << RESET << 
        " and target " << _target << std::endl << RESET;
}
/* Constructor with parameters */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :    _formName("Shrubbery form"),                                                                                
                                                                        _gradeRequiredToSign(145),
                                                                        _gradeRequiredToExecute(137),
                                                                        _isSigned(false),
                                                                        _target(target)
{
    std::cout << BG_YELLOW << "ShrubberyCreationForm \"" << _formName << "\" with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << " was created"  << RESET << std::endl << RESET;
}
/* Copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & source) : _formName(source._formName),
                                    _gradeRequiredToSign(source._gradeRequiredToSign),
                                    _gradeRequiredToExecute(source._gradeRequiredToExecute),
                                    _isSigned(false),
                                    _target(source._target)
{
    std::cout << BG_YELLOW << "ShrubberyCreationForm copy constructor was called"  << RESET << std::endl << RESET;
   return;
}

/*  ================*=  Destructor: =*================= */

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << RESET << BG_RED << "ShrubberyCreationForm \"" << this->_formName << "\" was deleted" << RESET << std::endl << RESET ;
}

/*  ===========*=  Overload "=" operator: =*=========== */

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & source)
{
    std::cout << BG_YELLOW << "ShrubberyCreationForm \"=\" operator overload was called"  << RESET << std::endl << RESET;
    this->_isSigned = source._isSigned;
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& ShrubberyCreationForm)
{
    os << RESET << BG_GREEN << "ShrubberyCreationForm name: " << ShrubberyCreationForm.getShrubberyCreationFormName() << 
                        " ShrubberyCreationForm is signed: " << ShrubberyCreationForm.getIsSigned() <<
                        " ShrubberyCreationForm grade required to sign: " << ShrubberyCreationForm.getGradeRequiredToSign() << 
                        " ShrubberyCreationForm grade required to execute: "<< ShrubberyCreationForm.getGradeRequiredToExecute() << 
                        " ShrubberyCreationForm target: " << ShrubberyCreationForm._target << RESET << std::endl << RESET;
    return os;
}

/*  =================*=  Methods: =*================= */

std::string const ShrubberyCreationForm::getShrubberyCreationFormName() const
{
    return this->_formName;
}

bool ShrubberyCreationForm::getIsSigned() const
{
    return this->_isSigned;
}

int ShrubberyCreationForm::getGradeRequiredToSign() const
{
    return this->_gradeRequiredToSign;
}

int ShrubberyCreationForm::getGradeRequiredToExecute() const
{
    return this->_gradeRequiredToExecute;
}

const char* ShrubberyCreationForm::GradeTooLowException::what()const throw()
{
    return "Error: Grade is too low";
}

const char* ShrubberyCreationForm::GradeTooHighException::what()const throw()
{
    return "Error: Grade is too high";
}

const char* ShrubberyCreationForm::ShrubberyCreationFormAlreadySignedException::what()const throw()
{
    return "Error: Form is already signed!";
}

const char* ShrubberyCreationForm::ShrubberyCreationFormANotSignedException::what()const throw()
{
    return "Error: Form is not signed yet !";
}

void ShrubberyCreationForm::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
        throw ShrubberyCreationForm::GradeTooLowException();
    else if (this->_isSigned)
        throw ShrubberyCreationForm::ShrubberyCreationFormAlreadySignedException();       
    else
       this->_isSigned = true;
    return;
}

void ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat) const
{   
   
    if (bureaucrat.getGrade() > this->_gradeRequiredToExecute)
        throw ShrubberyCreationForm::GradeTooLowException();
    else if (!this->_isSigned)
        throw ShrubberyCreationForm::ShrubberyCreationFormNotSignedException();
    else
    {
        std::string filename = this->_target + "_shrubbery";
        std::ofstream outputFile(filename.c_str(), std::ios::app);
        if(!outputFile)
            throw std::exception("Error: File cannot be opened");
            
        outputFile << "   ^   \n";
        outputFile << "  ^^^  \n";
        outputFile << " ^^^^^ \n";
        outputFile << "^^^^^^^\n";
        outputFile << "   |   \n";

        outputFile.close();

        std::cout << "New ASCII pine tree added to file \"" << filename << "\".\n";
    }
    return;
}
