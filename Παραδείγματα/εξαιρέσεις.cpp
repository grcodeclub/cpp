#include <iostream>
#include <stdexcept> // Για τις προκαθορισμένες εξαιρέσεις


// Αν ο δεύτερος αριθμός είναι μηδέν, ρίχνει μια εξαίρεση με το μήνυμα "Η διαίρεση με το μηδέν δεν επιτρέπεται!".
// Αν η divide ρίξει μια εξαίρεση, αυτή πιάνεται από το catch μπλοκ, το οποίο εκτυπώνει το μήνυμα σφάλματος.

int divide(int a, int b) {
    if (b == 0) {
        throw "Η διαίρεση με το μηδέν δεν επιτρέπεται!";
    }
    return a / b;
}

int main() {
    int num1, num2;
    std::cout << "Εισάγετε δύο αριθμούς: ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "Αποτέλεσμα: " << result << std::endl;
    } catch (const char* msg) {
        std::cerr << "Σφάλμα: " << msg << std::endl;
    }

    return 0;
}
