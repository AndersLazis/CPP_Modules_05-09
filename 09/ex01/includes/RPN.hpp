/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:22:44 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/12 15:42:42 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include "Colors.hpp"

#define NUMBER          1   
#define OPERATOR        2

class RPN
{
    private:
        std::string _input;
        std::stack<int> _stack;
                
        RPN();
        bool _isTokenValid(std::string const &token);
        void _processToken(std::string &token);
        int _state;

        
    public:
        RPN(std::string input);
        ~RPN();
        RPN(RPN const & obj);
        RPN & operator=(RPN const & obj);
        void process();
        
        
};

#endif

