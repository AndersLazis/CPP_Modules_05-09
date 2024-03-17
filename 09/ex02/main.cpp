/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:11:28 by aputiev           #+#    #+#             */
/*   Updated: 2024/03/17 18:47:09 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"


int main (int ac, char **av)
{   
    printfFancyTitle();
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

void printfFancyTitle()
{
    std::cout << PURPLE
    <<"\n  ____  _____  ____  ____         ____  _____  _   _  _  _  ___  _____  ___  _  _      __    __    ___  _____  ____  ____  ____  _   _  __  __ " << std::endl
    <<" ( ___)(  _  )(  _ \\(  _ \\  ___  (_  _)(  _  )( )_( )( \\( )/ __)(  _  )/ __)( \\( )    /__\\  (  )  / __)(  _  )(  _ \\(_  _)(_  _)( )_( )(  \\/  )"<< std::endl
    <<"  )__)  )(_)(  )   / )(_) )(___).-_)(   )(_)(  ) _ (  )  ( \\__ \\ )(_)( \\__ \\ )  (    /(__)\\  )(__( (_-. )(_)(  )   / _)(_   )(   ) _ (  )    ( "<< std::endl
    <<" (__)  (_____)(_)\\_)(____/      \\____) (_____)(_) (_)(_)\\_)(___/(_____)(___/(_)\\_)  (__)(__)(____)\\___/(_____)(_)\\_)(____) (__) (_) (_)(_/\\/\\_)" << std::endl
    << std::endl << RESET  << std::endl;    
    
}

