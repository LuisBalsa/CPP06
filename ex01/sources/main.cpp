#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data data;
    data.value = 42;
    data.c = 'X';

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Serialized pointer: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Value: " << ptr->value << ", Char: " << ptr->c << std::endl;

    if (ptr == &data)
        std::cout << "Pointers are equal!" << std::endl;
    else
        std::cout << "Pointers are NOT equal!" << std::endl;
    return 0;
}
