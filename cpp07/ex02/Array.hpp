#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T *data;
	size_t _size;

public:
	Array(/* args */);
	Array(unsigned int n);
	Array(const Array<T>& other);
	Array<T>& operator=(const Array<T>& other);
	T &operator[](size_t pos);
	size_t size(void);
	~Array();
};

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->data = new T[n];
	this->_size = (size_t)n;
}

template <typename T>
Array<T>::Array()
{
	this->data = 0;
	this->_size = 0;
}
template <typename T>
Array<T>::~Array()
{
	if (this->data)
		delete[] this->data;
}

template <typename T>
size_t Array<T>::size(void)
{
	return this->_size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return *this;

	delete[] data;

	this->_size = other._size;
	data = new T[this->_size];

	for (size_t i = 0; i < this->_size; i++)
		data[i] = other.data[i];

	return *this;
}

template <typename T>
Array<T>::Array(const Array<T>& other)
{
	this->_size = other._size;
	data = new T[this->_size];

	for (size_t i = 0; i < this->_size; i++)
		data[i] = other.data[i];
}

template <typename T>
T &Array<T>::operator[](size_t pos)
{
	if (pos > this->_size)
	{
		throw std::exception();
	}
	return this->data[pos];
}

#endif
