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


class Span
{
private:
    const unsigned int _n;
    std::vector<int> _vektor;
public:
    Span();
    Span(const unsigned int & n);
    Span( Span const &  src);
    ~Span();

    Span & operator= (Span const & src);
    
    std::vector<int> getSpan() const;

    void addNumber(const int & num);
    int shortestSpan();
    //int longestSpan();
};

std::ostream & operator<<(std::ostream &out, Span sp);


#endif