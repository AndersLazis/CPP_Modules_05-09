/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:52:14 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/08 21:12:30 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/iter.hpp"

template <typename T>
void iter (T* arr, size_t size, void (*f)(T const &));


/* subject test */

class Awesome
{
public:
    Awesome( void ): _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
private:
    int _n;
};
std::ostream & operator<< (std::ostream & o, Awesome const & rhs )
{
     o << rhs.get();
     return o;
}

template<typename T >
void print( T x )
{ 
    std::cout << x << std::endl;
    return; 
}

int main()
{
    int tab[] = { 0, 1, 2, 3, 4 };
    Awesome tab2[5];
    iter(tab, 5, print);
    iter( tab2, 5, print);
    return 0; 
}




// void times_two(int const &n) 
// {
//     std::cout << n * 2 << std::endl;
// }

// void print(std::string const &s) 
// {
//     std::cout << s << std::endl;
// }

// int main(void) 
// {
//     int array[] = {1, 2, 3, 4, 5};

//     ::iter(array, 5, times_two);

//     std::string strings[] = {"s1", "s2", "s3"};

//     ::iter(strings, 3, print);
// }