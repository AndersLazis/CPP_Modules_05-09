/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:10 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/17 12:51:30 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "includes/AForm.hpp"
#include "includes/Colors.hpp"

/*  ================*= Constructors =*================= */
/* Default */
AForm::AForm() : _formName("default AForm"),                
                _gradeRequiredToSign(MIN_GRADE),
                _gradeRequiredToExecute(MIN_GRADE),
                _isSigned(false)
{
    std::cout << BG_YELLOW << "AForm \"" << _formName << "\" with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << " was created" << RESET << std::endl << RESET;
}
/* Constructor with parameters */
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _formName(name),                                                                                
                                                                                _gradeRequiredToSign(gradeToSign),
                                                                                _gradeRequiredToExecute(gradeToExecute),
                                                                               _isSigned(false)
{
    if(gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw AForm::GradeTooLowException();
    else if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw AForm::GradeTooHighException();
    std::cout << BG_YELLOW << "AForm \"" << _formName << "\" with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << " was created"  << RESET << std::endl << RESET;
}
/* Copy constructor */
AForm::AForm(AForm const & source) : _formName(source._formName),
                                    _gradeRequiredToSign(source._gradeRequiredToSign),
                                    _gradeRequiredToExecute(source._gradeRequiredToExecute),
                                    _isSigned(false)
{
    std::cout << BG_YELLOW << "AForm copy constructor was called"  << RESET << std::endl << RESET;
   return;
}

/*  ================*=  Destructor: =*================= */

AForm::~AForm()
{
    std::cout << RESET << BG_RED << "AForm \"" << this->_formName << "\" was deleted" << RESET << std::endl << RESET ;
}

/*  ===========*=  Overload "=" operator: =*=========== */

AForm & AForm::operator=(AForm const & source)
{
    std::cout << BG_YELLOW << "AForm \"=\" operator overload was called"  << RESET << std::endl << RESET;
    this->_isSigned = source._isSigned;
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << RESET << BG_GREEN << "AForm name: " << AForm.getFormName() << 
                        " AForm is signed: " << AForm.getIsSigned() <<
                        " AForm grade required to sign: " << AForm.getGradeRequiredToSign() << 
                        " AForm grade required to execute: "<< AForm.getGradeRequiredToExecute() << RESET << std::endl << RESET;
    return os;
}

/*  =================*=  Methods: =*================= */

std::string const AForm::getFormName() const
{
    return this->_formName;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeRequiredToSign() const
{
    return this->_gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const
{
    return this->_gradeRequiredToExecute;
}

const char* AForm::GradeTooLowException::what()const throw()
{
    return "Error: Grade is too low";
}

const char* AForm::GradeTooHighException::what()const throw()
{
    return "Error: Grade is too high";
}

const char* AForm::FormAlreadySignedException::what()const throw()
{
    return "Error: Form is already signed!";
}

const char* AForm::FormNotSignedException::what()const throw()
{
    return "Error: Form is not signed yet !";
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
        throw AForm::GradeTooLowException();
    else if (this->_isSigned)
        throw AForm::FormAlreadySignedException();       
    else
       this->_isSigned = true;
    return;
}

void AForm::execute(Bureaucrat const & bureaucrat) const
{   
    if (bureaucrat.getGrade() > this->_gradeRequiredToExecute)
        throw AForm::GradeTooLowException();
    else if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    else
        this->beExecuted();
    return;
}
