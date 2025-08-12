#include <iostream>
#include <stdexcept>     // Για τις προκαθορισμένες εξαιρέσεις.
using namespace std;     // Χρησιμοποιούμε το χώρο ονομάτων std για απλοποίηση


int main() {
    try {
        throw runtime_error("Κάτι πήγε στραβά κατά την εκτέλεση!");
    } catch (const runtime_error& e) {
        cout << "Πιάστηκε runtime_error: " << e.what() << endl;
    }

    return 0;
}
