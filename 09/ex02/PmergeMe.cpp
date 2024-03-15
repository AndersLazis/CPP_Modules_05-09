

#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {} 

PmergeMe::~PmergeMe()
{
    if(_array)
        delete [] _array;
    if(_pairs)
        delete _pairs;

    _array = NULL;
    _pairs = NULL;
 }

PmergeMe::PmergeMe(int ac, char** av) : _size(ac-1), _array(NULL), _straggler(0), _isStraggler(false), _pairs(NULL)
{
    try
    {
        _createArray(av);
    }
    catch(const std::exception& e)
    {   
        this->~PmergeMe();
        throw;
    }
}

PmergeMe::PmergeMe(PmergeMe const & obj)
{
    *this = obj;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & obj)
{
    if (this != &obj)
    {
        return (*this);
    }
    return (*this);
}

void PmergeMe::processVector()
{   
    //std::clock_t vectorStartTime = std::clock();
    _createVector();    
    _checkVectorForDuplicates();
    _checkForStraggler();
    if(!_isVectorSorted())
        _sortVector();

        
    //std::clock_t vectorEndTime = std::clock();    
}

void PmergeMe::_createVector()
{
    for(int i = 0; i < _size; i++)
        _vektor.push_back(_array[i]);
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Input vector: \t[ ";
        for (int i = 0; i < _size; i++)
            std::cout << _vektor[i] << " ";
        std::cout << "]" << RESET << std::endl;
    }
    delete [] _array;
    _array = NULL;
}

void PmergeMe::_sortVector()
{   
    _createVectorOfPairs();
    _sortVectorOfPairs();
    
    

}

void PmergeMe::_sortVectorOfPairs()
{
    
}