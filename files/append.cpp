#include <fstream>
#include <iostream>

int main() {
    std::ofstream outputFile("output.txt", std::ios::app);

    if (outputFile.is_open()) {
        outputFile << "Νέα γραμμή προστέθηκε!\n";
        outputFile.close();
    } else {
        std::cerr << "Δεν μπόρεσε να ανοιχτεί το αρχείο για append.\n";
    }

    return 0;
}
