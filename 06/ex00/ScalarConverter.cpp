/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:39:28 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/04 14:49:03 by aputiev          ###   ########.fr       */
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


int defineType(std::string &literal)
{
    size_t length = literal.length();
    size_t dotPos = 0;
    bool nonzero = false;   
    size_t NumOfDots = 0;
    
    std::cout << "  === defineType === " << RESET <<  std::endl;
    if(literal == "nan" || literal == "nanf" || literal == "+inf" || 
        literal == "+inff" || literal == "-inf" || literal == "-inff" || literal == "inf" || literal == "inff")
        return (NOTANUMBER);
    else if(length == 0)
        return (WRONGARG);
    else if(length == 1 && (isprint(literal[0]) != 0) && (literal[0] < '0' || literal[0] > '9') && literal[0] != '0')
        return (CHAR); 
    if(literal[0] == '+' && length > 1){
       literal  = literal.substr(1, length - 1);
       length = literal.length();
    }
    
    /* parsing */
    for (size_t i = 0; i < length; ++i)
    {   
        if (literal[i] != '0' && literal[i] != '.' && literal[i] != '-' && literal[i] != '+')
            nonzero = true;
        if ((literal[i] == '-' || literal[i] == '+') && i != 0)
            return (WRONGARG);
        else if (literal[i] == 'f' && ((i != length - 1) || i == dotPos+1))
            return WRONGARG;       
        else if (literal[i] == '.')
        {   
            if (nonzero == false && i > 1)
                return WRONGARG;
            if (i == 0 || i == length - 1)
                return WRONGARG;
            else
            {
                dotPos = i;
                NumOfDots++;
                if (NumOfDots > 1)
                    return WRONGARG;
            }
        }
        else if ((!isdigit(literal[i]) && literal[i]!='-') && (literal[length - 1] != 'f'))  
            return WRONGARG;
    }
    if(NumOfDots == 0 && literal[length - 1] != 'f')
        return INT;
    else if(NumOfDots == 1 && literal[length - 1] == 'f')
        return FLOAT;
    else if(NumOfDots == 1 && literal[length - 1] != 'f')
        return DOUBLE; 
    else 
        return WRONGARG;
}

void printImpossible(std::string  &literal)
{   std::cout << GREEN << "  === printImpossible === " << std::endl;
    (void)literal;
    std::cout << GREEN << "char: impossible" << RESET << std::endl;
    std::cout << GREEN << "int: impossible" << RESET << std::endl;
    std::cout << GREEN << "float: nanf" << RESET << std::endl;
    std::cout << GREEN << "double: nan" << RESET << std::endl;
} 

void printNAN(std::string  &literal)
{   std::cout << GREEN << "  === printNAN === "  << RESET << std::endl;
    std::cout << GREEN << "char: impossible" << RESET << std::endl;
    std::cout << GREEN << "int: impossible" << RESET << std::endl;
    if(literal == "nan" || literal == "nanf")
    {       
        std::cout << GREEN << "float: nanf" << RESET << std::endl;
        std::cout << GREEN << "double: nan" << RESET << std::endl;
    }
    else if(literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
    {
        std::cout << GREEN << "float: +inff" << RESET << std::endl;
        std::cout << GREEN << "double: +inf" << RESET << std::endl;
    } 
    else if(literal == "-inf" || literal == "-inff")
    {
        std::cout << GREEN << "float: -inff" << RESET << std::endl;
        std::cout << GREEN << "double: -inf" << RESET << std::endl;
    }
}

void printChar(std::string  &literal)
{   std::cout << GREEN << "  === printCHAR === " << RESET << std::endl;
    std::cout << GREEN << "char: \'" << literal << "\'" << RESET << std::endl;    
    std::cout << GREEN << "int: " << static_cast<int>(literal[0]) << RESET << std::endl;
    std::cout << GREEN << "float: " << static_cast<float>(literal[0]) << ".0f" << RESET << std::endl;
    std::cout << GREEN << "double: " << static_cast<double>(literal[0])  << ".0" << RESET << std::endl;       
}

void printInt(std::string  &literal)
{   std::cout << GREEN << "  === printInt === " << std::endl;
    /* char */
    if((strtol(literal.c_str(), nullptr, 10)) > 32 && strtol(literal.c_str(), nullptr, 10) <= 127)    
        std::cout << GREEN << "char: \'" <<  static_cast<char>(strtof(literal.c_str(), nullptr)) << "\'" <<RESET << std::endl; 
    else if((strtol(literal.c_str(), nullptr, 10)) >=0 && strtol(literal.c_str(), nullptr, 10) <= 32) 
        std::cout << GREEN << "char: Non displayable" << RESET << std::endl;
    else
        std::cout << GREEN << "char: impossible" << RESET << std::endl;        
    /* int */        
    if((strtol(literal.c_str(), nullptr, 10)) > INT_MAX || strtol(literal.c_str(), nullptr, 10) <= INT_MIN)
         std::cout << GREEN << "int: impossible" << RESET << std::endl;
    else 
        std::cout << GREEN << "int: " << strtol(literal.c_str(), nullptr, 10) << RESET << std::endl;
        
    /* float */
    if((strtol(literal.c_str(), nullptr, 10)) > INT_MAX || strtol(literal.c_str(), nullptr, 10) <= INT_MIN)
         std::cout << GREEN << "float: impossible" << RESET << std::endl;
    else 
        std::cout << GREEN << "float: " << static_cast<float>(strtol(literal.c_str(), nullptr, 10)) << ".0f" << RESET << std::endl;

    /* double */
   if((strtol(literal.c_str(), nullptr, 10)) > INT_MAX || strtol(literal.c_str(), nullptr, 10) <= INT_MIN)
         std::cout << GREEN << "double: impossible" << RESET << std::endl;
    else 
        std::cout << GREEN << "double: " << static_cast<double>(strtol(literal.c_str(), nullptr, 10)) << ".0" << RESET << std::endl;
}

void printFloat(std::string &literal)
{   std::cout << GREEN << "  === printFloat === " << std::endl;
    /* char */
     if((strtof(literal.c_str(), nullptr)) > 32 && strtof(literal.c_str(), nullptr) <= 127)    
       std::cout << GREEN << "char: \'" <<  static_cast<char>(strtof(literal.c_str(), nullptr)) << "\'" << RESET << std::endl; 
    else if((strtof(literal.c_str(), nullptr)) >=0 && strtof(literal.c_str(), nullptr) <= 32) 
        std::cout << GREEN << "char: Non displayable" << RESET << std::endl;
    else
        std::cout << GREEN << "char: impossible" << RESET << std::endl;
        
    /* int */        
    if((strtof(literal.c_str(), nullptr)) > INT_MAX || strtof(literal.c_str(), nullptr) <= INT_MIN)
         std::cout << GREEN << "int: impossible" << RESET << std::endl;
    else 
        std::cout << GREEN << "int: " << static_cast<int>(strtof(literal.c_str(), nullptr)) << RESET << std::endl;
        
    /* float */
    if((strtof(literal.c_str(), nullptr)) > FLT_MAX || strtof(literal.c_str(), nullptr) <= -FLT_MAX)
         std::cout << GREEN << "float: impossible" << RESET << std::endl;
    else if (strtod(literal.c_str(), nullptr) < FLT_MIN && strtod(literal.c_str(), nullptr) > -FLT_MIN)
        std::cout << GREEN << "float: 0.0f" << RESET << std::endl;
    else
    {
        std::cout << GREEN << "float: " << strtof(literal.c_str(), nullptr) ;
        if(((strtof(literal.c_str(), nullptr)/strtol(literal.c_str(), nullptr, 10)) == 1) || strtof(literal.c_str(), nullptr) == 0)
            std::cout << ".0f\n";
         else
             std::cout << "f\n";
    }

    /* double */
    if((strtof(literal.c_str(), nullptr)) > FLT_MAX  || strtof(literal.c_str(), nullptr) <= -FLT_MAX)
         std::cout << GREEN << "double: impossible" ;
    else if (strtod(literal.c_str(), nullptr) < DBL_MIN && strtod(literal.c_str(), nullptr) > -DBL_MIN)
        std::cout << GREEN << "double: 0.0" << RESET << std::endl;
    else
    { 
        std::cout << GREEN << "double: " << static_cast<double>(strtof(literal.c_str(), nullptr));
        if(((strtof(literal.c_str(), nullptr)/strtol(literal.c_str(), nullptr, 10)) == 1) || strtof(literal.c_str(), nullptr) == 0)
            std::cout << ".0";        
    }
    std::cout << RESET  << std::endl;
}

void printDouble(std::string  &literal)
{   std::cout << GREEN << "  === printDouble === " << std::endl;
    /* char */
    if((strtod(literal.c_str(), nullptr)) > 32 && strtod(literal.c_str(), nullptr) <= 127)    
       std::cout << GREEN << "char: \'" <<  static_cast<char>(strtof(literal.c_str(), nullptr)) << "\'" << std::endl; 
    else if((strtod(literal.c_str(), nullptr)) >=0 && strtod(literal.c_str(), nullptr) <= 32) 
        std::cout << GREEN << "char: Non displayable" << RESET << std::endl;
    else
        std::cout << GREEN << "char: impossible" << RESET << std::endl;
        
    /* int */      
    if((strtod(literal.c_str(), nullptr)) > INT_MAX || strtod(literal.c_str(), nullptr) <= INT_MIN)
         std::cout << GREEN << "int: impossible" << RESET << std::endl;
    else 
        std::cout << GREEN << "int: " <<  static_cast<int>(strtod(literal.c_str(), nullptr)) << RESET << std::endl;
        
    /* float */
    if((strtod(literal.c_str(), nullptr)) > FLT_MAX || strtod(literal.c_str(), nullptr) <= -FLT_MAX)
         std::cout << GREEN << "float: impossible" << RESET << std::endl;
    else if (strtod(literal.c_str(), nullptr) < FLT_MIN && strtod(literal.c_str(), nullptr) > -FLT_MIN)
        std::cout << GREEN << "float: 0.0f" << RESET << std::endl;
    else        
    {
        std::cout << GREEN << "float: " <<  static_cast<float>(strtod(literal.c_str(), nullptr));
        if(((strtod(literal.c_str(), nullptr)/strtol(literal.c_str(), nullptr, 10)) == 1) || strtod(literal.c_str(), nullptr) == 0)
            std::cout << ".0f\n";
         else
             std::cout << "f\n";
    }
        
    /* double */
    if((strtod(literal.c_str(), nullptr)) > DBL_MAX || strtod(literal.c_str(), nullptr) <= -DBL_MAX)
         std::cout << GREEN << "double: impossible" << std::endl;
    else if (strtod(literal.c_str(), nullptr) < DBL_MIN && strtod(literal.c_str(), nullptr) > -DBL_MIN)
        std::cout << GREEN << "double: 0.0" << RESET << std::endl;
    else 
    { 
        std::cout << GREEN << "double: " << static_cast<double>(strtod(literal.c_str(), nullptr));
        if(((strtod(literal.c_str(), nullptr)/strtol(literal.c_str(), nullptr, 10)) == 1) || strtod(literal.c_str(), nullptr) == 0)
            std::cout << ".0";        
    }
    std::cout << RESET  << std::endl;
}

void ScalarConverter::convert(std::string &literal)
{

    void (*printPtr[7])(std::string &literal);
    printPtr[CHAR] = printChar;
    printPtr[INT] = printInt;
    printPtr[FLOAT] = printFloat;
    printPtr[DOUBLE] = printDouble;
    printPtr[NOTANUMBER] = printNAN;
    printPtr[WRONGARG] = printImpossible;
            
    printPtr[defineType(literal)](literal);
    return;    
}