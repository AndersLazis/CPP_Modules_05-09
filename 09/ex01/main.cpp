/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:11:28 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/12 14:28:07 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/RPN.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: no input." << std::endl;
        return (1);
    }
    std::string filename = av[1];
    try
    {   
        RPN rpn(filename);
        rpn.process();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return (0);
}

