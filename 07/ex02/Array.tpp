/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:00:39 by aputiev           #+#    #+#             */
/*   Updated: 2024/02/09 22:06:44 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Array.hpp"


template<typename T>
Array<T>::Array() : _size(0), _array(new T[0]){std::cout << "Array default constructor" << std::endl;}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n),  _array(new T[n]()) {std::cout << "Array n-constructor" << std::endl;}

template<typename T>
Array<T>::Array(const Array<T> &other)
{	
	this->_array = NULL;
	*this = other; 
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor" << std::endl;
	if(this->_array != NULL)
		delete[] this->_array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other) {
	
	if(this->_array != NULL)
		delete[] this->_array;
	if(other._size != 0)
	{	
		this->_size = other._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)			
			this->_array[i] = other._array[i];
	}
	return *this;    
}


template<typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw wrongIndexException();
	return this->_array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}