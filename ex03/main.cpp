/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:51:16 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/20 19:50:40 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/Bureaucrat.hpp"
#include "includes/Colors.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/AForm.hpp"
#include "includes/Intern.hpp"




int main()
{
	////////////////////////////////////////////// SCHRUBBERY ///////////////////////////////////////////
 	//#1
	std::cout << "\n\n============ #1 creation of tree ============\n\n" << RESET;
	try
	{
		Intern boy;
		Bureaucrat manager("Johnny then manager", 10);
		Bureaucrat gardener("Billy the Worker", 3);

		AForm* PinePtr = boy.makeForm("ShrubberyCreationForm", "Wald");
		std::cout << *PinePtr << RESET;
		ShrubberyCreationForm & ref = dynamic_cast<ShrubberyCreationForm&>(*PinePtr);
		ShrubberyCreationForm Oak(ref);
		std::cout << "Oak: " << Oak << RESET;	 	
	 	manager.signForm(Oak);	 	
	 	gardener.executeForm(Oak);		
	}
	catch(std::exception& e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	} 

	//#2
	std::cout << "\n\n============ #2 creation of Robot ============\n\n" << RESET;
	try
	{
		Intern boy;
		Bureaucrat manager("Johnny then manager", 10);
		Bureaucrat gardener("Billy the Worker", 3);

		AForm* Roborequest = boy.makeForm("RobotomyRequestForm", "Kellner");
		std::cout << *Roborequest << RESET;
		RobotomyRequestForm & ref = dynamic_cast<RobotomyRequestForm&>(*Roborequest);	 	
	 	manager.signForm(ref);	 	
	 	gardener.executeForm(ref);		
	}
	catch(std::exception& e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	
	//#3
	std::cout << "\n\n============ #3 creation of Pardon ============\n\n" << RESET;
	try
	{
		Intern boy;
		Bureaucrat manager("Johnny then manager", 10);
		Bureaucrat worker("Billy the Worker", 3);
		AForm* Pardonrequest = boy.makeForm("PresidentialPardonForm", "Kellner");
		std::cout << *Pardonrequest << RESET;
		PresidentialPardonForm & ref = dynamic_cast<PresidentialPardonForm&>(*Pardonrequest);	 	
	 	manager.signForm(ref);	 	
	 	worker.executeForm(ref);		
	}
	catch(std::exception& e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
}