#include <iostream>
using namespace std;

class Node {
public:
    string RegNo;
    string firstname;
    string lastname;
    string fullname;
    Node *next;

    Node() {
        RegNo = "";
        firstname = "";
        lastname = "";
        fullname="";
        next = NULL;
    }
    Node(string k, string fn, string ln ,string fln) {
        RegNo = k;
        firstname = fn;
        lastname = ln;
        fullname =fln;
        next = NULL;
    }
};

class Stack {
public:
    Node *top;

    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        if (top == NULL) {
            return true;
        }
        else {
            return false;
        }
    }

    bool checkIfNodeExist(Node *n) {
        Node *temp = top;
        bool exist = false;

        while (temp != NULL) {
            if (temp->RegNo == n->RegNo) {
                exist = true;
                break;
            }
            temp = temp->next;
        }
        return exist;
    }

    void push(Node *n) {
        if (top == NULL) {
            top = n;
            cout << "Node PUSHED successfully\n" << endl;
        }
        else if (checkIfNodeExist(n)) {
            cout << "Node already exist with this RegNo value.\n" << "Enter different RegNo value" << endl << endl;
        }
        else if (n->RegNo < top->RegNo) {
            n->next = top;
            top = n;

            cout << "Node PUSHED successfully\n" << endl;
        }
        else {
            Node *temp = top;
            while (temp->next != NULL && temp->next->RegNo < n->RegNo) {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
            if (temp->next == NULL) {
                top = n;
            }

            cout << "Node PUSHED successfully\n" << endl;
        }
    }

    Node *pop() {
        Node *temp = NULL;
        if (isEmpty()) {
            cout << "stack underflow\n" << endl;
            return temp;
        }
        else {
            temp = top;
            top = top->next;
            return temp;
        }
    }

    Node *peek() {
        // Node *temp = NULL;
        if (isEmpty()) {
            cout << "stack underflow\n" << endl;
            return NULL;
        }
        else {
            return top;
        }
    }

    int count() {
        int count = 0;
        Node *temp = top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        cout << "All values in the Stack are :" << endl;
        Node *temp = top;
        while (temp != NULL) {
            cout << "(" << temp->RegNo << "," << temp->fullname << ")";
            if (temp->next != NULL) {
                cout << " -> ";
            }
            cout << endl;
            temp = temp->next;
        }
        // cout<< "Total no of Nodes in the stack :" <<count()
        //<<endl;
        cout << endl;
    }
};

int main() {
    Stack s1;
    int option;
    string RegNo, firstname, lastname, fullname;

    do {
        cout << "What operation do you want to perform?" << "Select Option number. \nEnter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. peek()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;
        cin >> option;
        // Node n1 = new Node();
        Node *new_node = new Node();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Enter RegNo of student: ";
            cin >> RegNo;
            cout << "Enter firstname of student: ";
            cin>>firstname;
            cout<<"Enter lastname of student: ";
            cin >>lastname;
            new_node->RegNo = RegNo;
            new_node->fullname =firstname + " " + lastname;
            s1.push(new_node);
            break;
        case 2:
            cout << "Pop Function Called - Poped Value: " << endl;
            new_node = s1.pop();
            if (new_node != NULL) {
                cout << "TOP of Stack is: (" << new_node->RegNo << "," << new_node->fullname << ")";
                delete new_node;
            }
            cout << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "Stack is Empty" << endl << endl;
            else
                cout << "Stack is not Empty" << endl << endl;
            break;
        case 4:
            if (s1.isEmpty()) {
                cout << "Stack is Empty" << endl;
            }
            else {
                cout << "PEEK Function Called : " << endl;
                new_node = s1.peek();
                cout << "TOP of Stack is: (" << new_node->RegNo << "," << new_node->fullname << ")" << endl << endl;
            }
            break;
        case 5:
            cout << "Count Function Called: " << endl;
            cout << "No of nodes in the Stack: " << s1.count() << endl << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            s1.display();
            cout << endl;
            break;
        case 7:
            system("clear");
            break;
        default:
            cout << "Enter Proper Option number " << endl << endl;
        }
    } while (option != 0);

    while (!s1.isEmpty()) {
        delete s1.pop();
    }
    cout << "Deleted Entire Stack" << endl;

    return 0;
}