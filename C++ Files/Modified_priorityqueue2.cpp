// Priority_Queue_C++_Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <queue>
using namespace std;

class PriorityQueue {
private:
    int front;
    int rear;
    int arr[5];
    int itemCount;

public:
    PriorityQueue() {
        itemCount = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0;
        }
    }

    bool isEmpty() {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if ((rear + 1) % 5 == front)
            return true;
        else
            return false;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Priority Queue full" << endl;
            return;
        } else if (isEmpty()) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        } else {
            int i=rear;
            while(i>= front && val >arr[i]){
                arr[(i+1)%5]=arr[i];
                i=(i-1)%5;
            }
            arr[(i+1)%5]=val;
            rear=(rear+1)%5;
        }
        itemCount++;
    }

    int dequeue() {
        int x = 0;
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return x;
        } else if (rear == front) {
            x = arr[rear];
            rear = -1;
            front = -1;
            itemCount--;
            return x;
        } else {
            cout << "front value: " << front << endl;
            x = arr[front];
            arr[front] = 0;
            front = (front + 1) % 5;
            itemCount--;
            return x;
        }
    }

    int count() {
        return (itemCount);
    }

    void display() {
        cout << "All values in the  Priority Queue are - " << endl;
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    PriorityQueue pqr;
    int value, option;

    do {
        cout << "\n\nWhat operation do you want to perform? Select Option number.Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;
        cin >> option;

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Enqueue Operation \nEnter an item to Enqueue in the Priority Queue " << endl;
            cin >> value;
            pqr.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Operation \nDequeued Value : " << pqr.dequeue() << endl;
            break;
        case 3:
            if (pqr.isEmpty())
                cout << " Priority Queue is Empty" << endl;
            else
                cout << "Priority Queue is not Empty" << endl;
            break;
        case 4:
            if (pqr.isFull())
                cout << "Priority Queue is Full" << endl;
            else
                cout << "Priority Queue is not Full" << endl;
            break;
        case 5:
            cout << "Count Operation \nCount of items in the Priority Queue : " << pqr.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            pqr.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);
    return 0;
}