#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("Κάτι πήγε στραβά κατά την εκτέλεση!");
    } catch (const std::runtime_error& e) {
        std::cout << "Πιάστηκε std::runtime_error: " << e.what() << std::endl;
    }

    return 0;
}
