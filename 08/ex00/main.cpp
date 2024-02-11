#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>


template <typename T>
void print(T & spisok)
{
    for (typename std::list<T>::const_iterator it = spisok.cbegin();
     it != spisok.cend(); it++)
        std::cout << *it << std::endl;
}


template <typename T>
typename T::const_iterator easyfind(T & spisok, int num)
{
    typename T::const_iterator it = std::find(spisok.begin(), spisok.end(), num);
    if(it != spisok.end())
    {
        std::cout << "found " << *it << std::endl;
        return it;
            
    }
    else
    {
        std::cout << "not found" << std::endl;
        return it;
    }
}

int main(void) {

    std::list<int> mylist;
    std::vector<int> myvector;

    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    
    mylist.push_front(1);
    mylist.push_back(2);
    mylist.push_back(3);
    mylist.push_back(4);


    easyfind(mylist, 3);
    easyfind(myvector, 3);
       
    // std::vector <int>::iterator itr = std::find(myvector.begin(), myvector.end(), 3);

    // if(itr != myvector.end())
    //     std::cout << "found " << *itr << std::endl;
    // else
    //     std::cout << "not found" << std::endl;


    //std::cout << "size: " << mylist.size() << std::endl;
    //print(mylist);
    //std::cout << *it << std::endl;
    
    return 0;
}

