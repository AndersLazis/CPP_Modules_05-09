

#include "includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe()
{
//     if(_array)
//         delete [] _array;
 }

PmergeMe::PmergeMe(int ac, char** av) 
{
    _createArray(ac, av);
    //_isArrayValid();
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

void PmergeMe::_createArray(int ac, char** av)
{
    _array = new int[ac-1];
    long long int temp;
    for (int i = 1; i < ac; i++)
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
        std::cout << CYAN << "[verbose] Input array: ";
        for (int i = 0; i < ac-1; i++)
            std::cout << _array[i] << " ";
        std::cout << RESET << std::endl;
    }
    delete [] _array;
}
