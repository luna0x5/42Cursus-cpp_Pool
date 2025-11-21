
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    Base* basePtr = generate();

    std::cout << "\n--- Identification ---" << std::endl;

    std::cout << "Using pointer: ";
    identify(basePtr);

    std::cout << "Using reference: ";
    identify(*basePtr);

    delete basePtr;
    return 0;
}
