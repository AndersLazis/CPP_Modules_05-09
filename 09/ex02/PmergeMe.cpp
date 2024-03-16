
#include <unistd.h>
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
