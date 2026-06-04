#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);

	std::cout << "= Tests avec VECTOR =" << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(v, 55);
		std::cout << *it << " has been found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "55 not found" << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << *it << " has been found" << std::endl;
		it = easyfind(v, 10);
		std::cout << *it << " has been found" << std::endl;
		it = easyfind(v, 50);
		std::cout << *it << " has been found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "not found" << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "= Tests avec deque =" << std::endl;

	std::deque<int> d;
	d.push_back(10);
	d.push_back(30);
	d.push_back(50);

	try
	{
		std::deque<int>::iterator it2 = easyfind(d, 55);
		std::cout << *it2 << " has been found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "55 not found" << std::endl;
	}

	try
	{
		std::deque<int>::iterator it2 = easyfind(d, 30);
		std::cout << *it2 << " has been found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "not found" << std::endl;
	}


}
