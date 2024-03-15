
#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <climits>
#include <cstdlib>

#include <ctime>
#include "Colors.hpp"


#define VERBOSE 1

class PmergeMe
{
    private:          
        
        long long   _size;
        int*        _array;

        /* Vector variables: */
        int         _straggler;
        bool        _isStraggler;
        std::vector<std::pair<int, int> >* _pairs;

        std::vector<int> _vektor;        
        //std::list<int> _list;
        PmergeMe();
        void _createArray(char** av);



    /* Vector methods: */
        void _createVector();
        void _checkVectorForDuplicates();
        bool _isVectorSorted();
        void _sortVector();
        void _checkForStraggler();
        void _createVectorOfPairs();
        void _sortVectorOfPairs();

                
    public:
        PmergeMe(int ac, char** av);
        ~PmergeMe();
        PmergeMe(PmergeMe const & obj);
        PmergeMe & operator=(PmergeMe const & obj);
        void processVector();
       
        
};

#endif