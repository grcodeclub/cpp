#include <iostream>

using namespace std;

class Complex {
private:
    int int1;  // Πρώτος ακέραιος αριθμός
    int int2;  // Δεύτερος ακέραιος αριθμός

public:
    // Κανονικός κατασκευαστής χωρίς παραμέτρους
    Complex() {
        int1 = 0;
        int2 = 0;
    }

    // Κανονικός κατασκευαστής με παραμέτρους
    Complex(int num1, int num2) {
        int1 = num1;
        int2 = num2;
    }

    // Υπερφόρτωση του τελεστή + για πρόσθεση δύο αντικειμένων Complex
    Complex operator + (const Complex& other) const {
        Complex result;
        result.int1 = int1 + other.int1;
        result.int2 = int2 + other.int2;
        return result;
    }

    // Υπερφόρτωση του τελεστή * για πολλαπλασιασμό δύο αντικειμένων Complex
    Complex operator * (const Complex& other) const {
        Complex result;
        result.int1 = int1 * other.int1;
        result.int2 = int2 * other.int2;
        return result;
    }

    // Συνάρτηση για εμφάνιση των τιμών
    void print() const {
        cout << "int1: " << int1 << ", int2: " << int2 << endl;
    }
};

int main() {
    // Δημιουργία δύο αντικειμένων Complex με ακέραιους αριθμούς
    Complex num1(3, 4);  // int1 = 3, int2 = 4
    Complex num2(1, 2);  // int1 = 1, int2 = 2

    // Πρόσθεση των δύο αντικειμένων
    Complex sum = num1 + num2;  // int1 = 3 + 1, int2 = 4 + 2

    // Πολλαπλασιασμός των δύο αντικειμένων
    Complex product = num1 * num2;  // int1 = 3 * 1, int2 = 4 * 2

    // Εμφάνιση αποτελεσμάτων
    cout << "Sum: ";
    sum.print();
    cout << "Product: ";
    product.print();

    return 0;
}
