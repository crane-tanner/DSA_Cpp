#include <iostream>

using namespace std;


class Node {

public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        }
        else {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        }
        else {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void append(int value) { 
        Node* newNode = new Node(value); // create a new node 

        if (head == nullptr) // if empty LL
        {
            head = newNode;
            tail = newNode;
        }
        else { // if items already in the LL
            tail->next = newNode; 
            tail = newNode;
        }

        length++;
    }

    void deleteLast() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {

        Node* pre = head;
        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
    }
        delete temp;
        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value); // create a new node with the passed in value

        if (length == 0) { // if LL is empty then head and tail point to newNode
            head = newNode;
            tail = newNode; 
        }
        else { // otherwise newNode next pointer to head then head point (move over) to newNode

            newNode->next = head;
            head = newNode;
        
        }

        length++; // increment length of LL
    }
};



int main() {

    LinkedList* myLinkedList = new LinkedList(4);

    /*
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    */

    myLinkedList->append(5);
    myLinkedList->prepend(3);
    myLinkedList->deleteLast();

    cout << "\nLinked List:\n";
    myLinkedList->printList();

   
    /*
        EXPECTED OUTPUT:
        ----------------
        Head: 4
        Tail: 4
        Length: 1

        Linked List:
        3
        4
        5
    */

}

