/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:53:15 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/11 19:06:17 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARDON_HPP
# define PARDON_HPP

#include <string>
#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class PresidentialPardonForm: public AForm
{
private:
    std::string	_target;
    
public:
	
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const & source);
    ~PresidentialPardonForm();
    PresidentialPardonForm & operator=(PresidentialPardonForm const & source);
	
    std::string const	getTarget() const;
    void                execute(Bureaucrat const & executor) const;        
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
#endif
