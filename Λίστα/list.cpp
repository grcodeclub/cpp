#include <stdio.h>
#include <stdlib.h>

// Δήλωση του κόμβου της λίστας
struct Node {
    int data;
    struct Node* next;
};

// Συνάρτηση για προσθήκη στοιχείου στην αρχή της λίστας
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Συνάρτηση για εκτύπωση των στοιχείων της λίστας
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Αρχικοποίηση κενής λίστας

    // Προσθήκη στοιχείων στη λίστα
    insert(&head, 3);
    insert(&head, 7);
    insert(&head, 5);

    // Εκτύπωση των στοιχείων της λίστας
    printf("Λίστα: ");
    printList(head);

    return 0;
}
