#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    string Reg_No, firstname, lastname, fullname;
    char Gender;
    int Age;
    // Marks for each subject
    double Workshop_Technology_1, Workshop_Technology_2, Computer_Science, Pure_Maths_1A;
    double Pure_Maths_1B, Applied_Maths_1A, Applied_Maths_1B, DSA;
    double Physics_1A, Physics_1B, ECT;
    // Grades for each subject
    char Workshop_Technology_1_Grade, Workshop_Technology_2_Grade, Computer_Science_Grade, DSA_Grade, Pure_Maths_1A_Grade;
    char Pure_Maths_1B_Grade, Applied_Maths_1A_Grade, Applied_Maths_1B_Grade, Physics_1A_Grade, Physics_1B_Grade, ECT_Grade;
    // Aggregate and Mean score
    double Aggregate, Mean_Score;
    char Mean_Grade;

    Node *next;
    Node()
    {
        // Initialize variables
        // Set default values
        // Initialize next to NULL
        firstname = "";
        lastname = "";
        fullname = "";
        Reg_No = "Nil";
        Gender = 'O';
        Age = 0;
        Workshop_Technology_1 = 0;
        Workshop_Technology_2 = 0;
        Computer_Science = 0;
        DSA = 0;
        Pure_Maths_1A = 0;
        Pure_Maths_1B = 0;
        Applied_Maths_1A = 0;
        Applied_Maths_1B = 0;
        Physics_1A = 0;
        Physics_1B = 0;
        ECT = 0;
        Workshop_Technology_1_Grade = 0;
        Workshop_Technology_2_Grade = 0;
        Computer_Science_Grade = 0;
        DSA_Grade = 0;
        Pure_Maths_1A_Grade = 0;
        Pure_Maths_1B_Grade = 0;
        Applied_Maths_1A_Grade = 0;
        Applied_Maths_1B_Grade = 0;
        Physics_1A_Grade = 0;
        Physics_1B_Grade = 0;
        ECT_Grade = 0;
        Aggregate = 0;
        Mean_Score = 0;
        Mean_Grade = 0;

        next = NULL;
    } // Constructor with parameters
    Node(string fn, string ln, string fln, string r, char g, int a, double b, double c, double d, double e, double f, double h, double i, double j, double k, double l, double m, double n, double o, double p, char g1, char g2, char g3, char g4, char g5, char g6, char g7, char g8, char g9, char g10, char g11)
    {
        // Assign parameter values to member variables
        // Initialize next to NULL
        firstname = fn;
        lastname = ln;
        fullname = fln;
        Reg_No = r;
        Gender = g;
        Age = a;
        Workshop_Technology_1 = b;
        Workshop_Technology_2 = c;
        Computer_Science = d;
        DSA = e;
        Pure_Maths_1A = f;
        Pure_Maths_1B = h;
        Applied_Maths_1A = i;
        Applied_Maths_1B = j;
        Physics_1A = k;
        Physics_1B = l;
        ECT = m;
        Workshop_Technology_1_Grade = g1;
        Workshop_Technology_2_Grade = g2;
        Computer_Science_Grade = g3;
        DSA_Grade = g4;
        Pure_Maths_1A_Grade = g5;
        Pure_Maths_1B_Grade = g6;
        Applied_Maths_1A_Grade = g7;
        Applied_Maths_1B_Grade = g8;
        Physics_1A_Grade = g9;
        Physics_1B_Grade = g10;
        ECT_Grade = g11;
        Aggregate = n;
        Mean_Score = o;
        Mean_Grade = p;
        next = NULL;
    }
    void calculateGrade()
    {
        // Calculate aggregate marks
        Aggregate = Workshop_Technology_1 + Workshop_Technology_2 + Computer_Science + DSA + Pure_Maths_1A +
                    Pure_Maths_1B + Applied_Maths_1A + Applied_Maths_1B + Physics_1A + Physics_1B + ECT;
        // Calculate mean marks
        Mean_Score = Aggregate / 11.0;

        // Calculate grade for the individual units
        Workshop_Technology_1_Grade = calculateUnitGrade(Workshop_Technology_1);
        Workshop_Technology_2_Grade = calculateUnitGrade(Workshop_Technology_2);
        Computer_Science_Grade = calculateUnitGrade(Computer_Science);
        DSA_Grade = calculateUnitGrade(DSA);
        Pure_Maths_1A_Grade = calculateUnitGrade(Pure_Maths_1A);
        Pure_Maths_1B_Grade = calculateUnitGrade(Pure_Maths_1B);
        Applied_Maths_1A_Grade = calculateUnitGrade(Applied_Maths_1A);
        Applied_Maths_1B_Grade = calculateUnitGrade(Applied_Maths_1B);
        Physics_1A_Grade = calculateUnitGrade(Physics_1A);
        Physics_1B_Grade = calculateUnitGrade(Physics_1B);
        ECT_Grade = calculateUnitGrade(ECT);

        // Calculate mean grade
        Mean_Grade = calculateMeanGrade();
    }

    char calculateUnitGrade(double marks)
    {
        if (marks >= 70)
            return 'A';
        else if (marks >= 60)
            return 'B';
        else if (marks >= 50)
            return 'C';
        else if (marks >= 40)
            return 'D';
        else
            return 'E';
    }

    char calculateMeanGrade()
    {

        // Assign a grade based on the Mean Score
        if (Mean_Score >= 70)
            return 'A';
        else if (Mean_Score >= 60)
            return 'B';
        else if (Mean_Score >= 50)
            return 'C';
        else if (Mean_Score >= 40)
            return 'D';
        else
            return 'E';
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
        cout << "The details of the student are:" << endl;
        Node *temp = top;
        while (temp != NULL)
        {

            cout << "Reg_No:" << temp->Reg_No << endl;
            cout << "Name:" << temp->fullname << endl;
            cout << "Gender:" << temp->Gender << endl;
            cout << "Age: " << temp->Age << endl;
            std::cout << std::endl;
            cout << "Workshop technology 1   " << temp->Workshop_Technology_1 << "  " << temp->Workshop_Technology_1_Grade << endl;
            cout << "Workshop technology 2   " << temp->Workshop_Technology_2 << "  " << temp->Workshop_Technology_2_Grade << endl;
            cout << "Computer science        " << temp->Computer_Science << "  " << temp->Computer_Science_Grade << endl;
            cout << "DSA                     " << temp->DSA << "  " << temp->DSA_Grade << endl;
            cout << "Pure Maths 1A           " << temp->Pure_Maths_1A << "  " << temp->Pure_Maths_1A_Grade << endl;
            cout << "Pure Maths 1B           " << temp->Pure_Maths_1B << "  " << temp->Pure_Maths_1B_Grade << endl;
            cout << "Applied Maths 1A        " << temp->Applied_Maths_1A << "  " << temp->Applied_Maths_1A_Grade << endl;
            cout << "Applied Maths 1B        " << temp->Applied_Maths_1B << "  " << temp->Applied_Maths_1B_Grade << endl;
            cout << "Physics 1A              " << temp->Physics_1A << "  " << temp->Physics_1A_Grade << endl;
            cout << "Physics 1B              " << temp->Physics_1B << "  " << temp->Physics_1B_Grade << endl;
            cout << "ECT                     " << temp->ECT << "  " << temp->ECT_Grade << endl;
            std::cout << std::endl;
            cout << "Aggregate                 " << temp->Aggregate << endl;
            cout << "Mean score                " << temp->Mean_Score << endl;
            cout << "Mean grade                " << temp->Mean_Grade << endl;

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
    int option, Age;
    string Reg_No, firstname, lastname, fullname;
    double Workshop_Technology_1, Workshop_Technology_2, Computer_Science, Pure_Maths_1A;
    double Pure_Maths_1B, Applied_Maths_1A, Applied_Maths_1B, DSA;
    double Physics_1A, Physics_1B, ECT, Aggregate, Mean_Score;
    char Gender, Workshop_Technology_1_Grade, Workshop_Technology_2_Grade, Computer_Science_Grade, DSA_Grade, Pure_Maths_1A_Grade;
    char Pure_Maths_1B_Grade, Applied_Maths_1A_Grade, Applied_Maths_1B_Grade, Physics_1A_Grade, Physics_1B_Grade, ECT_Grade, Mean_Grade;

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
            cout << "Enter Age of student:" << endl;
            cin >> Age;
            if (Age < 0)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT AGE SHOULD BE A NON-NEGATIVE NUMBER" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter Workshop technology 1 marks:" << endl;
            cin >> Workshop_Technology_1;
            if (Workshop_Technology_1 < 0 || Workshop_Technology_1 > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter Workshop technology 2 marks:" << endl;
            cin >> Workshop_Technology_2;
            if (Workshop_Technology_2 < 0 || Workshop_Technology_2 > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter Computer science marks:" << endl;
            cin >> Computer_Science;
            if (Computer_Science < 0 || Computer_Science > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter DSA marks:" << endl;
            cin >> DSA;
            if (DSA < 0 || DSA > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << " Enter Pure maths 1A marks:" << endl;
            cin >> Pure_Maths_1A;
            if (Pure_Maths_1A < 0 || Pure_Maths_1A > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter Pure maths 1B marks:" << endl;
            cin >> Pure_Maths_1B;
            if (Pure_Maths_1B < 0 || Pure_Maths_1B > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter Applied maths 1A marks:" << endl;
            cin >> Applied_Maths_1A;
            if (Applied_Maths_1A < 0 || Applied_Maths_1A > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter Applied maths 1B marks:" << endl;
            cin >> Applied_Maths_1B;
            if (Applied_Maths_1B < 0 || Applied_Maths_1B > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter Physics 1A marks:" << endl;
            cin >> Physics_1A;
            if (Physics_1A < 0 || Physics_1A > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter Physics 1B marks:" << endl;
            cin >> Physics_1B;
            if (Physics_1B < 0 || Physics_1B > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            cout << "Enter ECT marks:" << endl;
            cin >> ECT;
            if (ECT < 0 || ECT > 100)
            {

                std::cout << std::endl;
                cout << "INVALID INPUT MARKS ENTERED SHOULD BE BETWEEN 0 AND 100" << endl;
                std::cout << std::endl;
                break;
            }
            //Sudent details and units
            new_node->Reg_No = Reg_No;
            new_node->fullname = firstname + " " + lastname;
            new_node->Gender = Gender;
            new_node->Age = Age;
            new_node->Workshop_Technology_1 = Workshop_Technology_1;
            new_node->Workshop_Technology_2 = Workshop_Technology_2;
            new_node->Computer_Science = Computer_Science;
            new_node->DSA = DSA;
            new_node->Pure_Maths_1A = Pure_Maths_1A;
            new_node->Pure_Maths_1B = Pure_Maths_1B;
            new_node->Applied_Maths_1A = Applied_Maths_1A;
            new_node->Applied_Maths_1B = Applied_Maths_1B;
            new_node->Physics_1A = Physics_1A;
            new_node->Physics_1B = Physics_1B;
            new_node->ECT = ECT;

            //  Unit grades,Mean score, Mean grade and Aggregate
            new_node->calculateGrade();
            Workshop_Technology_1_Grade = new_node->Workshop_Technology_1_Grade;
            Workshop_Technology_2_Grade = new_node->Workshop_Technology_2_Grade;
            Computer_Science_Grade = new_node->Computer_Science_Grade;
            DSA_Grade = new_node->DSA_Grade;
            Pure_Maths_1A_Grade = new_node->Pure_Maths_1A_Grade;
            Pure_Maths_1B_Grade = new_node->Pure_Maths_1B_Grade;
            Applied_Maths_1A_Grade = new_node->Applied_Maths_1A_Grade;
            Applied_Maths_1B_Grade = new_node->Applied_Maths_1B_Grade;
            Physics_1A_Grade = new_node->Physics_1A_Grade;
            Physics_1B_Grade = new_node->Physics_1B_Grade;
            ECT_Grade = new_node->ECT_Grade;
            Aggregate = new_node->Aggregate;
            Mean_Score = new_node->Mean_Score;
            Mean_Grade = new_node->Mean_Grade;
            // Push the node into the stack
            s1.push(new_node);
            break;
        case 2:
            cout << "Pop Function Called - Poped Value: " << endl;
            new_node = s1.pop();
            cout << "Reg_No:" << new_node->Reg_No << endl;
            cout << "Name:" << new_node->fullname << endl;
            cout << "Gender:" << new_node->Gender << endl;
            cout << "Age: " << new_node->Age << endl;
            std::cout << std::endl;
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
                cout << "TOP of Stack is:" << endl;
                cout << "Reg_No:" << new_node->Reg_No << endl;
                cout << "Name:" << new_node->fullname << endl;
                cout << "Gender:" << new_node->Gender << endl;
                cout << "Age: " << new_node->Age << endl;
                std::cout << std::endl;
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
    while (!s1.isEmpty())
    {
        delete s1.pop();
    }
    cout << "Deleted Entire Stack" << endl;

    return 0;
}