#include <iostream>
#include <stdexcept>

void checkNumber(int num) {
    if (num <= 0) {
        throw std::invalid_argument("Ο αριθμός πρέπει να είναι μεγαλύτερος του μηδενός!");
    }
    std::cout << "Ο αριθμός είναι: " << num << std::endl;
}

int main() {
    try {
        checkNumber(-5);
    } catch (const std::invalid_argument& e) {
        std::cout << "Πιάστηκε std::invalid_argument: " << e.what() << std::endl;
    }

    return 0;
}
