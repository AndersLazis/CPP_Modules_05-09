
#include <iterator>
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
    std::cout << CYAN << "[verbose] Input array: \t\t\t[ ";
    for (int i = 0; i < _size; i++)
        std::cout << _array[i] << " ";
    std::cout << "]"<< RESET << std::endl;
}


void PmergeMe::_checkVectorForDuplicates()
{   
    for(std::vector<int>::iterator it = _vektor.begin(); it != _vektor.end(); it++)
        for(std::vector<int>::iterator it2 = it+1; it2 != _vektor.end(); it2++)
            if (*it == *it2)
                throw std::invalid_argument("invalid argument. Duplicate has been found");
}

void PmergeMe::_checkListForDuplicates()
{   
    std::list<int>::iterator it = _list.begin();
    std::list<int>::iterator it2 = it;
    ++it2;
    for(; it != _list.end(); it++)
        for(; it2 != _list.end(); it2++)
            if (*it == *it2)
                throw std::invalid_argument("invalid argument. Duplicate has been found");
}

bool PmergeMe::_isVectorSorted(std::vector<int>* vektor)
{
    for(std::vector<int>::iterator it = vektor->begin(); it != vektor->end()-1; it++)
        if (*it > *(it+1))
            return false;
    if(VERBOSE)
        std::cout << CYAN << "[verbose] Vector is already sorted." << RESET << std::endl;
    return true;
}


bool PmergeMe::_isListSorted(std::list<int>* list)
{
    std::list<int>::iterator it = list->begin();
    std::list<int>::iterator next_it = it;
    next_it++;

    for (; next_it != list->end(); it++, next_it++)
    {
        if (*it > *next_it)
            return false;
    }
    if(VERBOSE)
        std::cout << CYAN << "[verbose] List is already sorted." << RESET << std::endl;
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
    {
        std::cout << CYAN << "[verbose] Straggler exists: \t\t[" << _isStraggler << "]" << RESET << std::endl;
        std::cout << CYAN << "[verbose] Straggler: \t\t\t[" << _straggler << "]" << RESET << std::endl;
    }
}

void PmergeMe::_checkListForStraggler()
{
    if(_size % 2 != 0)
    {
        _isStraggler = true;
        _straggler = _list.back();
        _list.pop_back();    
    }
    if(VERBOSE)
    {
        std::cout << CYAN << "[verbose] Straggler exists: \t\t[" << _isStraggler << "]" << RESET << std::endl;
        std::cout << CYAN << "[verbose] Straggler: \t\t\t[" << _straggler << "]" << RESET << std::endl;
    }
}

/* merge */

void PmergeMe::_merge(std::vector<int> vektor)
{
    if(vektor.size() <= 2)
    {
        if(vektor[0] < vektor[1])
            _pairs->push_back(std::make_pair(vektor[0], vektor[1]));
        else
            _pairs->push_back(std::make_pair(vektor[1], vektor[0]));
        return;
    }
    long long median = vektor.size() / 2;
    std::vector<int> left(vektor.begin(), vektor.begin() + median);
    std::vector<int> right(vektor.begin() + median, vektor.end());
    if(left.size() % 2 != 0)
    {
        right.push_back(left[0]);
        left.erase(left.begin());
    }
    _merge(left);
    _merge(right);
}

void PmergeMe::_merge(std::list<int> list)
{
    
    if(list.size() <= 2)
    {
        if(*(list.begin()) < *(++list.begin()))
            _list_pairs->push_back(std::make_pair(*(list.begin()), *(++list.begin())));
        else
            _list_pairs->push_back(std::make_pair(*(++list.begin()), *(list.begin())));
        return;
    }
    std::list<int>::iterator median_it = list.begin();
    std::advance(median_it, (list.size() / 2));

    std::list<int> right;
    right.splice(right.begin(), list, median_it, list.end());
    if(list.size() % 2 != 0)
    {
        right.push_back(list.front());
        list.pop_front();
    }

    // for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
    // for (std::list<int>::iterator it = right.begin(); it != right.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
    _merge(list);
    _merge(right);
}

void PmergeMe::printTime(std::clock_t time, int range)
{
	double clock_per_ms = static_cast<double>(CLOCKS_PER_SEC) / 1000;
	double timeInMs = time / clock_per_ms;

	std::cout << "Time to process a range of " << range << " numbers: " << time << " clock ticks (";
	std::cout << std::fixed;
	std::cout.precision( 6 );
	std::cout << timeInMs << " ms)" << std::endl;
}