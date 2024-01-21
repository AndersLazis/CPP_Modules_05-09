/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:23:30 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/20 19:00:25 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "includes/AForm.hpp"
#include "includes/Colors.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Bureaucrat.hpp"

/*  ================*= Constructors =*================= */
/* Default */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm default", 145, 137),
                                                _target("default")
{
    std::cout << BG_PURPLE << "ShrubberyCreationForm: \"" << this->getFormName() << "\" with grade required to sign: " << 
        this->getGradeRequiredToSign() << " and grade require to execute: " << this->getGradeRequiredToExecute() << "and target: " <<
         _target << " was created" << RESET << RESET << std::endl ;
}

/* Constructor with parameters */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm default", 145, 137),
                                                                    _target(target)
{    
    std::cout << BG_PURPLE << "ShrubberyCreationForm \"" << this->getFormName() << "\" with grade required to sign" << 
        this->getGradeRequiredToSign() << " and grade require to execute " << this->getGradeRequiredToExecute() << "and target: " <<
         _target << " was created"  << RESET << std::endl ;
}
/* Copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & source) : AForm(source.getFormName(),
                                                                                     source.getGradeRequiredToSign(),
                                                                                     source.getGradeRequiredToExecute())
{   
    std::cout << BG_PURPLE << "ShrubberyCreationForm copy constructor was called"  << RESET << RESET << std::endl ;
}

/*  ================*=  Destructor: =*================= */

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << RESET << BG_RED << "ShrubberyCreationForm \"" << this->getFormName() << "\" was deleted" << RESET << RESET << std::endl  ;
}

/*  ===========*=  Overload "=" operator: =*=========== */

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & source)
{   if(this == &source)
        return *this;
    _target = source._target;
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
    os << RESET << BG_GREEN << "ShrubberyCreationForm  name: " << form.getFormName() << 
                        " ShrubberyCreationForm  is signed: " << form.getIsSigned() <<
                        " ShrubberyCreationForm  grade required to sign: " << form.getGradeRequiredToSign() << 
                        " ShrubberyCreationForm  grade required to execute: "<< form.getGradeRequiredToExecute() << 
                        " ShrubberyCreationForm  target: "<< form.getTarget() << RESET << RESET << std::endl ;
    return os;
}

/*  =================*=  Methods: =*================= */

std::string const ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}


// HERE IS 
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{   
    std::cout << BG_PURPLE << "ShrubberyCreationForm \"" << this->getFormName() << "\" is being executed by " << executor.getName() << RESET << std::endl;
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();
    else if (!this->getIsSigned())
        throw AForm::AFormUnsignedException();       
    else
    {
        std::string pine = "      _-_\n";
        pine +=            "   /~~   ~~\\\n";
        pine +=            "/~~         ~~\\\n";
        pine +=            "{               }\n";
        pine +=            " \\  _-     -_  /\n";
        pine +=            "  ~  \\\\ //  ~\n";
        pine +=            " _- -  | | _- _\n";
        pine +=            "   _ - | |   -_\n";
        pine +=            "       | |     \n";
        pine +=            "       | |     \n";
        pine +=            "       | |     \n" ;
        pine +=            "      // \\\\\n";
        std::ofstream pineFile((this->_target + "_shrubbery").c_str(), std::ios::app);
        if(!pineFile.is_open())
        {   
            std::cerr << "Error: file is not open" << RESET << std::endl;
            throw std::exception();
            //throw std::runtime_error("Error: file is not open");
        }        
        else
        {
            pineFile << pine;
            pineFile.close();
            std::cout << GREEN << "<<< Pine has been plated in " << _target << " >>>" << RESET << std::endl;
        }    
    }
    return;
}


