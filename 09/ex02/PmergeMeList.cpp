
#include <unistd.h>
#include "includes/PmergeMe.hpp"

void PmergeMe::processList()
{   
    std::cout << YELLOW << " ==================== * Processing List... * ==================== " << RESET << std::endl;
    std::clock_t ListStartTime = std::clock();
    _createList();
    _checkListForDuplicates();
   
    if(!_isListSorted(&_list))
    {           
         std::list<int>* sortedListPtr = _sortList();
         std::clock_t ListTime = std::clock() - ListStartTime;
        
         std::cout << GREEN << "\nSorted sequence: \t\t\t[ ";
         for (std::list<int>::iterator it = sortedListPtr->begin(); it != sortedListPtr->end(); it++)
             std::cout << *it << " ";
         std::cout << "]\n" << RESET << std::endl; 
         if(VERBOSE)
        { 
            std::cout << CYAN <<"[verbose] size of sorted List: "<< sortedListPtr->size() << RESET << std::endl;
            std::cout <<  std::endl << GREEN << "[verbose] [check] is List correctly sorted: " << _isListSorted(sortedListPtr) << RESET << std::endl;
            if(sortedListPtr)
            {
                delete sortedListPtr;
                sortedListPtr = NULL;            
            }
        }
         printTime(ListTime, _size);
    //(void)sortedListPtr; //FIXME: remove this line
    }
    else
    {
         std::clock_t ListTime = std::clock() - ListStartTime;
         printTime(ListTime, _size);
    }
}

void PmergeMe::_createList()
{
    for(int i = 0; i < _size; i++)
        _list.push_back(_array[i]);
    delete [] _array;
    _array = NULL;
}

std::list<int>* PmergeMe::_sortList()
{   
    //_createListOfPairs();
    _checkListForStraggler();
    _list_pairs = new std::list<std::pair<int, int> >;
    _merge(_list);
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Unsorted list of pairs: \t[ ";
        for (std::list<std::pair<int, int> >::iterator it = _list_pairs->begin(); it != _list_pairs->end(); it++)
            std::cout << "{" << it->first << ", " << it->second << "} ";
        std::cout << "]" << RESET << std::endl ;
    }
    _sortListOfPairs();
    std::list<int>* sortedVectorPtr = _createListSortedsequence();
    return sortedVectorPtr;
}



std::list<int>* PmergeMe::_createListSortedsequence()
{
    std::list <int>* sorted = new std::list<int>;
    sorted->push_back(_list_pairs->front().first);
    for (std::list<std::pair<int, int> >::iterator it = _list_pairs->begin(); it != _list_pairs->end(); it++)
        sorted->push_back(it->second);
    if(sorted->size() == 2)
    {
        if(_isStraggler)
            _insertWithbinarySearch(sorted, _straggler);
        return sorted;
    }
    std::list<int> unsorted;
    std::list<std::pair<int, int> >::iterator itm = _list_pairs->begin();
    itm++;
    for (; itm != _list_pairs->end(); itm++)
        unsorted.push_back(itm->first);

    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Unsorted sequence: \t\t[ ";
        for (std::list<int>::iterator it = unsorted.begin(); it != unsorted.end(); it++)
            std::cout << *it << " ";
        std::cout << "]" << RESET << std::endl;
    }
    std::vector<int> indexSequence = _createIndexInsertSequence(unsorted.size());
    for (std::vector<int>::iterator itr = indexSequence.begin(); itr != indexSequence.end(); itr++)
    {   
        std::list<int>::iterator its = unsorted.begin();
        std::advance(its, *itr-1);
        int number = *its;
        _insertWithbinarySearch(sorted, number);
    }
    if(_isStraggler)
        _insertWithbinarySearch(sorted, _straggler);
    return sorted;
}


void PmergeMe::_insertWithbinarySearch(std::list<int>* sorted, int number)
{
   
    long long mid = 0;
    long long leftLimit = 0;
    long long rightLimit = sorted->size();
    while (leftLimit < rightLimit)
    {
        mid = (leftLimit + rightLimit) / 2;
        std::list<int>::iterator it = sorted->begin();
        std::advance(it, mid);



        if (number < (*it))
            rightLimit = mid;
        else
            leftLimit = mid + 1;
    }
    std::list<int>::iterator itr = sorted->begin();
    std::advance(itr, leftLimit);
    sorted->insert(itr, number);
}


// std::vector<int> PmergeMe::_createJacobSequence(long long size )
// {
//     std::vector<int> JacobSequence;
//     long long j = 3;
//     while( _getJacobNumber(j) < size - 1)
//     {
//         JacobSequence.push_back(_getJacobNumber(j));
//         j++;
//     }
//     return JacobSequence;
// }



// int PmergeMe::_getJacobNumber(int n)
// {
// 	if (n == 0)
// 		return 0 ;
// 	if(n == 1)
// 		return 1;
// 	return ( _getJacobNumber( n - 1 ) + 2 * _getJacobNumber( n - 2 ) );
// }




void PmergeMe::_sortListOfPairs()
{  
    int i = 1;
    std::list<std::pair<int, int> >::iterator  it_begin_next = _list_pairs->begin();
    it_begin_next++;
    for (std::list<std::pair<int, int> >::iterator  it = it_begin_next; it != _list_pairs->end(); ++it)
    {
        std::pair<int, int> temp = *it;
        std::list<std::pair<int, int> >::iterator  itr = it;
        --itr;
        
        while(itr != _list_pairs->begin() && ((itr->second) > temp.second))
        {
            std::list<std::pair<int, int> >::iterator  itr_next = itr;
            itr_next++;
            *(itr_next) = *itr;
            itr--;
        }
        if(itr == _list_pairs->begin() && ((itr->second) > temp.second))
        {
            std::list<std::pair<int, int> >::iterator  itr_next2 = itr;
            itr_next2++;
            *(itr_next2) = *itr;
            *itr = temp;
              
        }
        else
        {
            std::list<std::pair<int, int> >::iterator  itr_next3 = itr;
            itr_next3++;
            *(itr_next3) = temp;
        }
        
        i++;
    }
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Sorted list of pairs: \t[ ";
        for (std::list<std::pair<int, int> >::iterator it = _list_pairs->begin(); it != _list_pairs->end(); it++)
            std::cout << "{" << it->first << ", " << it->second << "} ";
        std::cout << "]" << RESET << std::endl;
    }
}

