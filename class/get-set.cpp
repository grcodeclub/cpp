#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor για την αρχικοποίηση των μεταβλητών
    Person(string n, int a) : name(n), age(a) {}

    // Getter για το όνομα
    string getName() const {
        return name;
    }

    // Setter για το όνομα
    void setName(string n) {
        name = n;
    }

    // Getter για την ηλικία
    int getAge() const {
        return age;
    }

    // Setter για την ηλικία
    void setAge(int a) {
            cout << "Η ηλικία είναι "<< a << endl;
    }

    // Μέθοδος για την εμφάνιση των πληροφοριών του ατόμου
    void display() const {
        cout << "Όνομα: " << name << ", Ηλικία: " << age << endl;
    }
};

int main() {
    // Δημιουργία ενός αντικειμένου Person
    Person person("Γιώργος", 30);

    // Χρήση των getters για εμφάνιση των αρχικών τιμών
    cout << "Αρχικές τιμές: ";
    person.display();

    // Χρήση των setters για αλλαγή των τιμών
    person.setName("Ελένη");
    person.setAge(25);

    // Χρήση των getters για εμφάνιση των νέων τιμών
    cout << "Νέες τιμές: ";
    person.display();

    return 0;
}
