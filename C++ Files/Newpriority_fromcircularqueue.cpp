#include <iostream>
#include <queue> 
using namespace std;

class PriorityQueue {
private:
    priority_queue<int> prq;

public:
    void enqueue(int val) {
        prq.push(val);
    }

    int dequeue() {
        if (!prq.empty()) {
            int top = prq.top();
            prq.pop();
            return top;
        }
        cout << "The priority queue is empty" << endl;
        return -1;
    }

    bool isEmpty() {
        return prq.empty();
    }

    int count() {
        return prq.size();
    }

    void display() { // Corrected syntax here
        priority_queue<int> temp = prq;

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue prq;
    int value, option;
    do {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. count()" << endl;
        cout << "5. display()" << endl;
        cout << "6. Clear Screen" << endl << endl;
        cin >> option;
        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enqueue Operation\nEnter an item to Enqueue in the priority queue: ";
                cin >> value;
                prq.enqueue(value);
                break;
            case 2:
                cout << "Dequeue Operation\nDequeued Value: " << prq.dequeue() << endl;
                break;
            case 3:
                if (prq.isEmpty())
                    cout << "The priority Queue is Empty!" << endl;
                else
                    cout << "The priority Queue is not Empty" << endl;
                break;
            case 4:
                cout << "The number of elements in the priority queue is: " << prq.count() << endl;
                break;
            case 5:
                cout << "The elements of the priority queue are:" << endl;
                prq.display();
                break;
            case 6:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number" << endl;
        }
    } while (option != 0);
    return 0;
}
