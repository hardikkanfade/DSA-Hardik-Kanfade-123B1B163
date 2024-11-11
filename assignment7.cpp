#include <iostream>
using namespace std;

#define MAX_ELEMENTS 10

class History {
    string stack[MAX_ELEMENTS];
    string stack2[MAX_ELEMENTS];
    int top1 = -1; // Top for current history stack
    int top2 = -1; // Top for back history stack
    
    public:
    void input(string str) {
        if(top1 == MAX_ELEMENTS - 1) {
            cout << "Search history is full" << endl;
        } else {
            top1++;
            stack[top1] = str;
            top2 = -1; // Clear forward stack whenever a new history entry is added
        }
    }
    
    void peek() {
        if(top1 == -1) {
            cout << "Search history is empty" << endl;
        } else {
            cout << "Current page: " << stack[top1] << endl;
        }
    }
    
    void check_empty() {
        if(top1 == -1) {
            cout << "Your search history is empty" << endl;
        } else {
            cout << "Your search history is not empty" << endl;
        }
    }
    
    void back_navigate() {
        if(top1 == -1) {
            cout << "History is empty" << endl;
        } else {
            top2++;
            stack2[top2] = stack[top1];
            top1--;
        }
    }
    
    void front_navigate() {
        if(top2 == -1) {
            cout << "All history is restored" << endl;
        } else if(top1 == MAX_ELEMENTS - 1) {
            cout << "Cannot navigate forward, history stack is full" << endl;
        } else {
            top1++;
            stack[top1] = stack2[top2];
            top2--;
        }
    }
    
    void print() {
        if(top1 == -1) {
            cout << "Search history is empty" << endl;
        } else {
            cout << "Current history stack:\n";
            for(int i = top1; i >= 0; i--) {
                cout << stack[i] << endl;
            }
        }
    }
};

int main() {
    History h1;
    int flip = 0;
    while(flip == 0) {
        int choice;
        cout << "\n1. Add history\n2. Back navigate\n3. Forward navigate\n";
        cout << "4. Peek\n5. Check if empty\n6. Print history\n7. End program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        string temp;
        switch(choice) {
            case 1:
                cout << "Enter the website name: ";
                cin >> temp;
                h1.input(temp);
                break;
            case 2:
                h1.back_navigate();
                break;
            case 3:
                h1.front_navigate();
                break;
            case 4:
                h1.peek();
                break;
            case 5:
                h1.check_empty();
                break;
            case 6:
                h1.print();
                break;
            case 7:
                flip = 1;
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Enter a valid number" << endl;
                break;
        }
    }
    return 0;
}
