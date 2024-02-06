/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:52:14 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/06 17:36:06 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serializer.hpp"
#include "includes/Data.hpp"
#include <iostream>

int main()
{
    try
    {   
        //Serializer s;
        Data* dataPtr = new Data;
        dataPtr->n = 42;
        dataPtr->s1 = "Hello, World!";
        std::cout << "\nOriginal: \t" << dataPtr << "n: " << dataPtr->n << "; s1: " << dataPtr->s1 << std::endl;
        
        uintptr_t serialized = Serializer::serialize(dataPtr);
        Data* deserialized = Serializer::deserialize(serialized);
        std::cout << "Deserialized: \t" << deserialized << "n: " << deserialized->n << "; s1: " << deserialized->s1 << std::endl << std::endl;
        if(dataPtr)
            delete dataPtr;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

