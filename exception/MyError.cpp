#include <iostream>
#include <string>

// Ορισμός της δομής MyError
struct MyError {
    int code;
    std::string message;
};

int main() {
    try {
        // Κάτι πήγε στραβά, πετάμε την εξαίρεση
        throw MyError{404, "Not Found"};
    } catch (const MyError& e) {
        // Πιάσαμε την εξαίρεση και εκτυπώνουμε τις πληροφορίες
        std::cout << "Πιάστηκε εξαίρεση MyError!" << std::endl;
        std::cout << "Κωδικός: " << e.code << std::endl;
        std::cout << "Μήνυμα: " << e.message << std::endl;
    } catch (...) {
        // Πιάστε οποιαδήποτε άλλη εξαίρεση
        std::cout << "Άγνωστη εξαίρεση πιάστηκε" << std::endl;
    }

    return 0;
}
