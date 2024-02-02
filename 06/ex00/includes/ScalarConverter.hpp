/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:58:39 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/02 16:39:50 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <string>
#include <cfloat>
#include "limits.h"
#include <iostream>
#include <cstdlib>

# define GREEN	"\e[32m"
# define RESET	"\e[0m"

enum type {CHAR, INT, FLOAT, DOUBLE, NOTANUMBER, WRONGARG};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);
public:
   
    ~ScalarConverter();
    static void convert(std::string &literal);
};

#endif
