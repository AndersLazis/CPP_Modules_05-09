/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:45:07 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/12 21:57:30 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include "Colors.hpp"


template <typename T, typename C = std::deque<T> >

class MutantStack : public std::stack<T, C>
{
    public:
        MutantStack<T, C>(): std::stack<T, C>() {};
        MutantStack<T, C>(MutantStack<T,C> const &src): std::stack<T, C>(src){};
        ~MutantStack<T, C>(){};
        MutantStack<T, C> &operator=(MutantStack<T, C> const &src)
        {
            if(this != src)
                return *this;
            return *this;
        }
    
        typedef typename std::stack<T, C>::container_type::iterator                     iterator;
        typedef typename std::stack<T, C>::container_type::const_iterator               const_iterator;
        typedef typename std::stack<T, C>::container_type::reverse_iterator             reverse_iterator;
        typedef typename std::stack<T, C>::container_type::const_reverse_iterator       const_reverse_iterator;

        MutantStack <T,C>::iterator begin()
        {
            return (this->c.begin());
        }

        MutantStack <T,C>::iterator end()
        {
            return (this->c.end());
        }

        MutantStack <T,C>::const_iterator cbegin() const
        {
            return (this->c.begin());
        }

        MutantStack <T,C>::const_iterator cend() const
        {
            return (this->c.end());
        }

        MutantStack <T,C>::reverse_iterator rbegin()
        {
            return (this->c.rbegin());
        }

        MutantStack <T,C>::reverse_iterator rend()
        {
            return (this->c.rend());
        }

        MutantStack <T,C>::const_reverse_iterator crbegin() const
        {
            return (this->c.rbegin());
        }

        MutantStack <T,C>::const_reverse_iterator crend() const
        {
            return (this->c.rend());
        }


     private:

};

#endif