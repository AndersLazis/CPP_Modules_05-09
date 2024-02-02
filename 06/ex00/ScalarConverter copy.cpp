/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:39:28 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/01 20:47:03 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScalarConverter.hpp"



ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    if(this != &copy)
        *this = copy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy)
{
    if(this != &copy)
        *this = copy;
    return (*this);
}

bool isLiteralValid(std::string const &literal)
{
    size_t length = literal.length();
    size_t dotPos = 0;
    size_t NumOfDots = 0;
    if(literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff")
        return (true);
    else if(length == 0)
        return (false);
    else if(length == 1 && isprint(literal[0]))
        return (true); 
    for (size_t i = 0; i < length; ++i)
    {
        if ((literal[i] == '-' || literal[i] == '+') && i != 0)
            return false;
        else if (literal[i] == 'f' && (i != length - 1))
            return false;
        else if (literal[i] == '.')
        {
            if (i == 0 || i == length - 1)
                return false;
            else
            {
                dotPos = i;
                NumOfDots++;
                if (NumOfDots > 1)
                    return false;
            }
        }
        else if (!isdigit(literal[i]))  
            return false;
    }
    return true;
}

void printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
} 

void printInt(std::string const &literal)
{   
     std::cout << "int: " << literal << std::endl;
   
}

void printChar(std::string const &literal)
{   
    char *endptr = NULL;
    if(literal[0] == '0' && literal.length() == 1)
        std::cout << "char: Non displayable" << std::endl;  
    else if(literal.length() == 1 && isprint(literal[0]) && literal[0] < '0' && literal[0] > '9') //if real char
        std::cout << "char: " << literal << std::endl;    
	else if (literal[literal.length() - 1] == 'f')
    {
		std::string withoutF = literal.substr(0, literal.length() - 1);
		float result = strtof(withoutF.c_str(), &endptr);
        int res = static_cast<int>(result);
        if(res >= 32 && static_cast<int>(result) <= 126)
            std::cout << "char: '" << static_cast<char>() << "'" << std::endl;		
	}



    
    else 
        std::cout << "char: impossible" << std::endl;  
}

void printFloat(std::string const &literal)
{
    std::cout << "float: " << literal << std::endl;
    return;
}

void printDouble(std::string const &literal)
{
    std::cout << "double: " << literal << std::endl;
    return;
}


void ScalarConverter::convert(std::string const &literal)
{
    if(isLiteralValid(literal))
    {
        printChar(literal);
        printInt(literal);
        printFloat(literal);
        printDouble(literal);
        return;
    }
    printImpossible();
    return;    
}