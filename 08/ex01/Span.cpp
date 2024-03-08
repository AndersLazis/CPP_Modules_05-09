/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:30:03 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/08 12:42:56 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"


Span::Span() : _n(0){}

Span::Span(unsigned int n) : _n(n)
{
    // _vektor.reserve(n);
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
        _vektor = src._vektor;
        _n = src._n;       
    }
    return *this;
}

std::vector<int> Span::getSpan() const
{
    return _vektor;
}

void Span::addNumber(const int & num)
{
    if(_n == 0)
        throw SpanTooSmallException();
    else if (_vektor.size() < _n)
        _vektor.push_back(num);
    else
        throw std::out_of_range("No space left");
}

void Span::addRange(itr begin, itr end)
{
    if (this->_vektor.size() + std::distance(begin, end) > this->_n)
        throw std::out_of_range("No space left");
    else
        _vektor.insert(_vektor.end(), begin, end);
}

int Span::longestSpan()
{   
    if(_n < 2 || _vektor.size() < 2)
        throw SpanTooSmallException();
    std::vector<int> diff(_vektor.size());
    sort(_vektor.begin(), _vektor.end());
    std::vector<int>::iterator it_min = std::min_element(_vektor.begin(), _vektor.end());
    std::vector<int>::iterator it_max = std::max_element(_vektor.begin(), _vektor.end());
    return *it_max - *it_min;
}

int Span::shortestSpan()
{
    if(_n < 2 || _vektor.size() < 2)
        throw SpanTooSmallException();
    std::vector<int> diff(_vektor.size());
    sort(_vektor.begin(), _vektor.end());
    std::adjacent_difference(_vektor.begin(), _vektor.end(), diff.begin());
    diff.erase(diff.begin());
    std::vector<int>::iterator it_min = std::min_element(diff.begin(), diff.end());
    return *it_min;
}

const char * Span::SpanTooSmallException::what(void) const throw()
{
    return ("Error: Span is too small!\n");
}

std::ostream & operator<<(std::ostream & out, Span sp)
{
    std::vector<int> vektor = sp.getSpan();
    std::cout << BLUE << "Your span is: \n" << RESET;
    for(std::vector<int>::iterator it = vektor.begin(); it != vektor.end(); it++)
    {
        out << *it << " ";
    }
    out << std::endl;
    return out;    
}