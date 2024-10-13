#include<iostream>
using namespace std;

// Class representing a single song (node in the linked list)
class song {
public:
    string song_title; // Stores the title of the song
    song* next;        // Pointer to the next song in the playlist

    // Default constructor to initialize song with "NA" and next pointer as NULL
    song() {
        song_title = "NA";
        next = NULL;
    } 

    // Parameterized constructor to initialize song with a title
    song(string d) {
        song_title = d;
        next = NULL;
    }
};

// Class representing the playlist (linked list of songs)
class playlist {
    song* head;  // Pointer to the first song in the playlist
public:
    // Constructor initializes head as NULL (empty playlist)
    playlist() {
        head = NULL; 
    }

    // Method declarations for playlist operations
    void insert_start(string d);            // Insert song at the start
    void insert_end(string d);              // Insert song at the end
    void insert_at_position(string d, int pos); // Insert song at a specific position
    void delete_start();                    // Delete the first song
    void delete_end();                      // Delete the last song
    void delete_at_position(int pos);       // Delete a song at a specific position
    void find(string key);                  // Find a song in the playlist
    void print();                           // Print all songs in the playlist
};

// Method to insert a song at the start of the playlist
void playlist::insert_start(string d) {
    song* nn = new song(d);  // Create a new song node
    if (head == NULL) {      // If the playlist is empty, new song becomes head
        head = nn;
    } else {
        nn->next = head;     // Point the new song's next to the current head
        head = nn;           // Update head to the new song
    }
}

// Method to insert a song at the end of the playlist
void playlist::insert_end(string d) {
    song* nn = new song(d);  // Create a new song node
    song* temp = head;
    if (head == NULL) {      // If the playlist is empty, new song becomes head
        head = nn;
    } else {
        while (temp->next != NULL) { // Traverse to the last song
            temp = temp->next;
        }
        temp->next = nn;      // Link the last song to the new song
    }
}

// Method to insert a song at a specific position in the playlist
void playlist::insert_at_position(string d, int pos) {
    song* nn = new song(d);  // Create a new song node
    if (pos == 0) {          // If position is 0, insert at the start
        insert_start(d);
        return;
    }
    song* temp = head;
    int current_pos = 0;
    // Traverse to the position where the new song will be inserted
    while (temp != NULL && current_pos < pos - 1) {
        temp = temp->next;
        current_pos++;
    }
    // If position is beyond list size
    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
    nn->next = temp->next;  // Link new song to the next song
    temp->next = nn;        // Link the previous song to the new song
}

// Method to delete the first song in the playlist
void playlist::delete_start() {
    if (head == NULL) {      // If the playlist is empty
        cout << "Linked list is Empty";
    } else {
        song * temp = head;  // Store the current head
        head = head->next;   // Move head to the next song
        delete temp;         // Delete the old head
    }
}

// Method to delete the last song in the playlist
void playlist::delete_end() {
    if (head == NULL) {      // If the playlist is empty
        cout << "Linked List is Empty";
    } else if (head->next == NULL) { // If there's only one song
        delete head;         // Delete the single song
        head = NULL;         // Set head to NULL (empty playlist)
    } else {
        song *temp = head;
        // Traverse to the second last song
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;   // Delete the last song
        temp->next = NULL;   // Set the second last song's next to NULL
    }
}

// Method to delete a song at a specific position
void playlist::delete_at_position(int pos) {
    if (head == NULL) {      // If the playlist is empty
        cout << "Linked list is Empty";
    } else {
        song* temp = head;
        song *curr = new song();
        int count = 0;
        // Traverse to the position where the song needs to be deleted
        while (count != pos - 1) {
            count++;
            temp = temp->next;
        }
        curr = temp->next;  // Store the song to be deleted
        temp->next = temp->next->next; // Unlink the song
        delete curr;        // Delete the song
    }
}

// Method to find a song by title in the playlist
void playlist::find(string key) {
    song *temp = head;
    int found = 0;
    if (head == NULL) {      // If the playlist is empty
        cout << "Playlist is Empty";
    } else {
        while (temp != NULL) { // Traverse the playlist
            if (temp->song_title == key) { // If the song title matches
                cout << "Song is found\n";
                found++;
                break;       // Stop if the song is found
            }
            temp = temp->next; // Move to the next song
        }
        if (!found) {        // If song is not found
            cout << "Song is not present in the playlist\n";
        }
    }
}

// Method to print all songs in the playlist
void playlist::print() {
    song* temp = head;
    while (temp != NULL) {    // Traverse the playlist
        cout << temp->song_title << " "; // Print each song title
        temp = temp->next;    // Move to the next song
    }
    cout << endl;
}

// Main program to run the playlist operations
int main() {
    playlist list;  // Create a new playlist
    int flip = 0;   // To keep the menu running
    while (flip == 0) {
        int choice;
        // Display the menu
        cout << "\n1. Add Song at the start\n2. Add song at the end\n3. Add song at a position\n4. Print all the songs\n5. Delete Starting song\n6. Delete song at the end.\n7. Delete at position.\n8. Find song in the playlist.\n9. Exit playlist\n";
        cout << "Enter your choice:";
        cin >> choice;
        string temp;
        int pos;

        // Switch case to handle user input
        switch (choice) {
        case 1:  
            cout << "Enter the song you want to insert at start:";
            cin >> temp;
            list.insert_start(temp);
            break;
        case 2:
            cout << "Enter the song to add at the end:";
            cin >> temp;
            list.insert_end(temp);
            break;
        case 3:
            cout << "Enter the song to add at a position:";
            cin >> temp;
            cout << "Enter the position:";
            cin >> pos;
            list.insert_at_position(temp, pos);
            break;
        case 4:
            list.print();  // Print all songs in the playlist
            break;
        case 5:
            list.delete_start(); // Delete the first song
            break;
        case 6:
            list.delete_end();   // Delete the last song
            break;
        case 7:
            cout << "Enter the position at which you have to delete node:";
            cin >> pos;
            list.delete_at_position(pos); // Delete song at the given position
            break;
        case 8:
            cout << "Enter the song title you wish to find: ";
            cin >> temp;
            list.find(temp); // Find the song by title
            break;
        case 9:
            flip = 1;   // Exit the menu
            break;
        default:
            cout << "Enter a valid number:"; // Invalid choice
        }
    }
    return 0;
}
