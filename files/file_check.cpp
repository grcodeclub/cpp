#include <fstream>
#include <iostream>

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

int main() {
    if (fileExists("example.txt")) {
        std::cout << "Το αρχείο υπάρχει." << std::endl;
    } else {
        std::cout << "Το αρχείο ΔΕΝ υπάρχει." << std::endl;
    }

    return 0;
}
