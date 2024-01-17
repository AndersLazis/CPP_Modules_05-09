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
#include <fstream>
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Colors.hpp"
#include "includes/AForm.hpp"

  

/*  ================*= Constructors =*================= */
/* Default */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default ShrubberyCreationForm", 145, 137),
                                                _target("default target")
{
    std::cout << BG_YELLOW << "ShrubberyCreationForm \"" << getFormName() << "with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << " was created" << RESET << 
        " and target " << _target << std::endl << RESET;
}
/* Constructor with parameters */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("default ShrubberyCreationForm", 145, 137),
                                                                    _target(target)
{
    std::cout << BG_YELLOW << "ShrubberyCreationForm \"" <<  getFormName() << "\" with grade required to sign" << 
        _gradeRequiredToSign << " and grade require to execute " << _gradeRequiredToExecute << " was created"  << RESET << std::endl << RESET;
}
/* Copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & source) : AForm(source), _target(source._target)
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
    this->_target = source._target;
    return *this;
}

/*  ===========*=  Overload "<<" operator: =*=========== */

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& ShrubberyCreationForm)
{
    os << RESET << BG_GREEN << "ShrubberyCreationForm name: " << ShrubberyCreationForm.getFormName() << 
                        " ShrubberyCreationForm is signed: " << ShrubberyCreationForm.getIsSigned() <<
                        " ShrubberyCreationForm grade required to sign: " << ShrubberyCreationForm.getGradeRequiredToSign() << 
                        " ShrubberyCreationForm grade required to execute: "<< ShrubberyCreationForm.getGradeRequiredToExecute() << 
                        " ShrubberyCreationForm target: " << ShrubberyCreationForm.getTarget() << RESET << std::endl << RESET;
    return os;
}

/*  =================*=  Methods: =*================= */

 std::string const & ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}


void ShrubberyCreationForm::beExecuted() const
{   
    std::ofstream out;
    std::string filename = this->_target + "shrubbery";
    if(out.open(filename.c_str()))       
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
