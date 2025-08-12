#include <iostream>       // Για είσοδο/έξοδο στην κονσόλα
#include <stdexcept>      // Περιλαμβάνει τις προκαθορισμένες εξαιρέσεις όπως out_of_range
#include <vector>         // Χρησιμοποιούμε τη δομή vector
using namespace std;     // Χρησιμοποιούμε το χώρο ονομάτων std για απλοποίηση

int main() {
    try {
        vector<int> vec = {1, 2, 3};
        int val = vec.at(10);
    } catch (const out_of_range& e) {
        cout << "Πιάστηκε out_of_range: " << e.what() << endl;
    }

    return 0;
}
