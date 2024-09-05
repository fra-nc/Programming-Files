#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    
    string Reg_No;
    string Name;
    Node *next;
    Node()
    {
        
        Name = "Nil";
        Reg_No = "Nil";
        next = NULL;
    }
    Node(string n, string r )
    {
        
        Name = n;
        Reg_No = r;
        next = NULL;
    }
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        if (top == NULL)
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
        Node *temp = top;
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
    void push(Node *n) {
        if (top == NULL) {
            top = n;
            cout << "Node PUSHED successfully\n" << endl;
        }
        else if (checkIfNodeExist(n)) {
            std::cout<<std::endl;
            cout << "A STUDENT WITH THE Reg_No ALREADY EXISTS!!" << endl;
            cout<<"ENTER A DIFFERENT Reg_No!"<<endl;
            std::cout<<std::endl;
        }
        else if (n->Reg_No < top->Reg_No) {
            n->next = top;
            top = n;

            cout << "Node PUSHED successfully\n" << endl;
        }
        else {
            Node *temp = top;
            while (temp->next != NULL && temp->next->Reg_No < n->Reg_No) {
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

    Node *pop()
    {
        Node *temp = NULL;
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return temp;
        }
        else
        {
            temp = top;
            top = top->next;
            return temp;
        }
    }
    Node *peek()
    {
        // Node *temp = NULL;
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return NULL;
        }
        else
        {
            return top;
        }
    }
    int count()
    {
        int count = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display()
    {
        cout << "The students in the class are:" << endl;
        Node *temp = top;
        while (temp != NULL)
        {

            cout << temp->Reg_No << "    " << temp->Name << endl;

            temp = temp->next;
        }
        // cout<< "Total no of Nodes in the stack :" <<count()
        //<<endl;
        cout << endl;
    }
};
    int main()
{
    Stack s1;
    int option;
    string Name, Reg_No;
    do
    {
        cout << "What operation do you want to perform?"
             << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. peek()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;
        cin >> option;
        // Node n1 = new Node();
        Node *new_node = new Node();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter Reg_No of student :" << endl;
            cin >> Reg_No;
            cout<<"Enter the name of student:"<<endl;
            cin >> Name;
            new_node->Reg_No = Reg_No;
            new_node->Name = Name;
            s1.push(new_node);
            break;
        case 2:
            cout << "Pop Function Called - Poped Value: " << endl;
            new_node = s1.pop();
            cout << "TOP of Stack is: ( "<< new_node->Reg_No<< ","<<new_node->Name<< ")";
            delete new_node;
            cout << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            if (s1.isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "PEEK Function Called : " << endl;
                new_node = s1.peek();
                cout << "TOP of Stack is: (" << new_node->Reg_No <<  ","<<new_node->Name<<  ")" <<endl;
            }
            break;
        case 5:
            cout << "Count Function Called: " << endl;
            cout << "No of students in the Stack: " << s1.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            s1.display();
            cout << endl;
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
