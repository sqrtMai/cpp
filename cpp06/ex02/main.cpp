#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();
	Base *random = NULL;

	random = random->generate();

	random->identify(a);
	random->identify(b);
	random->identify(c);
	random->identify(random);

	random->identify(*a);
	random->identify(*b);
	random->identify(*c);
	random->identify(*random);

	return 0;
}
