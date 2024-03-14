

#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Colors.hpp"

#define VERBOSE 1

class PmergeMe
{
    private:          
        
        int* _array;
        std::vector<int> _vektor;        
        //std::list<int> _list;
        PmergeMe();
        void _createArray(int ac, char** av);

                
    public:
        PmergeMe(int ac, char** av);
        ~PmergeMe();
        PmergeMe(PmergeMe const & obj);
        PmergeMe & operator=(PmergeMe const & obj);
       // void process();
       
        
};

#endif