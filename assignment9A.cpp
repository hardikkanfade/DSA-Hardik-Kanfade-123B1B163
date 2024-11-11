#include <iostream>
using namespace std;

class Wait {
public:
    string queue[10];
    int front = -1, rear = -1, size = 10;

    void add_queue(string n) {
        if (rear == size - 1) {
            cout << "Queue is Full" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            queue[++rear] = n;
        }
    }

    void remove() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty" << endl;
            front = rear = -1; // Reset the queue pointers if empty
        } else {
            cout << "Removed: " << queue[front] << endl;
            front++;
            if (front > rear) { // Reset if the queue is empty after removal
                front = rear = -1;
            }
        }
    }

    void print() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Wait w1;
    int choice;
    string name;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add to Queue" << endl;
        cout << "2. Remove from Queue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name to add to the queue: ";
                cin >> name;
                w1.add_queue(name);
                break;
            case 2:
                w1.remove();
                break;
            case 3:
                w1.print();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0;
}
