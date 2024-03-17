
#include <unistd.h>
#include "includes/PmergeMe.hpp"

void PmergeMe::processVector()
{   
    std::cout << YELLOW << " ==================== * Processing vector... * ==================== " << RESET << std::endl;
    std::clock_t vectorStartTime = std::clock();
    _createVector();    
    _checkVectorForDuplicates();
   
    if(!_isVectorSorted(&_vektor))
    {           
        std::vector<int>* sortedVectorPtr = _sortVector();
        std::clock_t vectorTime = std::clock() - vectorStartTime;
        
        std::cout << GREEN << "\nSorted sequence: \t\t\t[ ";
        for (std::vector<int>::iterator it = sortedVectorPtr->begin(); it != sortedVectorPtr->end(); it++)
            std::cout << *it << " ";
        std::cout << "]\n" << RESET << std::endl; 
        if(VERBOSE)
        { 
            std::cout << CYAN <<"[verbose] size of sorted vector: "<< sortedVectorPtr->size() << RESET << std::endl;
            std::cout <<  std::endl << GREEN << "[verbose] [check] is vector correctly sorted: " << _isVectorSorted(sortedVectorPtr) << RESET << std::endl;
            if(sortedVectorPtr)
            {
                delete sortedVectorPtr;
                sortedVectorPtr = NULL;            
            }
        }
        printTime(vectorTime, _size);
    }
    else
    {
        std::clock_t vectorTime = std::clock() - vectorStartTime;
        printTime(vectorTime, _size);
    }
}

void PmergeMe::_createVector()
{
    for(int i = 0; i < _size; i++)
        _vektor.push_back(_array[i]);
    //delete [] _array;
    //_array = NULL;
}

std::vector<int>* PmergeMe::_sortVector()
{   
    //_createVectorOfPairs();
    _checkForStraggler();
    _pairs = new std::vector<std::pair<int, int> >;
    _merge(_vektor);
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Unsorted vector of pairs: \t[ ";
        for (std::vector<std::pair<int, int> >::iterator it = _pairs->begin(); it != _pairs->end(); it++)
            std::cout << "{" << it->first << ", " << it->second << "} ";
        std::cout << "]" << RESET << std::endl ;
    }
    _sortVectorOfPairs();
    std::vector<int>* sortedVectorPtr = _createSortedsequence();
    return sortedVectorPtr;
}



std::vector<int>* PmergeMe::_createSortedsequence()
{
    std::vector <int>* sorted = new std::vector<int>;
    sorted->push_back(_pairs->front().first);
    for (std::vector<std::pair<int, int> >::iterator it = _pairs->begin(); it != _pairs->end(); it++)
        sorted->push_back(it->second);
    if(sorted->size() == 2)
    {
        if(_isStraggler)
            _insertWithbinarySearch(sorted, _straggler);
        return sorted;
    }
    std::vector<int> unsorted;
    for (std::vector<std::pair<int, int> >::iterator it = _pairs->begin() + 1; it != _pairs->end(); it++)
        unsorted.push_back(it->first);
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Unsorted sequence: \t\t[ ";
        for (std::vector<int>::iterator it = unsorted.begin(); it != unsorted.end(); it++)
            std::cout << *it << " ";
        std::cout << "]" << RESET << std::endl;
    }

    std::vector<int> indexSequence = _createIndexInsertSequence(unsorted.size());
    for (std::vector<int>::iterator itr = indexSequence.begin(); itr != indexSequence.end(); itr++)
    {
        int number = unsorted[*itr-1];
        _insertWithbinarySearch(sorted, number);
    }
    if(_isStraggler)
        _insertWithbinarySearch(sorted, _straggler);
    return sorted;
}


void PmergeMe::_insertWithbinarySearch(std::vector<int>* sorted, int number)
{
    long long mid = 0;
    long long leftLimit = 0;
    long long rightLimit = sorted->size();
    while (leftLimit < rightLimit)
    {
        mid = (leftLimit + rightLimit) / 2;
        if (number < ((*sorted)[mid]))
            rightLimit = mid;
        else
            leftLimit = mid + 1;
    }

    sorted->insert(sorted->begin() + leftLimit, number);
}




std::vector<int> PmergeMe::_createIndexInsertSequence(long long size)
{
    bool previousIsJacobNumber = false;
    std::vector<int> indexSequence;
    long long lastJacobNumber = 1;
    long long currentJacobNumber = 1;
    long long reverseIndex = 0;
    long long index = 2;

    indexSequence.push_back(1);
    if(size == 1)
        return indexSequence;
    
    std::vector<int> JacobSequence = _createJacobSequence(size);
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Jacob sequence: \t\t[ ";
        for (std::vector<int>::iterator it = JacobSequence.begin(); it != JacobSequence.end(); it++)
            std::cout << *it << " ";
        std::cout << "]" << RESET << std::endl;
    }

    while( index <= size )
    {
        if(JacobSequence.size() != 0 && previousIsJacobNumber == false)
        {
            indexSequence.push_back(JacobSequence.front());
            index++;
            lastJacobNumber = currentJacobNumber;
            currentJacobNumber = JacobSequence.front();
            reverseIndex = currentJacobNumber - 1;
            JacobSequence.erase(JacobSequence.begin());            
            previousIsJacobNumber = true;            
            continue;
        }
        else if(reverseIndex > lastJacobNumber)
        {
            while(reverseIndex > lastJacobNumber)
            {
                indexSequence.push_back(reverseIndex);
                index++;
                previousIsJacobNumber = false;
                reverseIndex--;
            }

            lastJacobNumber = currentJacobNumber;
        }
        else if(JacobSequence.size() == 0 )
        {
            indexSequence.push_back(index);
            index++;
        }
    }
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Index sequence: \t\t[ ";
        for (std::vector<int>::iterator it = indexSequence.begin(); it != indexSequence.end(); it++)
            std::cout << *it << " ";
        std::cout << "]" << RESET << std::endl;
    }
    return indexSequence;
}

std::vector<int> PmergeMe::_createJacobSequence(long long size )
{
    std::vector<int> JacobSequence;
    long long j = 3;
    while( _getJacobNumber(j) < size - 1)
    {
        JacobSequence.push_back(_getJacobNumber(j));
        j++;
    }
    return JacobSequence;
}



int PmergeMe::_getJacobNumber(int n)
{
	if (n == 0)
		return 0 ;
	if(n == 1)
		return 1;
	return ( _getJacobNumber( n - 1 ) + 2 * _getJacobNumber( n - 2 ) );
}



// void PmergeMe::_sortVectorOfPairs()
// {   
//     for (std::vector<std::pair<int, int> >::iterator it = _pairs->begin(); it != _pairs->end(); it++)
//     {
//         std::pair<int, int> temp  = *it;
//         std::vector<std::pair<int, int> >::iterator itr = it;

//         if (itr == _pairs->begin())
//             continue;
        
//         while(temp.second < ((--itr)->second) && itr != _pairs->begin())
//         {
//             --itr;
//         }
//         _pairs->erase(it);
//         _pairs->insert(itr, temp);
//         it = itr;        
//     }
// }

void PmergeMe::_sortVectorOfPairs()
{
  for (std::vector<std::pair<int, int> >::iterator  it = (_pairs->begin()+1); it != _pairs->end(); ++it) {
    std::pair<int, int>  temp = *it;
    std::vector<std::pair<int, int> >::iterator  itr = it - 1;
        
    while(itr >= _pairs->begin() && ((itr->second) > temp.second))
    {        
        *(itr+1) = *itr;
        itr--;
    }
    *(itr+1) = temp;
  }
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Sorted vector of pairs: \t[ ";
        for (std::vector<std::pair<int, int> >::iterator it = _pairs->begin(); it != _pairs->end(); it++)
            std::cout << "{" << it->first << ", " << it->second << "} ";
        std::cout << "]" << RESET << std::endl;
    }
 }