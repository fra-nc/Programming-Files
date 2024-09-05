#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    string Reg_No;
    string firstname;
    string lastname;
    string fullname;
    char Gender;
    int Age;
    double Workshop_tecnology_1;
    double Workshop_tecnology_2;
    double Computer_science;
    double DSA;
    double Pure_Maths_1A;
    double Pure_Maths_1B;
    double Applied_Maths_1A;
    double Applied_Maths_1B;
    double Physics_1A;
    double Physics_1B;
    double ECT;
    double Aggregate;
    double Mean;
    double Grade;

    Node *next;
    Node()
    {

        firstname = "";
        lastname = "";
        fullname = "";
        Reg_No = "Nil";
        Gender = 'O';
        int Age = 0;
        Workshop_tecnology_1 = 0;
        Workshop_tecnology_2 = 0;
        Computer_science = 0;
        DSA = 0;
        Pure_Maths_1A = 0;
        Pure_Maths_1B = 0;
        Applied_Maths_1A = 0;
        Applied_Maths_1B = 0;
        Physics_1A = 0;
        Physics_1B = 0;
        ECT = 0;
        Aggregate = 0;
        Mean = 0;
        Grade = 0;

        next = NULL;
    } // Constructor with parameters
    Node(string fn, string ln, string fln, string r, char g, int a, double b, double c, double d, double e, double f, double h, double i, double j, double k, double l, double m, double n, double o, double p)
    {

        firstname = fn;
        lastname = ln;
        fullname = fln;
        Reg_No = r;
        Gender = g;
        Age = a;
        Workshop_tecnology_1 = b;
        Workshop_tecnology_2 = c;
        Computer_science = d;
        DSA = e;
        Pure_Maths_1A = f;
        Pure_Maths_1B = h;
        Applied_Maths_1A = i;
        Applied_Maths_1B = j;
        Physics_1A = k;
        Physics_1B = l;
        ECT = m;
        Aggregate = n;
        Mean = o;
        Grade = p;
        next = NULL;
    }
};
class Stack
{
public:
    Node *top;
    Stack() // Constructor
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
    void push(Node *n)
    {
        if (top == NULL)
        {
            top = n;
            cout << "Node PUSHED successfully\n"
                 << endl;
        }
        else if (checkIfNodeExist(n))
        {
            std::cout << std::endl;
            cout << "A STUDENT WITH THE Reg_No ALREADY EXISTS!!" << endl;
            cout << "ENTER A DIFFERENT Reg_No!" << endl;
            std::cout << std::endl;
        }
        else if (n->Reg_No < top->Reg_No)
        {
            n->next = top;
            top = n;

            cout << "Node PUSHED successfully\n"
                 << endl;
        }
        else
        {
            Node *temp = top;
            while (temp->next != NULL && temp->next->Reg_No < n->Reg_No)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
            if (temp->next == NULL)
            {
                top = n;
            }

            cout << "Node PUSHED successfully\n"
                 << endl;
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

            cout << temp->Reg_No << "    " << temp->fullname << " " << temp->Gender << endl;

            temp = temp->next;
        }
        // cout<< "Total no of Nodes in the stack :" <<count()
        //<<endl;
        cout << endl;
    }
};
int main()
{
    Stack s1; // Create an object of stack(this will call the constructor)
    int option;
    string Reg_No, firstname, lastname, fullname;
    char Gender;
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
            cout << "Enter firstname of student: " << endl;
            cin >> firstname;
            cout << "Enter lastname of student: " << endl;
            cin >> lastname;
            cout << "Enter the gender of student either 'M' OR 'F':" << endl;
            cin >> Gender;

            if (Gender != 'M' && Gender != 'F')
            {

                std::cout << std::endl;
                cout << "INVALID GENDER INPUT! PlEASE ENTER 'M' FOR MALE 'F' FOR FEMALE." << endl;
                std::cout << std::endl;
                break;
            }
            new_node->Reg_No = Reg_No;
            new_node->fullname = firstname + " " + lastname;
            new_node->Gender = Gender;
            s1.push(new_node);
            break;
        case 2:
            cout << "Pop Function Called - Poped Value: " << endl;
            new_node = s1.pop();
            cout << "TOP of Stack is: ( " << new_node->Reg_No << "," << new_node->fullname << "," << new_node->Gender << ")";
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
                cout << "TOP of Stack is: (" << new_node->Reg_No << "," << new_node->fullname << "," << new_node->Gender << ")" << endl;
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
