/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:11:28 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/11 23:11:31 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
$> ./btc
Error: could not open file. $> ./btc input.txt
2011-01-03 => 3 = 0.9 2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3 2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42 2012-01-11 => 1 = 7.1
Error: too large a number. $>
*/

#include "includes/BitcoinExchange.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: no file." << std::endl;
        return (1);
    }
    std::string filename = av[1];
    try
    {   
        BitcoinExchange b(filename);
        b.process(filename);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return (0);
}

