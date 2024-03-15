

#include "includes/PmergeMe.hpp"

void PmergeMe::_createArray(char** av)
{
    long long int temp;

    if(_size > INT_MAX)
        throw std::invalid_argument("invalid argument. Too many arguments.");
    _array = new int[_size];
    for (int i = 1; i < _size + 1; i++)
    {   
        if(std::string(av[i]).empty())
            throw std::invalid_argument("invalid argument. Argument is empty.");
        for(int j = 0; av[i][j] != '\0'; j++)
        {
            if (!std::isdigit(av[i][j]))
                throw std::invalid_argument("invalid argument. Argument is not a positive number: [" + std::string(av[i]) + "].");
        }
        temp = std::atol(av[i]);
        if (temp > INT_MAX || temp < 0)
            throw std::invalid_argument("invalid argument. Argument is out of limits: [" + std::string(av[i]) + "].");
        _array[i-1] = temp;        
    }
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Input array: \t\t[ ";
        for (int i = 0; i < _size; i++)
            std::cout << _array[i] << " ";
        std::cout << "]"<< RESET << std::endl;
    }
}


void PmergeMe::_checkVectorForDuplicates()
{   
    for(std::vector<int>::iterator it = _vektor.begin(); it != _vektor.end(); it++)
        for(std::vector<int>::iterator it2 = it+1; it2 != _vektor.end(); it2++)
            if (*it == *it2)
                throw std::invalid_argument("invalid argument. Duplicate has been found");
}


bool PmergeMe::_isVectorSorted()
{
    for(std::vector<int>::iterator it = _vektor.begin(); it != _vektor.end()-1; it++)
        if (*it > *(it+1))
            return false;
    return true;
}

void PmergeMe::_checkForStraggler()
{
    if(_size % 2 != 0)
    {
        _isStraggler = true;
        _straggler = _vektor.back();
        _vektor.pop_back();    
    }
    if(VERBOSE)
        std::cout << CYAN << "[verbose] Straggler: \t\t[" << _straggler << "]" << RESET << std::endl;
}


void PmergeMe::_createVectorOfPairs()
{
    _pairs = new std::vector<std::pair<int, int> >;
    for(std::vector<int>::iterator it = _vektor.begin(); it != _vektor.end(); it +=2)
    {
        if(*it < *(it+1))
            _pairs->push_back(std::make_pair(*it, *(it+1)));
        else
            _pairs->push_back(std::make_pair(*(it+1), *it));
    }
    if(VERBOSE)
    {   
        std::cout << CYAN << "[verbose] Vector of pairs: \t[ ";
        for (std::vector<std::pair<int, int> >::iterator it = _pairs->begin(); it != _pairs->end(); it++)
            std::cout << "{" << it->first << ", " << it->second << "} ";
        std::cout << "]" << RESET << std::endl;
    }
}

