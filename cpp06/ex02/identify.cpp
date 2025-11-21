#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
        return;
    } catch (std::exception &e) {
        std::cout << "Failed A cast: " << e.what() << std::endl;
    }

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type: B" << std::endl;
        return;
    } catch (std::exception &e) {
        std::cout << "Failed B cast: " << e.what() << std::endl;
    }

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type: C" << std::endl;
        return;
    } catch (std::exception &e) {
        std::cout << "Failed C cast: " << e.what() << std::endl;
    }

    std::cout << "Unknown type" << std::endl;
}
