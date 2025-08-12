// Το πρόγραμμα ορίζει μια απλή δομή MyError, που περιέχει έναν αριθμητικό κωδικό σφάλματος και ένα μήνυμα
// Αυτή η δομή "πετιέται" ως εξαίρεση με throw, και στη συνέχεια πιάνεται και επεξεργάζεται στο catch.
#include <iostream>
#include <string>
using namespace std;     // Χρησιμοποιούμε το χώρο ονομάτων std για απλοποίηση

// Ορισμός της δομής MyError
struct MyError {
    int code;
    string message;
};

int main() {
    try {
        // Κάτι πήγε στραβά, πετάμε την εξαίρεση
        throw MyError{404, "Not Found"};
    } catch (const MyError& e) {
        // Πιάσαμε την εξαίρεση και εκτυπώνουμε τις πληροφορίες
        cout << "Πιάστηκε εξαίρεση MyError!" << endl;
        cout << "Κωδικός: " << e.code << endl;
        cout << "Μήνυμα: " << e.message << endl;
    } catch (...) {
        // Πιάστε οποιαδήποτε άλλη εξαίρεση
        cout << "Άγνωστη εξαίρεση πιάστηκε" << endl;
    }

    return 0;
}
