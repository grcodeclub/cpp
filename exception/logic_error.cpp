#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::logic_error("Σφάλμα λογικής εντοπίστηκε!");
    } catch (const std::logic_error& e) {
        std::cout << "Πιάστηκε std::logic_error: " << e.what() << std::endl;
    }

    return 0;
}
