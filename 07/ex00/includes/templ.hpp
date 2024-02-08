/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templ.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:05:39 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/08 16:58:21 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP
#include <iostream>
#include <climits>
#include "Colors.hpp"


template <typename T>
T const & min (T const &a, T const &b)
{
    return a < b ? a : b;
}

template <typename T>
T const & max (T const &a, T const &b)
{
    return a > b ? a : b;
}

template <typename T>
void swap (T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/* my test */
class Awesome
{
public:
    Awesome( int n ) : _n( n ) {}
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int getN() const { return this->_n; }
private:
    int _n;
};

std::ostream &  operator << (std::ostream & o, Awesome const & rhs)
{
    o << rhs.getN();
    return o;
}

#endif
