#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
    try {
        std::vector<int> vec = {1, 2, 3};
        // Προσπάθεια πρόσβασης σε στοιχείο εκτός ορίων
        int val = vec.at(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Πιάστηκε std::out_of_range: " << e.what() << std::endl;
    }

    return 0;
}
