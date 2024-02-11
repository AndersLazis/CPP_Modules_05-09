/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:23:30 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/11 18:56:44 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "includes/AForm.hpp"
#include "includes/Colors.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Bureaucrat.hpp"

/*  ================*= Constructors =*================= */
/* Default */
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm default", 25, 5),
                                                _target("default")
{
    std::cout << BG_WHITE << "PresidentialPardonForm: \"" << this->getFormName() << "\" with grade required to sign: " << 
        this->getGradeRequiredToSign() << " and grade require to execute: " << this->getGradeRequiredToExecute() << "and target: " <<
         _target << " was created" << RESET << std::endl << RESET;
}

/* Constructor with parameters */
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm default", 25, 5),
                                                                    _target(target)
{    
    std::cout << BG_WHITE << "PresidentialPardonForm \"" << this->getFormName() << "\" with grade required to sign" << 
        this->getGradeRequiredToSign() << " and grade require to execute " << this->getGradeRequiredToExecute() << "and target: " <<
         _target << " was created"  << RESET << std::endl ;
}
/* Copy constructor */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & source) : AForm(source.getFormName(),
                                                                                     source.getGradeRequiredToSign(),
                                                                                     source.getGradeRequiredToExecute())
{   
    std::cout << BG_WHITE << "PresidentialPardonForm copy constructor was called"  << RESET << std::endl << RESET;
}

/*  ================*=  Destructor: =*================= */

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << RESET << BG_RED << "PresidentialPardonForm \"" << this->getFormName() << "\" was deleted" << RESET << std::endl << RESET ;
}

/*  ===========*=  Overload "=" operator: =*=========== */

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & source)
{   if(this == &source)
        return *this;
    this->_target = source._target;
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
    os  << BG_GREEN << "PresidentialPardonForm  name: " << form.getFormName() << 
                        " PresidentialPardonForm  is signed: " << form.getIsSigned() <<
                        " PresidentialPardonForm  grade required to sign: " << form.getGradeRequiredToSign() << 
                        " PresidentialPardonForm  grade required to execute: "<< form.getGradeRequiredToExecute() << 
                        " PresidentialPardonForm  target: "<< form.getTarget() << RESET << std::endl;
    return os;
}

/*  =================*=  Methods: =*================= */

std::string const PresidentialPardonForm::getTarget() const
{
    return this->_target;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{   
    std::cout << BG_WHITE << "PresidentialPardonForm \"" << this->getFormName() << "\" is being executed by " << executor.getName() << RESET << std::endl;
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();
    else if (!this->getIsSigned())
        throw AForm::AFormUnsignedException();       
    else
    {
        std::cout << GREEN << "<<< " << _target << " has been pardoned by Zaphod Beeblebrox >>>" << RESET << std::endl;
    }
    return;
}


