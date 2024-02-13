/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:30:03 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/13 19:30:19 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"

Span::Span() : _n(0){}

Span::Span(const unsigned int & n) : _n(n){
    _vektor.reserve(n);
}

Span::~Span(){}

std::vector<int> Span::getSpan()
{
    return _vektor;
}

Span::Span( Span const &  src)
{}


void Span::addNumber(const int & num)
{
    if(_n == 0)
        throw std::out_of_range("No space left");
    else if (_vektor.size() < _n)
        _vektor.push_back(num);
    else
        throw std::out_of_range("No space left");
}

std::ostream & operator<<(std::ostream & out, Span sp)
{
    std::vector<int>::iterator it;
    for(it = sp.getSpan().begin(); it != sp.getSpan().end(); ++it)
    {
        out << *it << " ";
    }
    out << std::endl;
    return out;    
}
