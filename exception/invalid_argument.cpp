// Kάνει έλεγχο εγκυρότητας ενός αριθμού και διαχειρίζεται πιθανό σφάλμα μέσω εξαιρέσεων (exceptions)
// Στο main(), καλείται η checkNumber με την τιμή -5, που είναι λάθος.
// Η εξαίρεση πιάνεται από το catch block και τυπώνει το σχετικό μήνυμα σφάλματος.

#include <iostream>
#include <stdexcept>

// Η συνάρτηση checkNumber δέχεται έναν ακέραιο αριθμό και τον ελέγχει.
void checkNumber(int num) {
    if (num <= 0) {
        // Αν ο αριθμός είναι μικρότερος ή ίσος με το 0, ρίχνει εξαίρεση τύπου std::invalid_argument
        throw std::invalid_argument("Ο αριθμός πρέπει να είναι μεγαλύτερος του μηδενός!");
    }
    // Αν ο αριθμός είναι έγκυρος, τον εμφανίζει
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
