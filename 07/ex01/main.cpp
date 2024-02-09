/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:52:14 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/09 11:06:53 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/iter.hpp"

template <typename T>
void iter (T* arr, size_t size, void (*f)(T const &));



/* subject test */

class my_class
{
    public:
        my_class( void ): _number( 999 ) 
		{
			return;
		}
        int getNumber( void ) const 
		{
			return this->_number;
		}
    private:
        int _number;
};

std::ostream & operator<< (std::ostream & o, my_class const & src )
{
     o << src.getNumber();
     return o;
}

template<typename T >
void print( T const &x )
{ 
    std::cout << x << std::endl;
    return; 
}

template<typename T >
void multiply( T const & x )
{ 
    std::cout << x*2 << std::endl;
    return; 
}

template <typename T>
void prefix( T const & x )
{
	std::cout << "prefix_" + x << std::endl;
	return;
}

int main()
{
    int arr[] = { 0, 1, 2, 3, 4, 5, 6 };
	std::string arr3[] = { "0", "1", "2", "3", "4" , "5", "6" };
    my_class arr2[5];
	std::cout << GREEN <<  "\nint array\n"<< RESET;	
    iter(arr, 5, print);
	std::cout<< GREEN <<  "\nmy_class array\n"<< RESET;	
    iter(arr, 5, multiply);
	std::cout << GREEN << "\nstring array\n"<< RESET;	
    iter( arr2, 5, print);
	std::cout << GREEN << "\nstring array with prefix\n" << RESET;	
	iter( arr3, 5, prefix);
    return 0; 
}

