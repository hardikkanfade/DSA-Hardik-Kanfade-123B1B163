#include <iostream>
using namespace std;

class node {
    public:
    int coeff, pow;
    node* next;
    
    node() {
        coeff = 0;
        pow = 0;
        next = NULL;
    }
    
    node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class LL {
    public:
    node* head;
    
    LL() {
        head = NULL;
    }
    
    void input(int c, int p) {
        node *nn = new node(c, p);
        if(head == NULL) {
            head = nn;
        } else {
            node *temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    
    // Function to add two polynomials
    void add(LL L1, LL L2) {
        node* temp1 = L1.head;
        node* temp2 = L2.head;
        
        // Initialize result as an empty list
        head = NULL;
        node* curr = NULL;
        
        while(temp1 != NULL || temp2 != NULL) {
            int c = 0, p = 0;
            if(temp1 == NULL) { // If L1 is exhausted, use L2's term
                c = temp2->coeff;
                p = temp2->pow;
                temp2 = temp2->next;
            }
            else if(temp2 == NULL) { // If L2 is exhausted, use L1's term
                c = temp1->coeff;
                p = temp1->pow;
                temp1 = temp1->next;
            }
            else if(temp1->pow > temp2->pow) { // Use L1's term if it has a higher power
                c = temp1->coeff;
                p = temp1->pow;
                temp1 = temp1->next;
            }
            else if(temp1->pow < temp2->pow) { // Use L2's term if it has a higher power
                c = temp2->coeff;
                p = temp2->pow;
                temp2 = temp2->next;
            }
            else { // If both terms have the same power, add their coefficients
                c = temp1->coeff + temp2->coeff;
                p = temp1->pow;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            
            node* nn = new node(c, p);
            
            if(head == NULL) { // Initialize the head if it’s the first node
                head = nn;
                curr = head;
            } else { // Link the new node to the result list
                curr->next = nn;
                curr = curr->next;
            }
        }
    }
    
    // Display function
    void display() {
        node *temp = head;
        while(temp != NULL) {
            cout << temp->coeff << "x^" << temp->pow;
            if(temp->next != NULL) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Function to input multiple terms
    void inputPolynomial() {
        int coeff, pow;
        char choice;
        do {
            cout << "Enter coefficient and power (e.g., 3 2 for 3x^2): ";
            cin >> coeff >> pow;
            input(coeff, pow);
            cout << "Add another term? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }
};

int main() {
    LL L1, L2, L3;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input terms for Polynomial 1\n";
        cout << "2. Input terms for Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomial 1 and Polynomial 2\n";
        cout << "6. Display Resultant Polynomial\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Input terms for Polynomial 1:\n";
                L1.inputPolynomial();
                break;

            case 2:
                cout << "Input terms for Polynomial 2:\n";
                L2.inputPolynomial();
                break;

            case 3:
                cout << "Polynomial 1: ";
                L1.display();
                break;

            case 4:
                cout << "Polynomial 2: ";
                L2.display();
                break;

            case 5:
                L3.add(L1, L2);
                cout << "Polynomials added successfully!\n";
                break;

            case 6:
                cout << "Resultant Polynomial: ";
                L3.display();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
