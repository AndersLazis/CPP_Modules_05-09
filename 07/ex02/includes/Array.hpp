/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:05:39 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/09 22:08:40 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"
#include <iomanip>

template < typename T >
class Array
{
    public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array &			operator=( const Array &rhs );
		T &				operator[](unsigned int index);		
		unsigned int	size() const;

		class wrongIndexException : public std::exception
		{
            public:
                virtual const char *what () const throw()
                {
                    return "Index out of range";
                }
		};       

    private:		
		unsigned int	_size;
        T *				_array;

};

#include "../Array.tpp"
#endif