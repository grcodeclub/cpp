#include <iostream>
using namespace std;     // Χρησιμοποιούμε το χώρο ονομάτων std για απλοποίηση

int main() {
    try {
        int x = 10;
        int y = 0;
        if (y == 0) {
            throw "Διαίρεση με το 0!";
        }
        int result = x / y;
        cout << "Το αποτέλεσμα είναι: " << result << endl;
    }
    catch (const char* msg) {
        cout << "Σφάλμα: " << msg << endl;
    }
    return 0;
}
