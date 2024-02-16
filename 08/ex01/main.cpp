/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:12:08 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/16 21:00:56 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <algorithm>
#include "includes/Span.hpp"
#include <vector>
#include <list>
#include <deque>
#include <stack>

int main(void) {
        
//std::cout << YELLOW << "\n -------------- #1  TEST  -------------- " << RESET << std::endl;
    
    Span sp(3);
    try{
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
       std::cout << sp;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
