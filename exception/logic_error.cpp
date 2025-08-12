#include <iostream>      // Για είσοδο/έξοδο στην κονσόλα
#include <stdexcept>     // Για τις προκαθορισμένες εξαιρέσεις όπως logic_error
using namespace std;     // Χρησιμοποιούμε το χώρο ονομάτων std για απλοποίηση

int main() {
    try {
        throw logic_error("Σφάλμα λογικής εντοπίστηκε!");
    } 
    catch (const logic_error& e) {
        cout << "Πιάστηκε logic_error: " << e.what() << endl;
    }

    return 0; // Κανονικός τερματισμός προγράμματος
}
