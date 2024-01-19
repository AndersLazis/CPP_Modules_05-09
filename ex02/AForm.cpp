/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:10 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/18 11:26:08 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "includes/AForm.hpp"
#include "includes/Colors.hpp"

/*  ================*= Constructors =*================= */
/* Default */
AForm::AForm() : _formName("default Form"),                
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
AForm::AForm(Form const & source) : _formName(source._formName),
                                    _gradeRequiredToSign(source._gradeRequiredToSign),
                                    _gradeRequiredToExecute(source._gradeRequiredToExecute),
                                    _isSigned(false)
{
    std::cout << BG_YELLOW << "AForm copy constructor was called"  << RESET << std::endl << RESET;
}

/*  ================*=  Destructor: =*================= */

Form::~Form()
{
    std::cout << RESET << BG_RED << "AForm \"" << this->_formName << "\" was deleted" << RESET << std::endl << RESET ;
}

/*  ===========*=  Overload "=" operator: =*=========== */

AForm & AForm::operator=(AForm const & source)
{   if(this == &source)
        return *this;
    //nothing to assign in this class
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << RESET << BG_GREEN << "AForm name: " << form.getFormName() << 
                        " AForm is signed: " << form.getIsSigned() <<
                        " AForm grade required to sign: " << form.getGradeRequiredToSign() << 
                        " AForm grade required to execute: "<< form.getGradeRequiredToExecute() << RESET << std::endl << RESET;
    return os;
}

/*  =================*=  Methods: =*================= */

std::string const Form::getFormName() const
{
    return this->_formName;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGradeRequiredToSign() const
{
    return this->_gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
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

const char* AForm::AFormAlreadySignedException::what()const throw()
{
    return "Error: AForm is already signed!";
}

const char* AForm::AFormUnsignedException::what()const throw()
{
    return "Error: AForm is unsigned!";
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
        throw AForm::GradeTooLowException();
    else if (this->_isSigned)
        throw AForm::AFormAlreadySignedException();       
    else
       this->_isSigned = true;
    return;
}



