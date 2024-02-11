/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:05:39 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/10 18:57:44 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <iostream>
#include <string>
#include "Colors.hpp"

template <typename T>
void iter (const T* arr, size_t size, void (*func)( const T &))
{
    for (size_t i = 0; i < size; i++)
    {
        func(arr[i]);
    }
    return;
}

template <typename T>
void iter (T* arr, size_t size, void (*func)(T&))
{
    for (size_t i = 0; i < size; i++)
    {
        func(arr[i]);
    }
    return;
}


#endif
