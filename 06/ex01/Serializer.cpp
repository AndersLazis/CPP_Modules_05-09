/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:04:50 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/04 21:31:09 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serializer.hpp"


Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &copy)
{
    if(this != &copy)
        *this = copy;
}

Serializer & Serializer::operator=(const Serializer &copy)
{
    if(this != &copy)
        *this = copy;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}