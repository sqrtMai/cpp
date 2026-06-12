#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	/* data */
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack();
	MutantStack(const MutantStack<T> &other);
	MutantStack<T>& operator=(const MutantStack<T> &other);
	~MutantStack();

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}
};

template <typename T>
MutantStack<T>::MutantStack(/* args */)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
{
	*this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this == &other)
		return *this;
	this->c = other.c;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}
#endif
