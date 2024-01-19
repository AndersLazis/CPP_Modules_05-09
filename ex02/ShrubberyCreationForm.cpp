/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:23:30 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/20 00:06:17 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "includes/AForm.hpp"
#include "includes/Colors.hpp"

/*  ================*= Constructors =*================= */
/* Default */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm default", 145, 137),
                                                _target("default")
{
    std::cout << BG_YELLOW << "ShrubberyCreationForm \"" << this->_formName << "\" with grade required to sign" << 
        this->_gradeRequiredToSign << " and grade require to execute " << this->_gradeRequiredToExecute << "and target: " <<
         _target << " was created" << RESET << std::endl << RESET;
}

/* Constructor with parameters */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm default", 145, 137),
                                                                    _target(target)
{    
    std::cout << BG_YELLOW << "ShrubberyCreationForm \"" << _formName << "\" with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << << "and target: " << 
        _target << " was created" << RESET << std::endl;
}
/* Copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & source) : AForm(_formName(source._formName),
                                                                                     _gradeRequiredToSign(source._gradeRequiredToSign),
                                                                                     _gradeRequiredToExecute(source._gradeRequiredToExecute),
                                                                                    _isSigned(false))
{   
    std::cout << BG_YELLOW << "ShrubberyCreationForm copy constructor was called"  << RESET << std::endl << RESET;
}

/*  ================*=  Destructor: =*================= */

Form::~Form()
{
    std::cout << RESET << BG_RED << "ShrubberyCreationForm \"" << this->_formName << "\" was deleted" << RESET << std::endl << RESET ;
}

/*  ===========*=  Overload "=" operator: =*=========== */

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & source)
{   if(this == &source)
        return *this;
    _target = source._target;
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << RESET << BG_GREEN << "ShrubberyCreationForm  name: " << form.getFormName() << 
                        " ShrubberyCreationForm  is signed: " << form.getIsSigned() <<
                        " ShrubberyCreationForm  grade required to sign: " << form.getGradeRequiredToSign() << 
                        " ShrubberyCreationForm  grade required to execute: "<< form.getGradeRequiredToExecute() << 
                        " ShrubberyCreationForm  target: "<< form.getTarget() << RESET << std::endl << RESET;
    return os;
}

/*  =================*=  Methods: =*================= */

std::string const ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}


// HERE IS 
void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{   
    
    if (bureaucrat.getGrade() > this->_gradeRequiredToExecute)
        throw AForm::GradeTooLowException();
    else if (!this->_isSigned)
        throw AForm::AFormUnsignedException();       
    else
    {
        std::string pine = "       _-_\n
                                /~~   ~~\\\n
                              /~~         ~~\\\n
                              {               }\n
                              \\  _-     -_  /\n
                               ~  \\\\ //  ~\n
                              _- -   | | _- _\n
                                _ -  | |   -_\n
                                _ -  | |   -_\n
                                _ -  | |   -_\n
                                _ -  | |   -_\n 
                                    // \\\\\n";
        std::ofstream pineFile((this->_target + "_shrubbery"), std::ios::app);
        if(!pineFile.is_open())
        {
            throw std::exception();
        }        
        else
        {
            pineFile << pine;
            pineFile.close();
        }    
    }
    return;
}


