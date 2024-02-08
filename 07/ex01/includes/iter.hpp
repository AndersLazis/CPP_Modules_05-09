/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:05:39 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/08 21:12:05 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"

template <typename T>

void iter (T* arr, size_t size, void (*func)(T const &))
{
    for (size_t i = 0; i < size; i++)
    {
        func(arr[i]);
    }
    return;
}

#endif






// #pragma once

// #include <iostream>
// #include <string>

// template<typename T>

// void iter(T *array, size_t size, void(*f)(T const &)) 
// {
//     for (size_t i = 0; i < size; i++) 
// 	{
//         f(array[i]);
//     }
// }