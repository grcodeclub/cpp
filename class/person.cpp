#include <iostream>
#include <string>

using namespace std; // Χρήση του namespace std

// Ορισμός της κλάσης Person
class Person {
public:
    // Μέλη της κλάσης
    string name; // Όνομα του ατόμου
    int age; // Ηλικία του ατόμου
    float height; // Ύψος του ατόμου
};

int main() {
    // Δημιουργία αντικειμένου τύπου Person
    Person person;

    // Ανάθεση τιμών στα μέλη του αντικειμένου
    person.name = "John"; // Ανάθεση του ονόματος "John" στο μέλος name
    person.age = 30; // Ανάθεση της ηλικίας 30 στο μέλος age
    person.height = 1.75; // Ανάθεση του ύψους 1.75 στο μέλος height

    // Εκτύπωση των μελών του αντικειμένου
    cout << "Όνομα: " << person.name << endl; // Εκτύπωση του ονόματος
    cout << "Ηλικία: " << person.age << endl; // Εκτύπωση της ηλικίας
    cout << "Ύψος: " << person.height << endl; // Εκτύπωση του ύψους

    return 0;
}
