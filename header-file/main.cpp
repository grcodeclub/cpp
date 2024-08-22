// main.cpp
#include <iostream>
#include "my_functions.h" // Εδώ κάνεις include το δικό σου header file
using namespace std;

int main() {
    printHello();
    int sum = add(3, 4);
    cout << "The sum is: " << sum << endl;
    return 0;
}
