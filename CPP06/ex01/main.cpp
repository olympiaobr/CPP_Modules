#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.id = 123;
    data.name = "Test Data";

    uintptr_t raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Original Data:\n";
    std::cout << "ID: " << data.id << "\n";
    std::cout << "Name: " << data.name << "\n";

    std::cout << "Serialized Data Pointer: " << raw << "\n";

    std::cout << "Deserialized Data:\n";
    std::cout << "ID: " << deserializedData->id << "\n";
    std::cout << "Name: " << deserializedData->name << "\n";

    if (deserializedData == &data) {
        std::cout << "Success: The deserialized pointer is equal to the original.\n";
    } else {
        std::cout << "Error: The deserialized pointer is not equal to the original.\n";
    }

    return 0;
}
