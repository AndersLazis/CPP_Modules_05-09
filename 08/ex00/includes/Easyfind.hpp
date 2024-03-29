/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:45:07 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/12 21:57:30 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include "Colors.hpp"



template <typename T>
typename T::const_iterator easyfind(T const & conainer, int num)
{   
    typename T::const_iterator it = std::find(conainer.begin(), conainer.end(), num);
    if(it != conainer.end())
    {
        std::cout << GREEN << "Element \"" << *it << "\" has been found " << RESET << std::endl;
        return it;            
    }    
    else
    {   
        throw std::out_of_range("Element not found");
    }
}

#endif