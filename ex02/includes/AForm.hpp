/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:15 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/19 22:52:47 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;
class AForm
{
private:
    std::string	const	_formName;
    int	const			_gradeRequiredToSign;
    int const			_gradeRequiredToExecute;
    bool				_isSigned;
    
public:
	
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(AForm const & source);
    virtual ~AForm();
    AForm & operator=(AForm const & source);
	
    std::string const	getFormName() const;
    bool				getIsSigned() const;
    int					getGradeRequiredToSign() const;
    int					getGradeRequiredToExecute() const;
	void				beSigned(Bureaucrat const & bureaucrat);	

    virtual void execute(Bureaucrat const & executor) const = 0;
        
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what()const throw();            
    };
	class GradeTooHighException : public std::exception
    {
        public:
           virtual const char* what()const throw();            
    };
	class FormAlreadySignedException : public std::exception
    {
        public:
           virtual const char* what()const throw();            
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif
