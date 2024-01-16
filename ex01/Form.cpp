/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:10 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/16 15:14:23 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "includes/Form.hpp"
#include "includes/Colors.hpp"

/*  ================*= Constructors =*================= */
/* Default */
Form::Form() : _formName("default Form"),                
                _gradeRequiredToSign(MIN_GRADE),
                _gradeRequiredToExecute(MIN_GRADE),
                _isSigned(false)
{
    std::cout << BG_YELLOW << "Form \"" << _formName << "\" with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << " was created" << RESET << std::endl << RESET;
}
/* Constructor with parameters */
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _formName(name),                                                                                
                                                                                _gradeRequiredToSign(gradeToSign),
                                                                                _gradeRequiredToExecute(gradeToExecute),
                                                                               _isSigned(false)
{
    if(gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw Form::GradeTooLowException();
    else if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw Form::GradeTooHighException();
    std::cout << BG_YELLOW << "Form \"" << _formName << "\" with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << " was created"  << RESET << std::endl << RESET;
}
/* Copy constructor */
Form::Form(Form const & source) : _formName(source._formName),
                                    _gradeRequiredToSign(source._gradeRequiredToSign),
                                    _gradeRequiredToExecute(source._gradeRequiredToExecute),
                                    _isSigned(false)
{
    std::cout << BG_YELLOW << "Form copy constructor was called"  << RESET << std::endl << RESET;
   return;
}

/*  ================*=  Destructor: =*================= */

Form::~Form()
{
    std::cout << RESET << BG_RED << "Form \"" << this->_formName << "\" was deleted" << RESET << std::endl << RESET ;
}

/*  ===========*=  Overload "=" operator: =*=========== */

Form & Form::operator=(Form const & source)
{
    std::cout << BG_YELLOW << "Form \"=\" operator overload was called"  << RESET << std::endl << RESET;
    this->_isSigned = source._isSigned;
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << RESET << BG_PURPLE << "Form name: " << form.getFormName() << 
                        " Form is signed: " << form.getIsSigned() <<
                        " Form grade required to sign: " << form.getGradeRequiredToSign() << 
                        " Form grade required to execute: "<< form.getGradeRequiredToExecute() << RESET << std::endl << RESET;
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

const char* Form::GradeTooLowException::what()const throw()
{
    return "Grade of Form is too low";
}

const char* Form::GradeTooHighException::what()const throw()
{
    return "Grade of Form is too high";
}

const char* Form::FormAlreadySignedException::what()const throw()
{
    return "Form is already signed!";
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
        throw Form::GradeTooLowException();
    else if (this->_isSigned)
        throw Form::FormAlreadySignedException();       
    else
       this->_isSigned = true;
    return;
}
