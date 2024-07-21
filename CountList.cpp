#include <iostream>

// Node structure definition
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Iterative function to count the number of items in a linked list
int countIterative(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Recursive function to count the number of items in a linked list
int countRecursive(Node* head) {
    if (head == nullptr) {
        return 0;
    }
    return 1 + countRecursive(head->next);
}

// Helper function to insert a new node at the beginning of the linked list
void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Main function to test the counting functions
int main() {
    Node* head = nullptr;

    // Inserting some elements into the linked list
    insert(head, 5);
    insert(head, 10);
    insert(head, 15);
    insert(head, 20);

    std::cout << "Number of items in the linked list (Iterative): " << countIterative(head) << std::endl;
    std::cout << "Number of items in the linked list (Recursive): " << countRecursive(head) << std::endl;

    // Free allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
