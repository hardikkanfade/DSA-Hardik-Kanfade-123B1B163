#include<iostream>
using namespace std;

// Class representing each route (city) in the linked list
class route {
public:
    string city; // Stores the name of the city
    route* next; // Pointer to the next node in the linked list

    // Default constructor to initialize city with "NA" and next with NULL
    route() {
        city = "NA";
        next = NULL;
    }

    // Parameterized constructor to initialize city with a given name
    route(string d) {
        city = d;
        next = NULL;
    }
};

// Class for the linked list (LL) that manages the routes (cities)
class LL {
    route* head; // Pointer to the head of the linked list (the first city)

public:
    // Constructor to initialize the head of the list to NULL
    LL() {
        head = NULL;
    }

    // Function to insert a city at the start of the list
    void insert_start(string d);

    // Function to insert a city at the end of the list
    void insert_end(string d);

    // Function to insert a city at a given position in the list
    void insert_at_position(string d, int pos);

    // Function to delete the city at the start of the list
    void delete_start();

    // Function to delete the city at the end of the list
    void delete_end();

    // Function to delete a city at a given position in the list
    void delete_at_position(int pos);

    // Function to print all cities in the list
    void print();
};

// Function to insert a city at the start of the circular linked list
void LL::insert_start(string d) {
    route* nn = new route(d); // Create a new route node
    if (head == NULL) { // If the list is empty
        head = nn; // Set the new node as the head
        nn->next = head; // Make it point to itself (circular behavior)
    } else {
        route *temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = nn; // Link the last node to the new node
        nn->next = head; // Link the new node to the current head
        head = nn; // Update the head to the new node
    }
}

// Function to insert a city at the end of the circular linked list
void LL::insert_end(string d) {
    route* nn = new route(d); // Create a new route node
    route* temp = head;
    if (head == NULL) { // If the list is empty
        head = nn; // Set the new node as the head
        nn->next = head; // Circular link to itself
    } else {
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = nn; // Link the last node to the new node
        nn->next = head; // Link the new node to the head (circular)
    }
}

// Function to insert a city at a specific position in the circular linked list
void LL::insert_at_position(string d, int pos) {
    route* nn = new route(d); // Create a new route node
    if (pos == 0) { // If inserting at position 0
        insert_start(d); // Use insert_start() function
        return;
    }
    route* temp = head;
    int current_pos = 0;
    // Traverse the list until we reach the desired position
    while (temp != NULL && current_pos < pos - 1) {
        temp = temp->next;
        current_pos++;
    }
    if (temp == NULL) { // If the position is out of range
        cout << "Position out of range." << endl;
        return;
    }
    nn->next = temp->next; // Link the new node to the next node
    temp->next = nn; // Link the previous node to the new node
}

// Function to delete the city at the start of the circular linked list
void LL::delete_start() {
    if (head == NULL) { // If the list is empty
        cout << "Linked list is Empty";
    } else {
        route* temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = head->next; // Link the last node to the second node
        route* temp2 = head; // Temporary pointer to the current head
        head = head->next; // Update the head to the second node
        delete temp2; // Delete the old head
    }
}

// Function to delete the city at the end of the circular linked list
void LL::delete_end() {
    if (head == NULL) { // If the list is empty
        cout << "Linked List is Empty";
    } else if (head->next == head) { // If there is only one node
        delete head; // Delete the only node
        head = NULL; // Set the head to NULL
    } else {
        route* temp = head;
        while (temp->next->next != head) { // Traverse to the second-last node
            temp = temp->next;
        }
        delete temp->next; // Delete the last node
        temp->next = head; // Link the second-last node to the head
    }
}

// Function to delete a city at a specific position in the circular linked list
void LL::delete_at_position(int pos) {
    if (head == NULL) { // If the list is empty
        cout << "Linked list is Empty";
    } else {
        route* temp = head;
        route* curr = new route();
        int count = 0;
        // Traverse to the node before the desired position
        while (count != pos - 1) {
            count++;
            temp = temp->next;
        }
        curr = temp->next; // Node to be deleted
        temp->next = temp->next->next; // Link the previous node to the next node
        delete curr; // Delete the node
    }
}

// Function to print all the cities in the circular linked list
void LL::print() {
    route* temp = head;
    cout << temp->city << " "; // Print the first city
    while (temp->next != head) { // Traverse and print until the list circles back to the head
        cout << temp->next->city << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function for user interaction with the linked list
int main() {
    LL list; // Create a linked list object
    int flip = 0; // Control flag for the menu
    while (flip == 0) {
        int choice;
        // Display the menu options
        cout << "\n1.Add city at the start\n2.Add city at the end\n3.Add city at a position\n4.Print route\n5.Delete Start city\n6.Delete End city.\n7.Delete city at position\n8.End program\n";
        cout << "Enter your choice:";
        cin >> choice;
        string temp;
        switch (choice) {
        case 1:
            // Insert a city at the start
            cout << "Enter city to insert at start:";
            cin >> temp;
            list.insert_start(temp);
            break;
        case 2:
            // Insert a city at the end
            cout << "Enter the city to add at the end:";
            cin >> temp;
            list.insert_end(temp);
            break;
        case 3:
            // Insert a city at a specific position
            int pos;
            cout << "Enter the city to add at a position:";
            cin >> temp;
            cout << "Enter the position:";
            cin >> pos;
            list.insert_at_position(temp, pos);
            break;
        case 4:
            // Print the entire route (cities in the list)
            list.print();
            break;
        case 5:
            // Delete the city at the start
            list.delete_start();
            break;
        case 6:
            // Delete the city at the end
            list.delete_end();
            break;
        case 7:
            // Delete a city at a specific position
            int temp4;
            cout << "Enter the position at which you want to delete:";
            cin >> temp4;
            list.delete_at_position(temp4);
            break;
        case 8:
            // Exit the program
            flip = 1;
            break;
        default:
            // Handle invalid input
            cout << "Enter a valid number:";
        }
    }
    return 0;
}
