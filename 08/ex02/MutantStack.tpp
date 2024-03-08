#include "includes/MutantStack.hpp"


template <typename T, typename C>
typename MutantStack <T,C>::iterator MutantStack <T,C>::begin()
{
    return (this->c.begin());
}

