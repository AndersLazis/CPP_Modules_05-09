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

Span::Span(unsigned int n){

    // if(n > 1000000)
    //     throw std::out_of_range("Please, enter valid amount of numbers less than 100000");
    // else
    // {
        _n= n;
       // _vektor.reserve(n);
    //}
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

void Span::addNumber(const int & num)
{
    if(_n == 0)
        throw SpanTooSmallException();
    else if (_vektor.size() <= _n)
        _vektor.push_back(num);
    else
        throw std::out_of_range("No space left");
}

void Span::addManyNumbers(const unsigned int qty, const int & num_min)
{
    try
    {    
    if(qty < 2 )
        throw std::out_of_range("Please, enter valid amount of more than 1");
    else if (qty > UINT_MAX)
        throw std::out_of_range("Please, enter valid amount of numbers less than UINT_MAX");
    else if (qty > _n)
        throw std::out_of_range("Please, enter valid amount of numbers less than the size of the span.");


    if (num_min > INT_MAX)
        throw std::out_of_range("Please, enter valid number less than INT_MAX");
    else if (num_min < INT_MIN)
        throw std::out_of_range("Please, enter valid number more than INT_MIN");
    else if (num_min > INT_MAX || num_min < INT_MIN)
        throw std::out_of_range("Please, enter valid number");
    else if (num_min + qty > INT_MAX )
    {
        throw std::out_of_range("Please, enter valid number that  in limits of calculation");
    }

    if(qty >= _n)
        throw std::out_of_range("No space left");
    else
    {
        for (long m = num_min; m <= qty; m++)
        {   //std::cout << m << std::endl;
            _vektor.push_back(m);
        }
    }
    }
        catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

int Span::longestSpan()
{   
    if(_n < 2)
        throw SpanTooSmallException();
    std::vector<int> diff(_vektor.size());
    sort(_vektor.begin(), _vektor.end());
    std::vector<int>::iterator it_min = std::min_element(_vektor.begin(), _vektor.end());
    std::vector<int>::iterator it_max = std::max_element(_vektor.begin(), _vektor.end());
    return *it_max - *it_min;
}

int Span::shortestSpan()
{
    if(_n < 2)
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
    for(std::vector<int>::iterator it = vektor.begin(); it != vektor.end(); ++it)
    {
        out << *it << " ";
    }
    out << std::endl;
    return out;    
}