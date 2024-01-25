/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:15 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/20 16:59:02 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHRUBBERY_HPP
# define SCHRUBBERY_HPP

#include <string>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class ShrubberyCreationForm : public AForm
{
private:
    std::string	_target;
    
public:
	
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const & source);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & source);
	
    std::string const	getTarget() const;
    void                execute(Bureaucrat const & executor) const;        
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif
