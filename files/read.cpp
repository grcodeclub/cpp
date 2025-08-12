#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("file1.txt");
    std::string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Δεν μπόρεσε να ανοιχτεί το αρχείο." << std::endl;
    }

    return 0;
}
