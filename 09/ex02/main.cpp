/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:11:28 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/16 18:50:46 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int main (int ac, char **av)
{
    if (ac <= 2)
    {
        std::cerr << RED << "Error: no input or input less than 2 arguments." << RESET << std::endl;
        return (1);
    }
    try
    {   
        PmergeMe instance(ac, av);
        instance.processVector();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << '\n';
        return (1);
    }    
    try
    {   
        PmergeMe instance(ac, av);
        instance.processList();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << '\n';
        return (1);
    }    
    return (0);
}

