
#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <climits>
#include <cstdlib>
#include <iterator>
#include <ctime>
#include "Colors.hpp"


#define VERBOSE 0

class PmergeMe
{
    private:          
        
        long long                           _size;
        int*                                _array;

    /* Vector variables: */
        int                                 _straggler;
        bool                                _isStraggler;
        std::vector<std::pair<int, int> >*  _pairs;
        std::list<std::pair<int, int> >*    _list_pairs;
        std::vector<int>                    _vektor;
        std::list<int>                      _list;

    /* Common methods: */
                            PmergeMe();
        void                _createArray(char** av);
        std::vector<int>    _createIndexInsertSequence(long long size);
        void                printTime(std::clock_t time, int range);

    /* Vector methods: */
        void                _createVector();
        void                _checkVectorForDuplicates();
        bool                _isVectorSorted(std::vector<int>* vektor);
        std::vector<int>*   _sortVector();
        void                _checkForStraggler();
        void                _sortVectorOfPairs();
        void                _merge(std::vector<int> vektor);
        std::vector<int>*   _createSortedsequence();
        std::vector<int>    _createJacobSequence(long long size );
        int                 _getJacobNumber(int n);
        void                _insertWithbinarySearch(std::vector<int>* sorted, int number);

    /* List methods */
        void                _createList();
        void                _checkListForDuplicates();
        bool                _isListSorted(std::list<int>* list);
        std::list<int>*     _sortList();
        void                _checkListForStraggler();
        void                _createListOfPairs();
        void                _sortListOfPairs();
        void                _merge(std::list<int> list);
        std::list<int>*     _createListSortedsequence();    
        void                _insertWithbinarySearch(std::list<int>* sorted, int number);



    public:
                    PmergeMe(int ac, char** av);
                    ~PmergeMe();
                    PmergeMe(PmergeMe const & obj);
        PmergeMe &  operator=(PmergeMe const & obj);
        void        processVector();
        void        processList();             
};

void printfFancyTitle();
#endif