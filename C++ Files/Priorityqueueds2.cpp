#include <iostream>
using namespace std;

class PriorityQueue {
private:
    struct Node {
        int data;
        int priority;
        Node* next;
    };

    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(int val, int priority) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->priority = priority;
        newNode->next = nullptr;

        if (isEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Priority Queue is Empty" << endl;
            return x;
        } else {
            Node* temp = front;
            x = temp->data;
            front = front->next;
            delete temp;
            return x;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is Empty" << endl;
        } else {
            Node* temp = front;
            cout << "Priority Queue: ";
            while (temp != nullptr) {
                cout << temp->data << "(" << temp->priority << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int option, value, priority;

    do {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. Display()" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enter the value to be enqueued: ";
                cin >> value;
                cout << "Enter the priority of the value: ";
                cin >> priority;
                pq.enqueue(value, priority);
                break;
            case 2:
                cout << "Dequeued Value: " << pq.dequeue() << endl;
                break;
            case 3:
                pq.display();
                break;
            default:
                cout << "Enter Proper Option number" << endl;
        }
    } while (option != 0);

    return 0;
}
