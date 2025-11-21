
#include "Serializer.hpp"

#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Hajar";
    data.value = 3.14159;

    std::cout << "Original Data pointer: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (as uintptr_t): " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;

    if (deserialized == &data)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Error: pointers differ!" << std::endl;

    std::cout << "id: " << deserialized->id << std::endl;
    std::cout << "name: " << deserialized->name << std::endl;
    std::cout << "value: " << deserialized->value << std::endl;

    return 0;
}
