/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:55:49 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/17 13:07:52 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
    std::string	                _target;
    static std::string const	_shrubbery;
    
public:
	
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const & source);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & source);
	
    std::string const &	getTarget() const;
	void				beExecuted() const;

    static int	const			_gradeRequiredToSign = 145;
    static int const			_gradeRequiredToExecute = 137;

};

#endif
