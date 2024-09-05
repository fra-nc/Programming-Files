#include <iostream>
using namespace std;
class Node
{
public:
    string Reg_No;
    string firstname;
    string lastname;
    string fullname;
    Node *next;

    Node() {
        Reg_No = "";
        firstname = "";
        lastname = "";
        fullname="";
        next = NULL;
    }
    Node(string k, string fn, string ln ,string fln) {
        Reg_No = k;
        firstname = fn;
        lastname = ln;
        fullname =fln;
        next = NULL;
    }
};
class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkIfNodeExist(Node *n)
    {
        Node *temp = front;
        bool exist = false;
        while (temp != NULL)
        {
            if (temp->Reg_No == n->Reg_No)
            {
                exist = true;
                break;
            }
            temp = temp->next;
        }
        return exist;
    }
    void enqueue(Node *n)
    {
        if (isEmpty())
        {
            front = n;
            rear = n;
            cout << "Node ENQUEUED successfully" << endl;
        }
        else if (checkIfNodeExist(n))
        {
            cout << "Node already exist with this Reg_No value."
                 << "Enter different Reg_No" << endl;
        }
       else if (n->Reg_No < front->Reg_No) {
            n->next = front;
            front = n;

            cout << "Node ENQUEUED successfully\n" << endl;
        }
        else {
            Node *temp = front;
            while (temp->next != NULL && temp->next->Reg_No < n->Reg_No) {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
            if (temp->next == NULL) {
                front= n;
            }

            cout << "Node ENQUEUED successfully\n" << endl;
        }
    }
    Node *dequeue()
    {
        Node *temp = NULL;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return NULL;
        }
        else
        {
            if (front == rear)
            {
                temp = front;
                front = NULL;
                rear = NULL;
                return temp;
            }
            else
            {
                temp = front;
                front = front->next;
                return temp;
            }
        }
    }
    int count()
    {
        int count = 0;
        Node *temp = front;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "All students in the Queue are :" << endl;
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->Reg_No << "    " << temp->fullname << endl;
 
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    Queue q;
    int option ;
    string Reg_No, firstname, lastname, fullname;

    do
    {
        cout << "What operation do you want to perform?"
             << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. count()" << endl;
        cout << "5. display()" << endl;
        cout << "6. Clear Screen" << endl
             << endl;
        cin >> option;
        // Node n1 = new Node();
        Node *new_node = new Node();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "ENQUEUE Function Called -" << endl;
            cout << "Enter RegNo of student: ";
            cin >> Reg_No;
            cout << "Enter firstname of student: ";
            cin>>firstname;
            cout<<"Enter lastname of student: ";
            cin >>lastname;
            new_node->Reg_No = Reg_No;
            new_node->fullname =firstname + " " + lastname;
            q.enqueue(new_node);
            break;
        case 2:
            cout << "DEQUEUE Function Called - " << endl;
            new_node = q.dequeue();
            cout << "Dequeued Value is: (" << new_node->Reg_No << ","
                 << new_node->fullname<< ")";
            delete new_node;
            cout << endl;
            break;
        case 3:
            cout << "isEmpty Function Called - " << endl;
            if (q.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is NOT Empty" << endl;
            break;
        case 4:
            cout << "Count Function Called - " << endl;
            cout << "No of nodes in the Queue: " << q.count()
                 << endl;
            break;
        case 5:
            cout << "Display Function Called - " << endl;
            q.display();
            cout << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);
    return 0;
}