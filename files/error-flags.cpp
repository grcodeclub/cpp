/* 
Επίδειξη των Error Flags στα File Streams

Το πρόγραμμα επιχειρεί να διαβάσει δεδομένα από ένα αρχείο με χρήση ενός fstream.
Οι Error Flags (good(), bad(), fail(), eof()) χρησιμοποιούνται για την ανίχνευση προβλημάτων 
που μπορεί να προκύψουν κατά την ανάγνωση ή την εγγραφή από/προς ένα αρχείο. 

Οι Error Flags αλλάζουν την κατάστασή τους ανάλογα με το αποτέλεσμα των λειτουργιών που εκτελούνται στο αρχείο.

Η συνάρτηση ShowFlags εμφανίζει την τρέχουσα κατάσταση των Error Flags για ένα δεδομένο fstream. Σε αυτό το πρόγραμμα, 
η ShowFlags καλείται μετά από κάθε λειτουργία ανάγνωσης από το αρχείο, προκειμένου να εμφανιστούν οι αλλαγές στις Error Flags.

*/

#include <iostream>
#include <fstream>

using namespace std;

// Συνάρτηση για την εμφάνιση των Error Flags του αρχείου
void ShowFlags (fstream&);

int main ()
{
    char Buff[100];
    int v1 = -1;
    double v2 = -1.0;
    string Fn;
    fstream F;
    Fn = "File3.txttxt"; // Όνομα αρχείου που δεν υπάρχει
    F.open (Fn.c_str ());
    ShowFlags (F); // Εμφάνιση των Error Flags μετά το άνοιγμα του αρχείου

    Fn = "File3.txt"; // Έγκυρο όνομα αρχείου
    F.open (Fn.c_str ());
    ShowFlags (F); // Εμφάνιση των Error Flags μετά το άνοιγμα του αρχείου

    F >> v1; // Ανάγνωση ακέραιου από το αρχείο
    cout << v1 << endl;
    ShowFlags (F); // Εμφάνιση των Error Flags μετά την ανάγνωση

    F.clear (); // Καθαρισμός των Error Flags
    F >> Buff; // Ανάγνωση string από το αρχείο
    F >> v1; // Προσπάθεια ανάγνωσης ακέραιου από το αρχείο, αλλά αποτυγχάνει
    cout << v1 << endl;
    ShowFlags (F); // Εμφάνιση των Error Flags μετά την ανάγνωση

    F >> v2; // Ανάγνωση δεκαδικού αριθμού από το αρχείο
    cout << v2 << endl;
    ShowFlags (F); // Εμφάνιση των Error Flags μετά την ανάγνωση

    F >> Buff; // Ανάγνωση string από το αρχείο
    cout << Buff << endl;
    ShowFlags (F); // Εμφάνιση των Error Flags μετά την ανάγνωση
}

void ShowFlags (fstream &F)
{
    cout << "Good   Bad    Fail   Eof" << endl;
    cout << "  " << F.good () << "     " << F.bad () << "      " << F.fail () << "      " << F.eof () << endl << endl;
}
