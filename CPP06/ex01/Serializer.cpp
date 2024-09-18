#include "Serializer.hpp"

// Serialize a pointer to unsigned long
unsigned long Serializer::serialize(Data* ptr) {
    return reinterpret_cast<unsigned long>(ptr);
}

// Deserialize an unsigned long back to a data pointer
Data* Serializer::deserialize(unsigned long raw) {
    return reinterpret_cast<Data*>(raw);
}
