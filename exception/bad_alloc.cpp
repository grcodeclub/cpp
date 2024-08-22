#include <iostream>
#include <new> // Απαιτείται για τη χρήση του std::bad_alloc

int main() {
    try {
        // Προσπαθούμε να δεσμεύσουμε ένα πολύ μεγάλο μπλοκ μνήμης
        int* bigArray = new int[100000000000];
    } catch (const std::bad_alloc& e) {
        std::cout << "Πιάστηκε std::bad_alloc: " << e.what() << std::endl;
    }

    return 0;
}
