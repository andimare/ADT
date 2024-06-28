#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int data) : data(data), next(nullptr), prev(nullptr) {}
};

DNode* insert_at_beginning(DNode* head, int data) {
    DNode* new_node = new DNode(data);
    if (head) {
        head->prev = new_node;
    }
    new_node->next = head;
    return new_node;
}

DNode* insert_at_end(DNode* head, int data) {
    DNode* new_node = new DNode(data);
    if (!head) {
        return new_node;
    }
    DNode* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    return head;
}

DNode* delete_from_beginning(DNode* head) {
    if (!head) {
        return nullptr;
    }
    DNode* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    delete temp;
    return head;
}

DNode* delete_from_end(DNode* head) {
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }
    DNode* current = head;
    while (current->next) {
        current = current->next;
    }
    if (current->prev) {
        current->prev->next = nullptr;
    }
    delete current;
    return head;
}

void print_list(DNode* head) {
    DNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
        DNode* d_head = nullptr;
    
    //	Insertion
    d_head = insert_at_beginning(d_head, 3);
    d_head = insert_at_beginning(d_head, 2);
    d_head = insert_at_beginning(d_head, 1);
    d_head = insert_at_end(d_head, 7);
    
    //Display
    print_list(d_head);
    
    //Deletion
    d_head = delete_from_beginning(d_head);
    print_list(d_head);
    d_head = delete_from_end(d_head);
    
    print_list(d_head);

    return 0;
}
