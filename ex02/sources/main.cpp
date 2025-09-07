#include <iostream>
#include "Identify.hpp"

int main() {
    // Run several tests in a loop
    for (int i = 0; i < 10; ++i) {
        Base* ptr = generate();
        std::cout << "Test " << i + 1 << std::endl;
        std::cout << "Pointer: ";
        identify(ptr);
        std::cout << "Reference: ";
        identify(*ptr);
        delete ptr;
        std::cout << std::endl;
    }

    // Test with null pointer for identify(Base*)
    std::cout << "Pointer (null): ";
    Base* nullPtr = NULL;
    identify(nullPtr);

    // Test with empty object for identify(Base&)
    std::cout << "Reference (empty object): ";
    Base nullRef;
    identify(nullRef);

    return 0;
}
