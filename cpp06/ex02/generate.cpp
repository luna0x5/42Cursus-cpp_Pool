
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(NULL));
    int r = std::rand() % 3;

    switch (r)
	{
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        default:
            std::cout << "Generated: C" << std::endl;
            return new C();
    }
}
