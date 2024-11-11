#include<iostream>
using namespace std;

class node {
public:
    string name;
    node* next = NULL;
    node() {
        name = "NA";
        next = NULL;
    }
    node(string d) {
        name = d;
        next = NULL;
    }
};

class counter {
public:
    node* head;
    node* rear;
    counter() {
        head = NULL;
        rear = NULL;
    }

    void insert(string d) {
        node* nn = new node(d);
        if (head == NULL) {
            head = nn;
            rear = nn;
            rear->next = head;  // Circular link
        } else {
            rear->next = nn;
            rear = nn;
            rear->next = head;  // Circular link
        }
    }

    void display() {
        node* temp = head;
        if (head == NULL) {
            cout << "Queue is Empty" << endl;
        } else {
            do {
                cout << temp->name << " ";
                temp = temp->next;
            } while (temp != head);  // Loop till we get back to the head
            cout << endl;
        }
    }

    void checkEmpty() {
        if (head == NULL) {
            cout << "Queue at the counter is Empty. Counter closed." << endl;
        } else {
            cout << "Queue is not empty. Cannot close counter." << endl;
        }
    }

    void remove() {
        if (head == NULL) {
            cout << "Queue at the counter is Empty. Cannot checkout customers." << endl;
        } else if (head == rear) { // Only one customer in the queue
            delete head;
            head = NULL;
            rear = NULL;
        } else {
            node* temp = head;
            head = head->next;
            rear->next = head;  // Circular link maintenance
            delete temp;
        }
    }
};

int main() {
    counter l1;
    int flip = 0;
    while (flip == 0) {
        int choice;
        cout << "1. Customer arrival\n2. Customer checkout\n3. Close Checkout Counter\n4. View customers\n5. Exit program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        string temp;
        switch (choice) {
            case 1:
                cout << "Enter the name of new customer: ";
                cin >> temp;
                l1.insert(temp);
                break;
            case 2:
                l1.remove();
                break;
            case 3:
                l1.checkEmpty();
                break;
            case 4:
                l1.display();
                break;
            case 5:
                flip = 1;
                break;
            default:
                cout << "Enter a valid number!" << endl;
                break;
        }
    }
    return 0;
}
