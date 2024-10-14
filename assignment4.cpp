#include<iostream>
using namespace std;

// Class representing a node in a doubly linked list
class node {
    public:
    string text;    // Stores the text data of the node
    node* next;     // Pointer to the next node
    node* prev;     // Pointer to the previous node

    // Default constructor that initializes text to "NA", next and prev to NULL
    node() {
        text = "NA";
        next = NULL;
        prev = NULL;
    }

    // Parameterized constructor to initialize node with given text d 
    node(string d) {
        text = d;
        next = NULL;
        prev = NULL;
    }
};

// Class representing the TextEditor (doubly linked list)
class TextEditor {
    public:
    node* head;  // Pointer to the head (start) of the linked list

    // Constructor initializes head as NULL (empty text editor)
    TextEditor() {
        head = NULL;
    }

    // Method to insert text at the start of the list
    void insert_start(string d) {
        node* temp = new node(d);  // Create a new node with the given text
        if(head == NULL) {
            head = temp;  // If the list is empty, the new node becomes the head
        } else {
            head->prev = temp;    // Set current head's prev to new node
            temp->next = head;    // Set new node's next to current head
            head = temp;          // Update head to the new node
        }
    }

    // Method to insert text at the end of the list
    void insert_end(string d) {
        node* temp = head;
        node* new_node = new node(d);  // Create a new node with the given text
        if (head == NULL) {
            head = new_node;  // If the list is empty, new node becomes the head
        } else {
            while(temp->next != NULL) {  // Traverse to the last node
                temp = temp->next;
            }
            temp->next = new_node;  // Link last node's next to new node
            new_node->prev = temp;  // Link new node's prev to last node
            new_node->next = NULL;  // Ensure the new node's next is NULL
        }
    }

    // Method to insert text at a specific position in the list
    void insert_pos(string d, int pos) {
        node* temp = head;
        node* new_node = new node(d);  // Create a new node with the given text
        int count = 0;
        if (pos == 0) {
            insert_start(d);  // If position is 0, insert at the start
        } else {
            while (count != pos - 2 && temp != NULL) {  // Traverse to the position
                temp = temp->next;
                count++;
            }
            if(temp != NULL && temp->next != NULL) {
                new_node->next = temp->next;  // Link new node's next to node at position
                new_node->next->prev = new_node;  // Update the previous pointer of the node at the position
                temp->next = new_node;  // Link node before the position to new node
                new_node->prev = temp;  // Update new node's previous pointer
            } else {
                cout << "Invalid position\n";  // If position is beyond list length
            }
        }
    }

    // Method to delete the first node (text) in the list
    void delete_start() {
        if(head == NULL) {
            cout<<"Text Editor is Empty";  // Handle case of empty list
        } else {
            node* temp = head;
            head = head->next;   // Move head to the next node
            if(head != NULL) {
                head->prev = NULL;  // Set the new head's prev to NULL
            }
            delete temp;  // Delete the old head node
        }
    }

    // Method to delete the last node (text) in the list
    void delete_end() {
        if(head == NULL) {
            cout<<"Text Editor is Empty";  // Handle case of empty list
        } else if(head->next == NULL) {
            delete head;  // If there's only one node, delete it and reset head
            head = NULL;
        } else {
            node* temp = head;
            while(temp->next->next !=NULL) {  // Traverse to the second last node
                temp = temp->next;
            }
            delete temp->next;  // Delete the last node
            temp->next = NULL;  // Set the second last node's next to NULL
        }
    }

    // Method to delete a node (text) at a specific position
    void delete_between(int pos) {
        if(pos == 0) {
            delete_start();  // If position is 0, delete the first node
        } else {
            int count = 0;
            node* temp = head;
            while(count != pos-1 && temp != NULL) {  // Traverse to the node at the given position
                count++;
                temp = temp->next;
            }
            if(temp != NULL && temp->next != NULL) {
                node* node_to_delete = temp->next;
                temp->next = temp->next->next;  // Update the next pointer to skip the node being deleted
                if(temp->next != NULL) {
                    temp->next->prev = temp;  // Update the previous pointer of the next node
                }
                delete node_to_delete;  // Delete the node
            } else {
                cout << "Invalid position\n";  // Handle invalid position
            }
        }
    }

    // Method to find a specific text in the list
    void find(string key) {
        node* temp = head;
        int found = 0;
        while(temp != NULL) {
            if(temp->text == key) {  // If the text matches
                cout<<"Text is Found\n";
                found++;
                break;
            }
            temp = temp->next;  // Move to the next node
        }
        if(found == 0) {
            cout<<"Text is not found\n";  // If the text is not found
        }
    }

    // Method to print all the text in the list
    void print() {
        node* temp = head;
        while(temp != NULL) {
            cout << temp->text << " ";  // Print the text of each node
            temp = temp->next;  // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    TextEditor t;  // Create a new text editor object
    int flip = 0;
    while (flip == 0) {
        int choice;
        cout << "\n1.Add Text at the start\n2.Add Text at the end\n3.Add Text at a position\n4.Print all\n5.Delete Starting text\n6.Delete text at the end.\n7.Delete Text at position.\n8.Find text in the playlist.\n9.Exit Text writer\n";
        cout << "Enter your choice:";
        cin >> choice;
        string temp;
        int pos;

        // Handle user input based on the menu
        switch (choice) {
        case 1:  
            cout << "Enter the text you want to insert at start:";
            cin >> temp;
            t.insert_start(temp);  // Insert text at the start
            break;
        case 2:
            cout << "Enter the text to add at the end:";
            cin >> temp;
            t.insert_end(temp);  // Insert text at the end
            break;
        case 3:
            cout << "Enter the text to add at a position:";
            cin >> temp;
            cout << "Enter the position:";
            cin >> pos;
            t.insert_pos(temp, pos);  // Insert text at a specific position
            break;
        case 4:
            t.print();  // Print all text
            break;
        case 5:
            t.delete_start();  // Delete the first text
            break;
        case 6:
            t.delete_end();  // Delete the last text
            break;
        case 7:
            cout << "Enter the position at which you have to delete text:";
            cin >> pos;
            t.delete_between(pos);  // Delete text at a specific position
            break;
        case 8:
            cout << "Enter the text you wish to find: ";
            cin >> temp;
            t.find(temp);  // Find specific text
            break;
        case 9:
            flip = 1;  // Exit the program
            break;
        default:
            cout << "Enter a valid number:";  // Handle invalid input
        }
    }
}
