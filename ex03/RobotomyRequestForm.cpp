/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:23:30 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/20 19:17:50 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "includes/AForm.hpp"
#include "includes/Colors.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/Bureaucrat.hpp"

/*  ================*= Constructors =*================= */
/* Default */
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm default", 72, 45),
                                                _target("default")
{
    std::cout << BG_YELLOW << "RobotomyRequestForm: \"" << this->getFormName() << "\" with grade required to sign: " << 
        this->getGradeRequiredToSign() << " and grade require to execute: " << this->getGradeRequiredToExecute() << "and target: " <<
         _target << " was created" << RESET << std::endl << RESET;
}

/* Constructor with parameters */
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm default", 72, 45),
                                                                    _target(target)
{    
    std::cout << BG_YELLOW << "RobotomyRequestForm \"" << this->getFormName() << "\" with grade required to sign" << 
        this->getGradeRequiredToSign() << " and grade require to execute " << this->getGradeRequiredToExecute() << "and target: " <<
         _target << " was created"  << std::endl << RESET;
}
/* Copy constructor */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & source) : AForm(source.getFormName(),
                                                                                     source.getGradeRequiredToSign(),
                                                                                     source.getGradeRequiredToExecute())
{   
    std::cout << BG_YELLOW << "RobotomyRequestForm copy constructor was called"  << RESET << std::endl << RESET;
}

/*  ================*=  Destructor: =*================= */

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << RESET << BG_RED << "RobotomyRequestForm \"" << this->getFormName() << "\" was deleted" << RESET << std::endl << RESET ;
}

/*  ===========*=  Overload "=" operator: =*=========== */

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & source)
{   if(this == &source)
        return *this;
    _target = source._target;
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
    os << RESET << BG_GREEN << "RobotomyRequestForm  name: " << form.getFormName() << 
                        " RobotomyRequestForm  is signed: " << form.getIsSigned() <<
                        " RobotomyRequestForm  grade required to sign: " << form.getGradeRequiredToSign() << 
                        " RobotomyRequestForm  grade required to execute: "<< form.getGradeRequiredToExecute() << 
                        " RobotomyRequestForm  target: "<< form.getTarget() << RESET << std::endl << RESET;
    return os;
}

/*  =================*=  Methods: =*================= */

std::string const RobotomyRequestForm::getTarget() const
{
    return this->_target;
}


// HERE IS 
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{   
    std::cout << BG_YELLOW << "RobotomyRequestForm \"" << this->getFormName() << "\" is being executed by " << executor.getName() << RESET << std::endl;
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();
    else if (!this->getIsSigned())
        throw AForm::AFormUnsignedException();       
    else
    {   
        std::cout << GREEN << " <<<<< Drilling noize >>>>> \n" << RESET;
        std::time_t currentTime = std::time(NULL);
        int currentTimeInt = static_cast<int>(currentTime);
        if(currentTimeInt%2)
            std::cout << GREEN << " <target>" << _target << "has been robotomized successfully \n" << RESET;
        else
            std::cout << GREEN << " <target>" << _target << "has been not been robotomized. Robotomy failed. \n" << RESET;
    }
    return;
}


