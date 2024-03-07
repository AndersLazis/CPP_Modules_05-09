/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:45:07 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/16 20:56:24 by aputiev          ###   ########.fr       */
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


class Span
{
private:
    Span();
    unsigned int _n;
    std::vector<int> _vektor;

public:
    
    Span(unsigned int n);
    Span( Span const &  src);
    ~Span();

    Span & operator= (Span const & src);
    
    std::vector<int> getSpan() const;

    void addNumber(const int & num);
    void addManyNumbers(const unsigned int n, const int & num_min);
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