/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:15 by aputiev           #+#    #+#             */
/*   Updated: 2024/01/20 19:16:11 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include <string>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class RobotomyRequestForm: public AForm
{
private:
    std::string	_target;
    
public:
	
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const & source);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(RobotomyRequestForm const & source);
	
    std::string const	getTarget() const;
    void                execute(Bureaucrat const & executor) const;        
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif
