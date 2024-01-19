/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:51:16 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/20 00:09:11 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/Bureaucrat.hpp"
#include "includes/Colors.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/AForm.hpp"




int main()
{
	////////////////////////////////////////////////////////////////////////////////////////////////
	//#1
	std::cout << "\n\n============ #1 creation of form ============\n\n" << RESET;
	std::cout << "Form by default constructor:\n" << RESET;
	try
	{
		ShrubberyCreationForm Pine("Wald")
		std::cout << Pine << RESET;
		Bureaucrat manager("Johnny", 10);
		manager.signForm(Pine);
		Bureaucrat gardener("Billy", 3);
		gardener.executeForm(Pine);
		
	}
	catch(std::exception& e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}

	// //#2
	// std::cout << "\nForm by normal constructor:\n" << RESET;
	// try
	// {
	// 	Form form2("Form 2", 120, 120);
	// 	std::cout << form2 << RESET;
	// }
	// 	catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }

	// //#3
	// std::cout << "\nForm with NOK grades\n" << RESET;
	// try
	// {
	// 	Form formTooHigh("Form with too high grade", 200, 12);
	// 	std::cout << formTooHigh << RESET;
	// }
	// 	catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }

	// //#4
	// std::cout << "\n Form copy constructor test \n" << RESET;
	// try
	// {
	// 	Form source("Source", 110, 12);
	// 	Form newForm(source);
	// 	std::cout << newForm << RESET;
	// }
	// 	catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }

	// //#5
	// std::cout << "\n Form sign test with OK/NOK grade\n" << RESET;
	// try
	// {
	// 	Form form("Form 1", 3, 3);
	// 	Bureaucrat johnny("Johnny", 10);
	// 	johnny.signForm(form);
	// 	std::cout << form << RESET;
	// }
	// 	catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }

	// //#6
	// std::cout << "\n Form sign test if form already signed\n" << RESET;
	// try
	// {
	// 	Form form("Form 1", 3, 3);
	// 	Bureaucrat johnny("Johnny", 3);
	// 	Bureaucrat billy("Billy", 3);
	// 	johnny.signForm(form);
	// 	std::cout << form << RESET;
	// 	billy.signForm(form);
	// 	std::cout << form << RESET;
		
	// }
	// catch(std::exception& e)
	// {
	// 	std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	// }

}