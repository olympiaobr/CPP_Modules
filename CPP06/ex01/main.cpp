#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.id = 123;
    data.name = "Test Data";

    std::cout << "Original Data:\n";
    std::cout << "ID: " << data.id << "\n";
    std::cout << "Name: " << data.name << "\n";

    // Serialize
    unsigned long raw = Serializer::serialize(&data);
    std::cout << "Serialized Data Pointer: " << raw << "\n";

    // Deserialize
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data:\n";
    std::cout << "ID: " << deserializedData->id << "\n";
    std::cout << "Name: " << deserializedData->name << "\n";

    // Check if the deserialized pointer is equal to the original
    if (deserializedData == &data) {
        std::cout << "Success: The deserialized pointer is equal to the original.\n";
    } else {
        std::cout << "Error: The deserialized pointer is not equal to the original.\n";
    }

    return 0;
}

