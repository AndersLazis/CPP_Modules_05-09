/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:45:07 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/08 12:28:20 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include "Colors.hpp"
#include <numeric> 
#include <climits>

typedef std::vector<int>::iterator itr;

class Span
{
private:
   
    unsigned int _n;
    std::vector<int> _vektor;

public:
     Span();
    Span(unsigned int n);
    Span( Span const &  src);
    ~Span();

    Span & operator= (Span const & src);
    
    std::vector<int> getSpan() const;

    void addNumber(const int & num);
    void addRange(itr begin, itr end);
    int shortestSpan();
    int longestSpan();
    class SpanTooSmallException: public std::exception
    {
        public:
            virtual const char *what()const throw ();
    };
};

std::ostream & operator<<(std::ostream &out, Span sp);


#endif