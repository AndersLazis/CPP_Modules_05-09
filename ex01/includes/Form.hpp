/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:15 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/16 14:36:10 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;
class Form
{
private:
    std::string	const	_formName;
    int	const			_gradeRequiredToSign;
    int const			_gradeRequiredToExecute;
	

    
public:
	
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(Form const & source);
    ~Form();
    Form & operator=(Form const & source);
	
    std::string const	getFormName() const;
    bool				getIsSigned() const;
    int					getGradeRequiredToSign() const;
    int					getGradeRequiredToExecute() const;
	void				beSigned(Bureaucrat const & bureaucrat);

	bool				_isSigned;
        
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what()const throw();            
    };
	class GradeTooHighException : public std::exception
    {
        public:
            const char* what()const throw();            
    };
	class FormAlreadySignedException : public std::exception
    {
        public:
            const char* what()const throw();            
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);
#endif
