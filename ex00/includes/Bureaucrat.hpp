/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:15 by aputiev           #+#    #+#             */
/*   Updated: 2023/11/04 20:26:09 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
    std::string _Name;
    int _Grade;

    static int const _minGrade = 150;
    static int const _maxGrade = 1;
    void _checkGrade(int grade);
    
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const & source);
    ~Bureaucrat();
    Bureaucrat & operator=(Bureaucrat const & source);

    std::string const getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what()const throw();            
    };
    
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what()const throw();            
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif
