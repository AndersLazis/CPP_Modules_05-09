/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:15 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/17 13:50:07 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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
	

protected:
    virtual void		beExecuted() const = 0;
    
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
    void                execute(Bureaucrat const & bureaucrat) const;
	
        
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
    class FormNotSignedException : public std::exception
    {
        public:
            const char* what()const throw();            
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif
