/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:51:16 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/17 13:50:22 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include "includes/Bureaucrat.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Colors.hpp"



int main()
{	
	////////////////////////////////////////////////////////////////////////////////////////////////
	//#1
	std::cout << "\n\n============ #1 creation of form ============\n\n" << RESET;
	std::cout << "Form by default constructor:\n" << RESET;
	try
	{
		ShrubberyCreationForm form1;
		Bureaucrat johnny("Johnny", 3);
		johnny.signForm(form1);
		johnny.executeForm(form1);
		std::cout << form1 << RESET;
	}

	// //#2
	// std::cout << "Form by normal constructor:\n" << RESET;
	// try
	// {
	// 	Form form2("Form 2", 120, 120);
	// 	std::cout << form2 << RESET;
	// }
	
	// //#3	
	// std::cout << "\nForm with NOK grades\n" << RESET;	
	// try
	// {
	// 	Form formTooHigh("Form with too high grade", 200, 12);
	// 	std::cout << formTooHigh << RESET;
	// }

	//#4
	// std::cout << "\n Form copy constructor test \n" << RESET;	
	// try
	// {
	// 	Form source("Source", 110, 12);
	// 	Form newForm(source);
	// 	std::cout << newForm << RESET;
	// }

	//#5
	// std::cout << "\n Form assignment operator test \n" << RESET;	
	// try
	// {
	// 	Form source("Source", 110, 12);
	// 	Form newForm("newForm", 1, 1);
	// 	newForm = source;
	// 	std::cout << newForm << RESET;
	// }

	//#6
	// std::cout << "\n Form sign test with OK/NOK grade\n" << RESET;
	// try
	// {	
	// 	Form form("Form 1", 3, 3);
	// 	Bureaucrat johnny("Johnny", 10);
	// 	johnny.signForm(form);
	// 	std::cout << form << RESET;
	// }

	//#7
	// std::cout << "\n Form sign test if form already signed\n" << RESET;
	// try
	// {	
	// 	Form form("Form 1", 3, 3);
	// 	Bureaucrat johnny("Johnny", 3);
	// 	Bureaucrat billy("Billy", 3);		
	// 	johnny.signForm(form);
	// 	std::cout << form << RESET;
	// 	billy.signForm(form);		
	// }

	
	




	
	catch(std::exception& e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	
}
// 	////////////////////////////////////////////////////////////////////////////////////////////////
	
// 	std::cout << "\n============ #2 assignment operator test ===========\n\n" << RESET;
// 	//#5

// 	Bureaucrat eins("Eins", 1);
// 	Bureaucrat zwei("Zwei", 2);
	
// 	std::cout << CYAN << "I am: " << eins.getName() << RESET <<std::endl;
// 	std::cout << CYAN << "My grade is: " << eins.getGrade() << RESET <<std::endl;
// 	std::cout << CYAN << "I am: " << zwei.getName() << RESET <<std::endl;
// 	std::cout << CYAN << "My grade is: " << zwei.getGrade() << RESET <<std::endl;

// 	eins = zwei;
	
// 	std::cout << CYAN << "I am: " << eins.getName() << RESET <<std::endl;
// 	std::cout << CYAN << "My grade is: " << eins.getGrade() << RESET <<std::endl;
// 	std::cout << CYAN << "I am: " << zwei.getName() << RESET <<std::endl;
// 	std::cout << CYAN << "My grade is: " << zwei.getGrade() << RESET <<std::endl;

		
// 	////////////////////////////////////////////////////////////////////////////////////////////////
	
// 	std::cout << "\n============ #2 copy constructor test ===========\n\n" << RESET;
// 	//#6

// 	Bureaucrat alpha("Alpha", 2);
// 	Bureaucrat bravo(alpha);
	
// 	std::cout << CYAN << "I am: " << alpha.getName() << RESET <<std::endl;
// 	std::cout << CYAN << "My grade is: " << alpha.getGrade() << RESET <<std::endl;
// 	std::cout << CYAN << "I am: " << bravo.getName() << RESET <<std::endl;
// 	std::cout << CYAN << "My grade is: " << bravo.getGrade() << RESET <<std::endl;
	
// 	////////////////////////////////////////////////////////////////////////////////////////////////
	
// 	std::cout << "\n==== #1 increment/decrement level of bureaucrats ====\n\n" << RESET;
// 	//#7
// 	std::cout << "\nIncrement Bureaucrat with OK grade\n" << RESET;
// 	try
// 	{	
// 		Bureaucrat johnny("Johnny", 3);
// 		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
// 		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;

// 		johnny.incrementGrade();
		
// 		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
// 		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;
// 	}
// 	catch(Bureaucrat::GradeTooHighException & e)
// 	{
// 		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
// 	}
// 	catch(Bureaucrat::GradeTooLowException & e)
// 	{
// 		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
// 	}

// 	//#8
// 	std::cout << "\nDecrement Bureaucrat with OK grade\n" << RESET;	
// 	try
// 	{	
// 		Bureaucrat johnny("Johnny", 3);
// 		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
// 		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;
		
// 		johnny.decrementGrade();
		
// 		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
// 		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;
// 	}
// 	catch(Bureaucrat::GradeTooHighException & e)
// 	{
// 		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
// 	}
// 	catch(Bureaucrat::GradeTooLowException & e)
// 	{
// 		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
// 	}


// 	//#9
// 	std::cout << "\nIncrement Bureaucrat with NOK grade\n" << RESET;
	

// 	try
// 	{	
// 		Bureaucrat viktor("Viktor", 1);
// 		std::cout << CYAN << "I am: " << viktor.getName() << RESET <<std::endl;
// 		std::cout << CYAN << "My grade is: " << viktor.getGrade() << RESET <<std::endl;

// 		viktor.incrementGrade();
		
// 		std::cout << CYAN << "I am: " << viktor.getName() << RESET <<std::endl;
// 		std::cout << CYAN << "My grade is: " << viktor.getGrade() << RESET <<std::endl;
// 	}
// 	catch(Bureaucrat::GradeTooHighException & e)
// 	{
// 		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
// 	}
// 	catch(Bureaucrat::GradeTooLowException & e)
// 	{
// 		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
// 	}

// 	//#10
// 	std::cout << "\nDecrement Bureaucrat with NOK grade\n" << RESET;	
// 	try
// 	{	
// 		Bureaucrat zakharia("Zakharia", 150);
// 		std::cout << CYAN << "I am: " << zakharia.getName() << RESET <<std::endl;
// 		std::cout << CYAN << "My grade is: " << zakharia.getGrade() << RESET <<std::endl;
		
// 		zakharia.decrementGrade();
		
// 		std::cout << CYAN << "I am: " << zakharia.getName() << RESET <<std::endl;
// 		std::cout << CYAN << "My grade is: " << zakharia.getGrade() << RESET <<std::endl;
// 	}
// 	catch(Bureaucrat::GradeTooHighException & e)
// 	{
// 		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
// 	}
// 	catch(Bureaucrat::GradeTooLowException & e)
// 	{
// 		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
// 	}

// 	////////////////////////////////////////////////////////////////////////////////////////////////
	
// 	std::cout << "\n============= \"<<\" operator test ==============\n" << RESET;
// 	//#11
// 	std::cout << "\nPrint bureaucrat\n" << RESET;
// 	Bureaucrat peter("Peter", 38);
// 	std::cout << peter;
	
// 	return 0;
