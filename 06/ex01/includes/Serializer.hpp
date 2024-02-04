/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:05:39 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/04 21:41:19 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <string>
#include "Data.hpp"
#include <iostream>

#include <stdint.h>


# define GREEN	"\e[32m"
# define RESET	"\e[0m"


class Serializer
{
    private:  
        Serializer();
        Serializer(const Serializer &copy); 
        
    public:  
         
         Serializer &operator=(const Serializer &copy);
        virtual ~Serializer() =0;
        
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
