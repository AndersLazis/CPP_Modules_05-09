/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:30:03 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/16 21:06:12 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"

Span::Span() : _n(0){}

Span::Span(const unsigned int & n) : _n(n){
    _vektor.reserve(n);
}

Span::~Span(){}

Span::Span( Span const &  src) : _n(src._n)
{
    *this = src;
}

Span & Span::operator= (Span const & src)
{
    if (this != &src)
    {   
        _vektor = src.getSpan();       
    }
    return *this;
}

std::vector<int> Span::getSpan() const
{
    return _vektor;
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



void Span::addNumber(const int & num)
{
    if(_n == 0)
        throw std::out_of_range("No space left");
    else if (_vektor.size() < _n)
        _vektor.push_back(num);
    else
        throw std::out_of_range("No space left");
}

//int longestSpan();
int Span::shortestSpan()
{
    std::vector<int> diff(_vektor.size());
    sort(_vektor.begin(), _vektor.end());
    // std::cout << "min element " << *it_min << std::endl;
    // std::cout << "max element " << *it_max << std::endl;
   // =diff.begin();
    std::adjacent_difference(_vektor.begin(), _vektor.end(), diff.begin());
    //std::cout << "min element " << *it_r << std::endl;
    std::vector<int>::iterator it_min = std::min_element(diff.begin(), diff.end());
    std::vector<int>::iterator it_max = std::max_element(diff.begin(), diff.end());
    std::cout << "res " << *it_max << *it_min << std::endl;
    
    return 0; //*it_max;
}
