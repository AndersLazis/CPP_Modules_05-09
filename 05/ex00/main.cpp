/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:51:16 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/16 12:20:22 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include "includes/Bureaucrat.hpp"
#include "includes/Colors.hpp"


int main ()
{	
	////////////////////////////////////////////////////////////////////////////////////////////////
	//#1
	std::cout << "\n\n============ #1 creation of bureaucrats ============\n\n" << RESET;
	std::cout << "Bureaucrat by default constructor:\n\n" << RESET;
	try
	{
		Bureaucrat noname;
		std::cout << CYAN << "I am: " << noname.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << noname.getGrade() << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}

	//#2
	std::cout << "\nBureaucrat by constructor with parameters:\n\n" << RESET;
	try
	{
		Bureaucrat sam("SAM", 12);
		std::cout << CYAN << "I am: " << sam.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << sam.getGrade() << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	
	//#3	
	std::cout  <<"\nBureaucrats with NOK (negative value) grade\n\n" << RESET;	
	try
	{
		Bureaucrat johnny("Johnny", -12);
		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	
	//#4
	std::cout << "\nBureaucrats with NOK (too low) grade  and catch std::exception\n\n" << RESET;	
	try
	{
		Bureaucrat johnny("Jack", 160);
		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << PURPLE << "std::exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	
	
	////////////////////////////////////////////////////////////////////////////////////////////////
	
	std::cout << "\n============ #2 assignment operator test ===========\n\n" << RESET;
	//#5

	Bureaucrat eins("Eins", 1);
	Bureaucrat zwei("Zwei", 2);
	
	std::cout << CYAN << "I am: " << eins.getName() << RESET <<std::endl;
	std::cout << CYAN << "My grade is: " << eins.getGrade() << RESET <<std::endl;
	std::cout << CYAN << "I am: " << zwei.getName() << RESET <<std::endl;
	std::cout << CYAN << "My grade is: " << zwei.getGrade() << RESET <<std::endl;

	eins = zwei;
	
	std::cout << CYAN << "I am: " << eins.getName() << RESET <<std::endl;
	std::cout << CYAN << "My grade is: " << eins.getGrade() << RESET <<std::endl;
	std::cout << CYAN << "I am: " << zwei.getName() << RESET <<std::endl;
	std::cout << CYAN << "My grade is: " << zwei.getGrade() << RESET <<std::endl;

		
	////////////////////////////////////////////////////////////////////////////////////////////////
	
	std::cout << "\n============ #3 copy constructor test ===========\n\n" << RESET;
	//#6

	Bureaucrat alpha("Alpha", 2);
	Bureaucrat bravo(alpha);
	
	std::cout << CYAN << "I am: " << alpha.getName() << RESET <<std::endl;
	std::cout << CYAN << "My grade is: " << alpha.getGrade() << RESET <<std::endl;
	std::cout << CYAN << "I am: " << bravo.getName() << RESET <<std::endl;
	std::cout << CYAN << "My grade is: " << bravo.getGrade() << RESET <<std::endl;
	
	////////////////////////////////////////////////////////////////////////////////////////////////
	
	std::cout << "\n==== #4 increment/decrement level of bureaucrats ====\n\n" << RESET;
	//#7
	std::cout << "\nIncrement Bureaucrat with OK grade\n\n" << RESET;
	try
	{	
		Bureaucrat johnny("Johnny", 3);
		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;

		johnny.incrementGrade();
		
		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}

	//#8
	std::cout << "\nDecrement Bureaucrat with OK grade\n\n" << RESET;	
	try
	{	
		Bureaucrat johnny("Johnny", 3);
		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;
		
		johnny.decrementGrade();
		
		std::cout << CYAN << "I am: " << johnny.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << johnny.getGrade() << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}


	//#9
	std::cout << "\nIncrement Bureaucrat with NOK grade and catch std::exceptions\n\n" << RESET;
	

	try
	{	
		Bureaucrat viktor("Viktor", 1);
		std::cout << CYAN << "I am: " << viktor.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << viktor.getGrade() << RESET <<std::endl;

		viktor.incrementGrade();
		
		std::cout << CYAN << "I am: " << viktor.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << viktor.getGrade() << RESET <<std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << PURPLE << "std::exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}

	//#10
	std::cout << "\nDecrement Bureaucrat with NOK grade\n\n" << RESET;	
	try
	{	
		Bureaucrat zakharia("Zakharia", 150);
		std::cout << CYAN << "I am: " << zakharia.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << zakharia.getGrade() << RESET <<std::endl;
		
		zakharia.decrementGrade();
		
		std::cout << CYAN << "I am: " << zakharia.getName() << RESET <<std::endl;
		std::cout << CYAN << "My grade is: " << zakharia.getGrade() << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << PURPLE << "Exception was caught: \"" << e.what() << "\"" << RESET <<std::endl;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////
	
	std::cout << "\n============= #5 \"<<\" operator test ==============\n" << RESET;
	//#11
	std::cout << "\nPrint bureaucrat\n" << RESET;
	Bureaucrat peter("Peter", 38);
	std::cout << peter;
		
	return 0;
}