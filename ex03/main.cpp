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




int main()
{
	////////////////////////////////////////////// SCHRUBBERY ///////////////////////////////////////////////
	//#1
	// std::cout << "\n\n============ #1 creation of tree ============\n\n" << RESET;
	// std::cout << "Form by default constructor:\n" << RESET;
	// try
	// {
	// 	ShrubberyCreationForm Pine("Wald");
	// 	ShrubberyCreationForm Oak(Pine);
	// 	std::cout << Oak << RESET;
	// 	Bureaucrat manager("Johnny then manager", 10);
	// 	manager.signForm(Oak);
	// 	Bureaucrat gardener("Billy the Worker", 3);
	// 	gardener.executeForm(Oak);
		
		
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }

	// //#2
	// 	std::cout << "\n\n============ #2 creation of tree UNSIGNED ============\n\n" << RESET;
	// std::cout << "Form by default constructor:\n" << RESET;
	// try
	// {
	// 	ShrubberyCreationForm Pine("Wald");
	// 	std::cout << Pine << RESET;
	// 	Bureaucrat gardener("Billy the Worker", 3);
	// 	gardener.executeForm(Pine);
		
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }
	
	//#3
	// std::cout << "\n\n============ #3 creation of tree WRONG GRADE ============\n\n" << RESET;
	// std::cout << "Form by default constructor:\n" << RESET;
	// try
	// {
	// 	ShrubberyCreationForm Pine("Wald");
	// 	std::cout << Pine << RESET;
	// 	Bureaucrat manager("Johnny then manager", 10);
	// 	manager.signForm(Pine);
	// 	Bureaucrat gardener("Billy the Worker", 150);
	// 	gardener.executeForm(Pine);
		
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }





	////////////////////////////////////////////// ROBOTOMY ///////////////////////////////////////////////

	// std::cout << "\n\n============ #1 creation of form ============\n\n" << RESET;
	// try
	// {
	// 	RobotomyRequestForm form("Dumbhead bureaucrat");
	// 	std::cout << form << RESET;
	// 	Bureaucrat engineer("Johnny then engineer", 10);
	// 	engineer.signForm(form);
	// 	Bureaucrat robotist("Billy the Worker", 3);
	// 	robotist.executeForm(form);
		
		
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }

	// std::cout << "\n\n============ #2 creation of tree UNSIGNED ============\n\n" << RESET;
	// try
	// {
	// 	RobotomyRequestForm form("Dumbhead bureaucrat");
	// 	std::cout << form << RESET;
	// 	Bureaucrat robotist("Billy the Worker", 3);
	// 	robotist.executeForm(form);		
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }

	//#3
	// std::cout << "\n\n============ #3 creation of tree WRONG GRADE ============\n\n" << RESET;
	// try
	// {
	// 	RobotomyRequestForm form("Dumbhead bureaucrat");
	// 	std::cout << form << RESET;
	// 	Bureaucrat engineer("Johnny then engineer", 10);
	// 	engineer.signForm(form);
	// 	Bureaucrat robotist("Billy the Worker", 130);
	// 	robotist.executeForm(form);	
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }


		////////////////////////////////////////////// PARDON ///////////////////////////////////////////////
	//#1	
	std::cout << "\n\n============ #1 creation of form ============\n\n" << RESET;
	try
	{
		PresidentialPardonForm form("Kellner");
		std::cout << form << RESET;
		Bureaucrat minister("Johnny the minister", 10);
		minister.signForm(form);
		Bureaucrat worker("Billy the pardon-guy", 3);
		worker.executeForm(form);		
	}
	catch(std::exception& e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	
	//#2
	std::cout << "\n\n============ #2 creation of tree UNSIGNED ============\n\n" << RESET;
	try
	{
		PresidentialPardonForm form("Kellner");
		std::cout << form << RESET;
		Bureaucrat worker("Billy the pardon-guy", 3);
		worker.executeForm(form);		
	}
	catch(std::exception& e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}

	//#3
	std::cout << "\n\n============ #3 creation of tree WRONG GRADE ============\n\n" << RESET;
	try
	{
		PresidentialPardonForm form("Kellner");
		std::cout << form << RESET;
		Bureaucrat minister("Johnny the minister", 120);
		minister.signForm(form);
		Bureaucrat worker("Billy the pardon-guy", 3);
		worker.executeForm(form);	
	}
	catch(std::exception& e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	
	
}

