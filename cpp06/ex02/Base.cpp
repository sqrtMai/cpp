#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base *Base::generate(void)
{
	Base *ret;

	int nbr = rand() % 3;
	if (nbr == 0)
		ret = new A();
	if (nbr == 1)
		ret = new B();
	if (nbr == 2)
		ret = new C();
	return ret;
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void Base::identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A\n";
		(void)a;
		return;
	}
	catch (...)
	{
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B\n";
		(void)b;
		return;
	}
	catch (...)
	{
	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C\n";
		(void)c;
		return;
	}
	catch (...)
	{
	}
}
