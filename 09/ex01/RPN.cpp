/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:23:45 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/12 16:28:59 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(std::string input) : _input(input), _state(0)
{
    if(input.empty())
        throw std::invalid_argument("Error: no input.");
}

RPN::RPN(RPN const & obj)
{
    *this = obj;
}

RPN & RPN::operator=(RPN const & obj)
{
    if (this != &obj)
    {
        this->_input = obj._input;
    }
    return (*this);
}

void RPN::process()
{
    while(!_input.empty())
    {
        const unsigned long space_pos = _input.find(" ");

        std::string token = _input.substr(0, space_pos);
        //std::cout << GREEN << "Token: " << token << RESET << std::endl;
        if(_isTokenValid(token))
            _processToken(token);
        //std::cout << "operation result " << _stack.top() << std::endl;
        _input.erase(0, space_pos+1);
        if(space_pos == std::string::npos)
            break;
    }
    int result = _stack.top();
    _stack.pop();
    if(!_stack.empty())
        throw std::runtime_error("Error: not enough operators for numbers.");
    std::cout << GREEN << "Result: " << result << RESET << std::endl;
}

bool RPN::_isTokenValid(std::string const &token)
{
    if(token.empty())
        throw std::runtime_error("Error: empty token." + token);
    else if(token.length() == 1 && isdigit(token[0]))
    {
        _state = NUMBER;
        return true;
    }
    else if (token.length() == 2 && token[0] == '-' && isdigit(token[1]))
    {
        _state = NUMBER;
        return true;
    }
    else if ((token.length() == 1) && (token == "-" || token == "+" || token == "*" || token == "/"))
    {
        _state = OPERATOR;
        return true;
    }
    else 
        throw std::runtime_error("Error: invalid token." + token);
    
}

void RPN::_processToken(std::string &token)
{   
    int number;
    int second_number;
    std::stringstream ss(token);
    switch (_state)
    {
        case NUMBER:            
            ss >> number;
            _stack.push(number);
            break;
        case OPERATOR:
            if(_stack.size() < 2)
                throw std::runtime_error("Error: not enough numbers for operation.");
            number = _stack.top();
            _stack.pop();
            second_number = _stack.top();
            _stack.pop();
            if (token == "+")
                _stack.push(second_number + number);
            else if (token == "-")
                _stack.push(second_number - number);
            else if (token == "*")
                _stack.push(second_number * number);
            else if(token == "/" && number == 0)
                throw std::runtime_error("Error: division by zero.");
            else if (token == "/")
                _stack.push(second_number / number);            
            break;
    }
}