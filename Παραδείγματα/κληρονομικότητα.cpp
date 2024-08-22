// Σε αυτό το παράδειγμα, ορίζουμε μια βασική κλάση Shape, η οποία περιλαμβάνει τις μεταβλητές width και height. 
// Η κλάση Rectangle κληρονομεί την Shape και προσθέτει τη μέθοδο getArea() για τον υπολογισμό της περιοχής του ορθογωνίου.

#include <iostream>

// Βασική κλάση Shape
class Shape {
protected:
    int width; // Πλάτος του σχήματος
    int height; // Ύψος του σχήματος

public:
    // Constructor
    Shape(int w, int h) {
        width = w;
        height = h;
    }

    // Επιστροφή της περιοχής του σχήματος
    virtual int getArea() {
        return 0;
    }
};

// Κλάση Rectangle που κληρονομεί την κλάση Shape
class Rectangle : public Shape {
public:
    // Constructor
    Rectangle(int w, int h) : Shape(w, h) {}

    // Υπολογισμός και επιστροφή της περιοχής του ορθογωνίου
    int getArea() override {
        return width * height;
    }
};

int main() {
    // Δημιουργία αντικειμένου τύπου Rectangle
    Rectangle rectangle(5, 3);

    // Εκτύπωση της περιοχής του ορθογωνίου
    std::cout << "Περιοχή ορθογωνίου: " << rectangle.getArea() << std::endl;

    return 0;
}
