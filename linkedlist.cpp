#include <iostream>
#include <cassert>

// Node Class
class Node {
public:

    int data;       // Application data
    Node* prev;     // Pointer to next node
    Node* next;     // Pointer to previous node

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList Class
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {

        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add a node to the end of the list
    void append(int data) {

        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Remove a node from the list
    bool remove(int data) {

        Node* temp = head;

        while (temp != nullptr) {

            if (temp->data == data) 
            {
                if (temp->prev != nullptr) temp->prev->next = temp->next;
                if (temp->next != nullptr) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;

                delete temp;
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // Utility function to print the list for testing purposes
    void printList() {

        Node* temp = head;

        while (temp != nullptr) {

            std::cout << temp->data << " ";
            temp = temp->next;
        }
        
        std::cout << std::endl;
    }
};

// Basic Unit Tests
void runTests() {
    DoublyLinkedList list;

    // Test appending function
    list.append(1);
    list.append(2);
    list.append(3);
    assert(list.head->data == 1 && list.tail->data == 3);

    // Test removal in middle of linked list
    list.remove(2);
    assert(list.head->next->data == 3);

    // Test removal of head
    list.remove(1);
    assert(list.head->data == 3 && list.tail->data == 3);

    // Test removal of tail
    list.append(4);
    list.remove(4);
    assert(list.tail->data == 3);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}
