#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <thread>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>

using namespace std;

#define SPACE 10

void clearScreen()
{
    system("cls");
}

// -------------------------- Linked List Starts here ----------------------

class NodeLL
{
public:
    int data;

    NodeLL *next;
    NodeLL *prev;

    NodeLL()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    NodeLL(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }

    ~NodeLL()
    {
        cout << "Deleted Node\n";
    }
};

class LinkedLists
{
public:
    NodeLL *head;
    NodeLL *tail;

    LinkedLists()
    {
        head = NULL;
        tail = NULL;
    }

    void InsertSinglyLast(int num)
    {

        NodeLL *newnode = new NodeLL(num);
        NodeLL *temp = head;
        if (head == NULL)
        {
            head = newnode;
            head->next = NULL;
            cout << "Inserted " << num << " at the last after making a new node [ " << num << " | * ]" << endl;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
            cout << "Inserted " << num << " at the last after making a new node [ " << num << " | * ]" << endl;
        }
    }

    void InsertSinglyFirst(int num)
    {
        NodeLL *newnode = new NodeLL(num);
        if (head == NULL)
        {
            head = newnode;
            head->next = NULL;
            cout << "Inserted " << num << " at the start after making a new node [ " << num << " | * ]" << endl;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            cout << "Inserted " << num << " at the start after making a new node [ " << num << " | * ]" << endl;
        }
    }

    void AddafterSinglyNode(int value, int num)
    {
        NodeLL *newnode = new NodeLL(num);
        NodeLL *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data == value)
            {
                newnode->next = temp->next;
                temp->next = newnode;
                cout << "Inserted " << num << " after making a new node [ " << num << " | * ] and inserting it after node of " << value << endl;
            }
            temp = temp->next;
        }
    }

    void UpdateSinglyNode(int num, int value)
    {
        NodeLL *temp = head;
        while (temp->next != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        cout << "\n\nWhen updating, we just change the values in the nodes of the linked list after travrsing to find which number is to be replaced" << endl;
        cout << "\nIn our case, we want to replace " << value << " with " << num << endl;
        temp->data = num;
    }

    void DeleteSinglyNode(int value)
    {
        NodeLL *temp = head;
        NodeLL *prev;
        while (temp->next != NULL && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }
        cout << "\nWhen deleting uses previous pointer of the node to be deleted [ " << prev->data << " | * ]-> and points it to the node after the node being deleted [ " << temp->next->data << " | * ]" << endl;
        prev->next = temp->next;
        delete temp;
    }

    void printSinglyList()
    {
        NodeLL *temp = head;
        int i = 1;

        while (temp->next != NULL)
        {
            clock_t start_time = clock();
            int delay_seconds = 1;
            while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
                ;

            cout << "|" << temp->data << "|*|--->";
            i++;
            temp = temp->next;
            // cout << endl;
        }
        clock_t start_time = clock();
        int delay_seconds = 1;
        while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
            ;

        cout << "|" << temp->data << "|*|--> NULL";
        i++;
        temp = temp->next;
    }

    // Doubly Linked List

    void InsertDoublyLast(int num)
    {

        NodeLL *newnode = new NodeLL(num);
        NodeLL *temp = head;
        if (head == NULL)
        {
            head = newnode;
            tail = head;
            cout << "Inserted " << num << " at the last after making a new node [ " << num << " | * ]" << endl;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            tail->next = NULL;
            cout << "Inserted " << num << " at the last after making a new node [ " << num << " | * ]" << endl;
        }
    }

    void InsertDoublyFirst(int num)
    {
        NodeLL *newnode = new NodeLL(num);
        if (head == NULL)
        {
            head = newnode;
            tail = head;
            cout << "Inserted " << num << " at the start after making a new node [ " << num << " | * ]" << endl;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            cout << "Inserted " << num << " at the start after making a new node [ " << num << " | * ]" << endl;
        }
    }

    void AddafterDoublyNode(int value, int num)
    {
        NodeLL *newnode = new NodeLL(num);
        NodeLL *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data == value)
            {
                newnode->next = temp->next;
                temp->next->prev = newnode;
                temp->next = newnode;
                newnode->prev = temp;
                cout << "Inserted " << num << " after making a new node [ " << num << " | * ] and inserting it after node of " << value << endl;
            }
            temp = temp->next;
        }
    }

    void UpdateDoublyNode(int num, int value)
    {
        NodeLL *temp = head;
        while (temp->next != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        cout << "\n\nWhen updating, we just change the values in the nodes of the linked list after travrsing to find which number is to be replaced" << endl;
        cout << "\nIn our case, we want to replace " << value << " with " << num << endl
             << endl;
        temp->data = num;
    }

    void DeleteDoublyNode(int value)
    {
        NodeLL *temp = head;
        while (temp->next != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        cout << "\nWhen deleting uses previous pointer of the node to be deleted [ " << temp->prev->data << " | * ]<---> and points it to the node after the node being deleted [ " << temp->data << " | * ]" << endl;
        temp->prev->next = temp->next;
        delete temp;
    }

    void printDoublyList()
    {
        NodeLL *temp = head;
        int i = 1;
        cout << "NULL<---->";
        while (temp->next != NULL)
        {
            clock_t start_time = clock();
            int delay_seconds = 1.5;
            while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
                ;

            cout << "|" << temp->data << "|*|<---->";
            i++;
            temp = temp->next;
        }

        // Print the last node without "NULL" after it
        clock_t start_time = clock();
        int delay_seconds = 1.5;
        while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
            ;

        cout << "|" << temp->data << "|*|<----> NULL" << endl;
        i++;
    }

    // Circular Linked List

    void AddinCircularLast(int num)
    {
        NodeLL *newnode = new NodeLL(num);
        if (head == NULL)
        {
            head = newnode;
            tail = head;
            cout << "Inserted " << num << " at the last after making a new node [ " << num << " | * ]" << endl;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
            cout << "Inserted " << num << " at the last after making a new node [ " << num << " | * ]" << endl;
        }
    }

    void AddinCircularFirst(int num)
    {
        NodeLL *newnode = new NodeLL(num);
        if (head == NULL)
        {
            head = newnode;
            tail = head;
            cout << "Inserted " << num << " at the start after making a new node [ " << num << " | * ]" << endl;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = head;
            cout << "Inserted " << num << " at the start after making a new node [ " << num << " | * ]" << endl;
        }
    }

    void AddafterCircularNode(int value, int num)
    {
        NodeLL *newnode = new NodeLL(num);
        NodeLL *temp = head;
        while (temp->next != head)
        {
            if (temp->data == value)
            {
                newnode->next = temp->next;
                temp->next = newnode;
                cout << "Inserted " << num << " after making a new node [ " << num << " | * ] and inserting it after node of " << value << endl;
            }
            temp = temp->next;
        }
    }

    void DeleteCircularNode(int value)
    {
        NodeLL *temp = head;
        NodeLL *prev;
        while (temp->next != head && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }
        cout << "\n\nWhen deleting uses previous pointer of the node to be deleted [ " << prev->data << " | * ]---> and points it to the node after the node being deleted [ " << temp->data << " | * ]" << endl;
        prev->next = temp->next;
        delete temp;
    }

    void UpdateCircularNode(int d, int value)
    {
        NodeLL *temp = head;
        while (temp->next != head && temp->data != value)
        {
            temp = temp->next;
        }
        cout << "\n\nWhen updating, we just change the values in the nodes of the linked list after travrsing to find which number is to be replaced" << endl;
        cout << "\nIn our case, we want to replace " << d << " with " << value << endl;
        temp->data = d;
    }

    void printCircularList()
    {
        NodeLL *temp = head;
        int i = 1;

        while (temp->next != head)
        {
            clock_t start_time = clock();
            int delay_seconds = 1.5;
            while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
                ;

            cout << "-->|" << temp->data << "|*|--";
            i++;
            temp = temp->next;
        }
        clock_t start_time = clock();
        int delay_seconds = 1.5;
        while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
            ;

        cout << ">|" << temp->data << "|*|--";
        i++;
        temp = temp->next;
    }

    // DOUBLY CIRCULAR

    void AddinDCircularLast(int num)
    {
        NodeLL *newnode = new NodeLL(num);
        if (head == NULL)
        {
            head = newnode;
            tail = head;
            cout << "Inserted " << num << " at the last after making a new node [ " << num << " | * ]" << endl;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
            cout << "Inserted " << num << " at the last after making a new node [ " << num << " | * ]" << endl;
        }
    }

    void AddinDCircularFirst(int num)
    {
        NodeLL *newnode = new NodeLL(num);
        if (head == NULL)
        {
            head = newnode;
            tail = head;
            cout << "Inserted " << num << " at the start after making a new node [ " << num << " | * ]" << endl;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = head;
            cout << "Inserted " << num << " at the start after making a new node [ " << num << " | * ]" << endl;
        }
    }

    void AddafterDCircularNode(int value, int num)
    {
        NodeLL *newnode = new NodeLL(num);
        NodeLL *temp = head;
        while (temp->next != head)
        {
            if (temp->data == value)
            {
                newnode->next = temp->next;
                temp->next = newnode;
                cout << "Inserted " << num << " after making a new node [ " << num << " | * ] and inserting it after node of " << value << endl;
            }
            temp = temp->next;
        }
    }

    void DeleteDCircular(int value)
    {
        NodeLL *temp = head;
        NodeLL *prev;
        while (temp->next != head && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }
        cout << "\n\nWhen deleting uses previous pointer of the node to be deleted [ " << prev->data << " | * ]---> and points it to the node after the node being deleted [ " << temp->data << " | * ]" << endl;
        prev->next = temp->next;
        delete temp;
    }

    void UpdateDCircular(int oldValue, int newValue)
    {
        if (!head)
        {
            return;
        }

        NodeLL *current = head;
        do
        {
            if (current->data == oldValue)
            {
                current->data = newValue;
                cout << "\n\nWhen updating, we just change the values in the nodes of the linked list after travrsing to find which number is to be replaced" << endl;
                cout << "\nIn our case, we want to replace " << oldValue << " with " << newValue << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "\nNode with value " << oldValue << " not found. Cannot update." << endl;
    }

    void DisplayDCircular()
    {
        NodeLL *temp = head;
        int i = 1;

        while (temp->next != head)
        {
            clock_t start_time = clock();
            int delay_seconds = 1.5;
            while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
                ;

            cout << "-->|" << temp->data << "|*|<--";
            i++;
            temp = temp->next;
        }
        clock_t start_time = clock();
        int delay_seconds = 1.5;
        while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
            ;

        cout << ">|" << temp->data << "|*|<--";
        i++;
        temp = temp->next;
    }
};

void mainLL()
{
    LinkedLists obj1;
    LinkedLists obj2;
    LinkedLists obj3;
    LinkedLists obj4;

    int choice, choose;
    while (true)
    {
        cout << "\n";
        cout << "Which Linked List are you eager to learn today!!!" << endl;
        cout << "For Singly Linked List, Press 1." << endl;
        cout << "For Doubly Linked List, Press 2." << endl;
        cout << "For Circular Linked List, Press 3." << endl;
        cout << "For Doubly Circular Linked List, Press 4." << endl;
        cout << "Go Back, Press 5." << endl;
        cout << "Exit, Press 6." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        clearScreen();

        switch (choice)
        {
        case 1:
            cout << "\n";
            cout << "-------------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "Which Implementation do you wish to learn today?" << endl;
            cout << "For Insertion, Press 1." << endl;
            cout << "For Deletion, Press 2." << endl;
            cout << "For Update, Press 3." << endl;
            cout << "Enter your choice: ";
            cin >> choose;
            switch (choose)
            {
            case 1:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn Insertion in a Linkedlist!!!\n"
                     << endl;
                obj1.InsertSinglyFirst(5);
                obj1.InsertSinglyFirst(6);
                obj1.InsertSinglyLast(2);
                obj1.printSinglyList();
                cout << "\nYou can also add between any nodes your want as demonstrated: " << endl;
                obj1.AddafterSinglyNode(5, 3);
                obj1.printSinglyList();
                break;
            case 2:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn Deletion in a Linkedlist!!!\n"
                     << endl;
                obj1.InsertSinglyFirst(5);
                obj1.InsertSinglyFirst(6);
                obj1.InsertSinglyLast(2);
                cout << "\n Before: " << endl;
                obj1.printSinglyList();
                obj1.DeleteSinglyNode(5);
                obj1.printSinglyList();
                break;

            case 3:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn how to Update a node in a Linkedlist!!!\n"
                     << endl;
                obj1.InsertSinglyFirst(5);
                obj1.InsertSinglyFirst(6);
                obj1.InsertSinglyLast(2);
                obj1.printSinglyList();
                obj1.UpdateSinglyNode(7, 5);
                obj1.printSinglyList();
                break;

            default:
                break;
            }
            break;
        case 2:
            cout << "\n";
            cout << "-------------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "Which Implementation do you wish to learn today?" << endl;
            cout << "For Insertion, Press 1." << endl;
            cout << "For Deletion, Press 2." << endl;
            cout << "For Update, Press 3." << endl;
            cout << "Enter your choice: ";
            cin >> choose;
            switch (choose)
            {
            case 1:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn Insertion in a Doubly Linkedlist!!!\n"
                     << endl;
                obj2.InsertDoublyFirst(5);
                obj2.InsertDoublyFirst(6);
                obj2.InsertDoublyLast(2);
                obj2.printDoublyList();
                cout << "\nYou can also add between any nodes your want as demonstrated: " << endl;
                obj2.AddafterDoublyNode(5, 3);
                obj2.printDoublyList();
                break;

            case 2:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn Deletion in a Doubly Linkedlist!!!\n"
                     << endl;
                obj2.InsertDoublyFirst(5);
                obj2.InsertDoublyFirst(6);
                obj2.InsertDoublyLast(2);
                cout << "\n Before: " << endl;
                obj2.printDoublyList();
                obj2.DeleteDoublyNode(5);
                obj2.printDoublyList();
                break;

            case 3:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn how to Update a node in a Doubly Linkedlist!!!\n"
                     << endl;
                obj2.InsertDoublyFirst(5);
                obj2.InsertDoublyFirst(6);
                obj2.InsertDoublyLast(2);
                obj2.printDoublyList();
                obj2.UpdateDoublyNode(7, 5);
                obj2.printDoublyList();
                break;

            default:
                break;
            }
            break;
        case 3:
            cout << "\n";
            cout << "-------------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "Which Implementation do you wish to learn today?" << endl;
            cout << "For Insertion, Press 1." << endl;
            cout << "For Deletion, Press 2." << endl;
            cout << "For Update, Press 3." << endl;
            cout << "Enter your choice: ";
            cin >> choose;
            switch (choose)
            {
            case 1:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn Insertion in a Circular Linkedlist!!!\n"
                     << endl;
                obj3.AddinCircularFirst(5);
                obj3.AddinCircularFirst(6);
                obj3.AddinCircularLast(2);
                obj3.printCircularList();
                cout << "\nYou can also add between any nodes your want as demonstrated: " << endl;
                obj3.AddafterCircularNode(5, 3);
                obj3.printCircularList();
                break;

            case 2:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn Deletion in a Circular Linkedlist!!!\n"
                     << endl;
                obj3.AddinCircularFirst(5);
                obj3.AddinCircularFirst(6);
                obj3.AddinCircularLast(2);
                cout << "\n Before: " << endl;
                obj3.printCircularList();
                obj3.DeleteCircularNode(5);
                obj3.printCircularList();
                break;

            case 3:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn how to Update a node in a Circular Linkedlist!!!\n"
                     << endl;
                obj3.AddinCircularFirst(5);
                obj3.AddinCircularFirst(6);
                obj3.AddinCircularLast(2);
                obj3.printCircularList();
                obj3.UpdateCircularNode(7, 5);
                obj3.printCircularList();
                break;

            default:
                break;
            }
            break;
        case 4:
            cout << "\n";
            cout << "-------------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "Which Implementation do you wish to learn today?" << endl;
            cout << "For Insertion, Press 1." << endl;
            cout << "For Deletion, Press 2." << endl;
            cout << "For Update, Press 3." << endl;
            cout << "Enter your choice: ";
            cin >> choose;
            switch (choose)
            {
            case 1:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn Insertion in a Doubly Circular Linkedlist!!!\n"
                     << endl;
                obj4.AddinDCircularFirst(5);
                obj4.AddinDCircularFirst(6);
                obj4.AddinDCircularLast(2);
                obj4.DisplayDCircular();
                cout << "\nYou can also add between any nodes your want as demonstrated: " << endl;
                obj4.AddafterCircularNode(5, 3);
                obj4.DisplayDCircular();
                break;

            case 2:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn Deletion in a Doubly Circular Linkedlist!!!\n"
                     << endl;
                obj4.AddinDCircularFirst(5);
                obj4.AddinDCircularFirst(6);
                obj4.AddinCircularLast(2);
                cout << "\n Before: " << endl;
                obj4.DisplayDCircular();
                obj4.DeleteDCircular(5);
                obj4.DisplayDCircular();
                break;

            case 3:
                cout << "\n";
                cout << "-------------------------------------------------------------------------------------------\n"
                     << endl;
                cout << "Today we will learn how to Update a node in a Doubly Circular Linkedlist!!!\n"
                     << endl;
                obj4.AddinDCircularFirst(5);
                obj4.AddinDCircularFirst(6);
                obj4.AddinDCircularLast(2);
                obj4.DisplayDCircular();
                obj4.UpdateDCircular(5, 7);
                obj4.DisplayDCircular();
                break;

            default:
                break;
            }
            break;

        case 5:

            return;
        case 6:
            exit(0);
        default:
            cout << "\nInvalid choice." << endl;
            break;
        }
    }
}

// -------------------------- Linked List ends here ----------------------

// -------------------------- Stack And Queue Starts here -----------------------

class Node
{
public:
    int data;
    int priority;
    Node *next;
    Node *prev;

    Node() : data(0), priority(0), next(NULL), prev(NULL) {}

    Node(int d) : data(d), next(NULL), prev(NULL) {}

    Node(int d, int p) : data(d), priority(p), next(NULL), prev(NULL) {}
};

class Stack_And_Queue
{
    Node *top;
    Node *front;
    Node *bottom;
    Node *rear;
    int i, j, k;

public:
    Stack_And_Queue() : top(NULL), front(NULL), bottom(NULL), rear(NULL), i(0), j(0), k(0) {}

    bool isStackEmpty()
    {
        return top == NULL;
    }

    bool isQueueEmpty()
    {
        return front == NULL;
    }

    void push(int val)
    {

        if (isStackEmpty())
        {
            top = new Node(val);
            return;
        }
        else
        {
            Node *ptr = new Node(val);
            ptr->data = val;
            ptr->next = top;
            top = ptr;
            i++;
            k++;
        }
    }

    void pop()
    {
        if (!isStackEmpty())
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool searchStack(int target) const
    {
        Node *current = top;

        while (current != nullptr)
        {
            if (current->data == target)
            {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void enqueue(int val)
    {

        Node *New = new Node(val);

        if (isQueueEmpty())
        {
            front = rear = New;
        }
        else
        {
            rear->next = New;
            rear = New;
        }
    }

    Node *newNode(int data, int priority)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->priority = priority;
        temp->next = NULL;
        return temp;
    }

    void priorityEnqueue(int data, int priority)
    {
        Node *start = front;
        Node *temp = newNode(data, priority);
        if (front == nullptr || front->priority < priority)
        {
            temp->next = front;
            front = temp;
        }
        else
        {
            while (start->next != nullptr && start->next->priority > priority)
            {
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
        }
    }

    void circularEnqueue(int data)
    {
        Node *newNode = new Node(data);

        if (isQueueEmpty())
        {
            front = rear = newNode;
            rear->next = rear; // Point rear's next to itself for a single-node circular queue
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Make the list circular
        }
    }

    void doubleEndedEnqueue(int data, int op = 0)
    {

        if (op == 1)
        {
            Node *newNode = new Node(data);

            if (isQueueEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
        }
        else if (op == 2)
        {
            Node *newNode = new Node(data);

            if (isQueueEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                newNode->prev = rear;
                rear = newNode;
            }
        }
        else
        {
            Node *newNode = new Node(data);

            if (isQueueEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                newNode->prev = rear;
                rear = newNode;
            }
        }
    }

    int dequeue()
    {
        if (!isQueueEmpty())
        {
            int val = front->data;
            Node *temp = front;
            front = front->next;
            delete temp;
            return val;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
        return 0;
    }

    bool search(int target) const
    {
        Node *current = front;

        while (current != nullptr)
        {
            if (current->data == target)
            {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    int circularDequeue()
    {

        if (isQueueEmpty())
        {
            cout << "Queue is empty" << endl;
        }

        int val = front->data;
        Node *temp = front;

        if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
            rear->next = front; // Adjust the rear's next to maintain the circular structure
        }

        delete temp;
        return val;
    }

    void dequeueDoubleEndedQueue(int op)
    {

        if (op == 1)
        {
            if (isQueueEmpty())
            {
                cout << "Deque is empty" << endl;
            }
            else
            {
                Node *temp = front;
                front = front->next;

                if (front != nullptr)
                {
                    front->prev = nullptr;
                }
                else
                {
                    rear = nullptr; // If the deque becomes empty after deletion
                }

                delete temp;
            }
        }
        else if (op == 2)
        {
            if (isQueueEmpty())
            {
                cout << "Deque is empty. Cannot delete from the rear." << endl;
            }
            else
            {
                Node *temp = rear;
                rear = rear->prev;

                if (rear != nullptr)
                {
                    rear->next = nullptr;
                }
                else
                {
                    front = nullptr; // If the deque becomes empty after deletion
                }

                delete temp;
            }
        }
    }

    void displayInitialStack()
    {

        cout << "Let suppose initial stack is this: " << endl
             << endl;

        Node *temp = top;

        while (temp != NULL)
        {
            cout << "\t| " << temp->data << " |" << endl;
            temp = temp->next;
        }
        cout << "\t------";
        cout << endl
             << endl;
    }

    void displayInitialQueue()
    {

        cout << "Let suppose initial queue is this: " << endl
             << endl;

        Node *temp1 = front;

        cout << "[ ";

        while (temp1 != NULL)
        {
            cout << temp1->data << " | ";
            temp1 = temp1->next;
        }
        cout << " ]";
        cout << endl
             << endl;
    }

    void display(int choice, int choose)
    {
        // Display Stack

        if (choice == 1)
        {
            if (isStackEmpty())
            {
                cout << "Stack Is Empty" << endl;
                return;
            }

            Node *temp = top;

            cout << endl;

            if (choose == 1)
            {
                cout << "We are going to insert element no: " << temp->data << " in stack." << endl
                     << endl;
                temp = temp->next;
            }

            else if (choose == 2)
            {
                cout << endl
                     << "We are going to remove element no: " << temp->data << " from stack" << endl
                     << endl;
                pop();
            }
            else
            {
                cout << "Invalid Input" << endl;
            }

            temp = top;

            cout << "Final Stack will be like this:" << endl
                 << endl;

            while (temp != NULL)
            {
                cout << "\t| " << temp->data << " |" << endl;
                temp = temp->next;

                delay();
            }
            cout << "\t------";
            cout << endl
                 << endl;
        }

        // Display Queue

        else if (choice == 2)
        {
            if (isQueueEmpty())
            {
                cout << "Queue Is Empty" << endl;
                return;
            }

            Node *temp1 = front;
            Node *temp2 = rear;

            cout << endl;

            if (choose == 1)
            {
                cout << "We are going to insert element " << temp2->data << " in queue\t" << endl;
                temp2 = temp2->next;

                delay();
            }
            else if (choose == 2)
            {
                cout << endl
                     << "We are going to remove element " << temp1->data << " from queue\t" << endl;
                dequeue();

                delay();
            }
            else
            {
                cout << "Invalid Input" << endl;
            }

            temp1 = front;

            cout << "Final Queue will look like this:" << endl
                 << endl
                 << "[ ";

            while (temp1 != NULL)
            {
                cout << temp1->data << " | ";
                temp1 = temp1->next;

                delay();
            }
            cout << " ]";
            cout << endl
                 << endl;
        }
    }

    void displayPriorityQueue(int opt)
    {

        if (isQueueEmpty())
        {
            cout << "Queue Is Empty" << endl;
            return;
        }

        Node *temp1 = front;

        cout << endl;

        if (temp1 != NULL && opt == 1)
        {
            cout << "We are going to insert element with priority " << temp1->priority << " in priority queue which is " << temp1->data << endl;
            temp1 = temp1->next;

            delay();
        }
        else if (opt == 2)
        {
            cout << endl
                 << "We are going to remove element with priority " << temp1->priority << " from priority queue because it is the element with highest priority and it is " << temp1->data << endl;
            dequeue();

            delay();
        }
        else
        {
            cout << "Invalid Input" << endl;
        }

        cout << endl;

        temp1 = front;

        cout << "Final Queue will look like this:" << endl
             << endl
             << "[ ";

        while (temp1 != NULL)
        {
            cout << temp1->data << " | ";
            temp1 = temp1->next;

            delay();
        }
        cout << " ]";
        cout << endl
             << endl;
    }

    void displayInitialCircular()
    {

        cout << "Let suppose initial queue is this: " << endl
             << endl;

        Node *temp1 = front;

        cout << endl
             << "Final Circular Queue will look like this:" << endl
             << endl
             << "[ ";

        do
        {
            cout << temp1->data << " | ";
            temp1 = temp1->next;

            delay();

        } while (temp1 != front);

        cout << " ]";
        cout << endl
             << endl;
    }

    void displayCircularQueue(int opt)
    {

        if (isQueueEmpty())
        {
            cout << "Circular Queue is empty." << endl;
            return;
        }

        Node *temp1 = front;
        Node *temp2 = rear;

        if (opt == 1)
        {
            cout << "We are going to insert element " << temp2->data << " in circular queue" << endl;
            temp2 = temp2->next;
            delay();

            cout << endl;
        }
        else if (opt == 2)
        {
            cout << endl
                 << endl
                 << "We are going to remove element " << temp1->data << " in circular queue" << endl;
            circularDequeue();

            delay();
        }
        else
        {
            cout << "Invalid Input" << endl;
        }

        temp1 = front;

        cout << endl
             << "Final Circular Queue will look like this:" << endl
             << endl
             << "[ ";

        do
        {
            cout << temp1->data << " | ";
            temp1 = temp1->next;

            delay();

        } while (temp1 != front);

        cout << " ]";
        cout << endl
             << endl;
    }

    void displayDoubleEndedQueue(int opt, int op)
    {
        if (isQueueEmpty())
        {
            cout << "Deque Is Empty" << endl;
            return;
        }

        Node *temp = front;
        Node *temp1 = rear;

        cout << endl;

        if (opt == 1)
        {
            if (op == 1)
            {
                cout << "We are going to insert element " << temp->data << " at front of double ended queue." << endl;
                temp = temp->next;
                delay();
            }
            else if (op == 2)
            {
                cout << "We are going to insert element " << temp1->data << " at rear of double ended queue." << endl;
                temp1 = temp1->next;
                delay();
            }
        }

        else if (opt == 2)
        {
            if (op == 1)
            {
                cout << endl
                     << "We are going to remove element " << temp->data << " from queue because it is the first inserted element and we have to remove from front." << endl;
                dequeueDoubleEndedQueue(op);
                delay();
            }
            else if (op == 2)
            {
                cout << endl
                     << "We are going to remove element " << temp->data << " from queue because it is the last inserted element and we have to remove from rear." << endl;
                dequeueDoubleEndedQueue(op);
                delay();
            }
        }
        else
        {
            cout << "Invalid Input" << endl;
        }

        temp = front;

        cout << endl
             << "Final Double Ended Queue will look like this:" << endl
             << endl
             << "[ ";

        while (temp != NULL)
        {
            cout << temp->data << " | ";
            temp = temp->next;

            delay();
        }
        cout << " ]";
        cout << endl
             << endl;
    }

    void delay()
    {
        clock_t start_time = clock();
        int delay_seconds = 2;
        while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
            ;
    }
};

void mainStackAndQueue()
{
    Stack_And_Queue obj1, obj2, obj3, obj4, obj5;

    obj1.push(4);
    obj1.push(5);
    obj1.push(6);

    obj2.enqueue(4);
    obj2.enqueue(5);
    obj2.enqueue(6);

    obj3.priorityEnqueue(4, 2);
    obj3.priorityEnqueue(5, 1);
    obj3.priorityEnqueue(6, 3);

    obj4.circularEnqueue(4);
    obj4.circularEnqueue(5);
    obj4.circularEnqueue(6);

    obj5.doubleEndedEnqueue(4);
    obj5.doubleEndedEnqueue(5);
    obj5.doubleEndedEnqueue(6);

    int choice, choose;

    do
    {
        cout << "Q1) Enter what you want to learn." << endl
             << endl;
        cout << "Press 1 for Stack" << endl
             << "Press 2 for Queue" << endl
             << "Press 3 to go back" << endl
             << "Press 4 for Exit" << endl
             << "---------------------------------" << endl
             << endl
             << "Enter: ";
        cin >> choice;
        cout << endl
             << "---------------------------------" << endl;

        clearScreen();

        if (choice == 4)
        {
            exit(1);
        }
        else if (choice == 3)
        {
            break;
        }

        do
        {
            cout << endl
                 << "Q2) Which topic do you want to learn" << endl
                 << endl;
            cout << "Press 1 for Insertion" << endl
                 << "Press 2 for Deletion" << endl
                 << "Press 3 for Searching" << endl
                 << "Press 4 for Special Types Of Queue" << endl
                 << "Press 5 to go back" << endl
                 << "------------------------------------" << endl
                 << endl
                 << "Enter: ";
            cin >> choose;
            cout << endl
                 << "---------------------------------" << endl;
            clearScreen();

            if (choose == 5)
            {
                break;
            }

            // Stack

            if (choice == 1)
            {

                if (choose == 1)
                {
                    int num;
                    cout << endl
                         << "1) Adds a new element to the top of the stack." << endl
                         << "2) The newly added element becomes the new top." << endl
                         << "3) Follows the Last In, First Out (LIFO) principle." << endl
                         << endl;

                    obj1.delay();

                    obj1.displayInitialStack();

                    cout << "Write now top pointer is pointing at the element at the top of stack because it was the last inserted element" << endl
                         << endl;
                    obj1.delay();

                    cout << "Enter element you want to insert in Stack: ";
                    cin >> num;

                    obj1.push(num);
                    cout << endl;

                    obj1.display(choice, choose);

                    cout << endl
                         << "Since new element is added so now top pointer in incremented and now pointing to a newly added element." << endl
                         << endl;
                    obj1.delay();
                }
                else if (choose == 2)
                {

                    cout << endl
                         << "1) Removes the top element from the stack." << endl
                         << "2) The next element beneath it becomes the new top." << endl
                         << "3) Follows the LIFO principle, ensuring the most recently added element is the first to be removed." << endl
                         << endl;

                    obj1.delay();

                    obj1.displayInitialStack();

                    cout << "Write now top pointer is pointing at the element at the top of stack because it was the last inserted element" << endl
                         << endl;
                    obj1.delay();

                    obj1.display(choice, choose);

                    cout << endl
                         << "Since last element is deleted so now top pointer in decremented and now pointing to a second last element which is now become a last element." << endl
                         << endl;
                    obj1.delay();
                }
                else if (choose == 3)
                {

                    cout << endl
                         << "Searching in a stack involves sequentially examining elements from the top until finding the desired item or reaching the bottom. Due to its Last In, First Out (LIFO) nature, stacks are less efficient for searching compared to data structures that allow direct access to elements." << endl
                         << endl;

                    obj1.displayInitialStack();

                    int target;

                    cout << "Enter target: ";
                    cin >> target;
                    cout << endl;

                    if (obj1.searchStack(target))
                    {
                        cout << "Target Found In Stack" << endl;
                    }
                    else
                    {
                        cout << "Target Not Found In Stack" << endl;
                    }
                }
                else if (choose == 4)
                {
                    cout << endl
                         << "Sorry! This function is only avaliable for Queue" << endl
                         << endl;
                    break;
                }
            }

            // Queue

            else if (choice == 2)
            {
                if (choose == 1)
                {

                    int num;

                    cout << endl
                         << "1) Adds a new element to the rear of the queue." << endl
                         << "2) The newly added element becomes the last in the queue." << endl
                         << "3) Follows the First In, First Out (FIFO) principle." << endl
                         << endl;

                    obj2.delay();

                    obj2.displayInitialQueue();

                    cout << "At present, the front pointer is indicating the element at the front of the queue, and the rear pointer is pointing to the last-inserted element at the back of the queue." << endl
                         << endl;
                    obj2.delay();

                    cout << endl
                         << "Enter element you want to insert in Queue: ";
                    cin >> num;

                    obj2.enqueue(num);
                    cout << endl;

                    obj2.display(choice, choose);

                    cout << endl
                         << "With the addition of a new element, the rear pointer has been incremented, and it now points to the newly added element in the queue, while the front pointer remains at the front of the queue." << endl
                         << endl;
                    obj2.delay();
                }
                else if (choose == 2)
                {

                    cout << endl
                         << "1) Removes the front element from the queue." << endl
                         << "2) The next element in line becomes the new front." << endl
                         << "3) Follows the FIFO principle, ensuring the first element added is the first to be removed." << endl
                         << endl;

                    obj2.delay();

                    obj2.displayInitialQueue();

                    cout << "Currently, the rear pointer is directed towards the newly added element in the queue as it was the most recently inserted, while the front pointer remains at the front of the queue." << endl
                         << endl;
                    obj2.delay();

                    obj2.display(choice, choose);

                    cout << endl
                         << "After the deletion of the last element, both the front and rear pointers are decremented. The rear pointer now points to the new last element in the queue, while the front pointer points at the second element because it is the new front of the queue." << endl
                         << endl;
                    obj2.delay();
                }
                else if (choose == 3)
                {

                    cout << endl
                         << "In a queue, searching typically involves iterating through elements in a First In, First Out (FIFO) order, starting from the front, until the desired item is found or the end of the queue is reached. Queues are more suitable for applications where elements are processed in the order of their arrival rather than direct access, making them efficient for managing tasks such as task scheduling and breadth-first search algorithms." << endl
                         << endl;

                    obj2.displayInitialQueue();

                    int target;

                    cout << "Enter target: ";
                    cin >> target;
                    cout << endl;

                    if (obj2.search(target))
                    {
                        cout << "Target Found In Queue" << endl;
                    }
                    else
                    {
                        cout << "Target Not Found In Queue" << endl;
                    }
                }
                else if (choose == 4)
                {
                    int option, opt;

                    cout << endl
                         << "Q3) Enter which type do you want to learn." << endl
                         << endl;
                    cout << "Press 1 for Priority Queue" << endl
                         << "Press 2 for Circular Queue" << endl
                         << "Press 3 for Double Ended Queue" << endl
                         << "Press 4 to go back" << endl
                         << "---------------------------------------" << endl
                         << endl
                         << "Enter: ";
                    cin >> option;
                    cout << endl
                         << "---------------------------------" << endl;

                    if (option == 4)
                    {
                        break;
                    }

                    cout << endl
                         << "Q4) Enter what you want to learn." << endl
                         << endl;
                    cout << "Press 1 for Enqueue" << endl
                         << "Press 2 for Dequeue" << endl
                         << "Press 3 to go back" << endl
                         << "-----------------------------" << endl
                         << endl
                         << "Enter: ";
                    cin >> opt;
                    cout << endl
                         << "-----------------------------" << endl;

                    // Priority Queue

                    if (option == 1)
                    {

                        if (opt == 1)
                        {

                            cout << endl
                                 << "1) Adds a new element to the priority queue." << endl
                                 << "2) The position of the new element is determined by its priority." << endl
                                 << "3) Higher-priority elements are positioned closer to the front." << endl
                                 << endl;

                            int num, priority;

                            obj3.delay();

                            obj3.displayInitialQueue();

                            cout << "Currently, the front pointer is indicating the element with the highest priority in the priority queue, and the rear pointer is pointing to the last-inserted element with the highest priority." << endl
                                 << endl;
                            obj3.delay();

                            cout << "Enter element you want to insert in Queue: ";
                            cin >> num;
                            cout << "It's priority: ";
                            cin >> priority;
                            cout << endl;

                            obj3.priorityEnqueue(num, priority);

                            cout << endl;

                            obj3.displayPriorityQueue(opt);

                            cout << endl
                                 << "With the addition of a new element in the priority queue, the rear pointer has been incremented, and it now points to the newly added element with the highest priority, while the front pointer remains at the front of the priority queue." << endl
                                 << endl;
                            obj4.delay();
                        }
                        else if (opt == 2)
                        {
                            cout << endl
                                 << "1) Removes the highest-priority element from the priority queue." << endl
                                 << "2) The next highest-priority element in line becomes the new front." << endl
                                 << "3) Follows the priority-based order, ensuring elements are processed in order of their priority." << endl
                                 << endl;

                            obj3.delay();

                            obj3.displayInitialQueue();

                            cout << "Following the deletion of an element in the priority queue, the front pointer is now directed towards the element with the highest priority, while the rear pointer remains at the position of the last-inserted element with the highest priority." << endl
                                 << endl;
                            obj3.delay();

                            obj3.displayPriorityQueue(opt);

                            cout << endl
                                 << "After the deletion of the last element in the priority queue, both the front and rear pointers are decremented. The rear pointer now points to the new last element with the highest priority, while the front pointer indicates the second element with the next highest priority, as it is the new front of the priority queue." << endl
                                 << endl;
                            obj3.delay();
                        }
                        else if (opt == 3)
                        {
                            break;
                        }
                    }

                    // Circular Queue

                    else if (option == 2)
                    {
                        if (opt == 1)
                        {

                            cout << endl
                                 << "1) Adds a new element to the rear of the circular queue." << endl
                                 << "2) The newly added element becomes the last in the queue." << endl
                                 << "3) If the rear reaches the end of the queue, it wraps around to the front." << endl
                                 << endl;

                            int num;

                            obj4.delay();

                            obj4.displayInitialCircular();

                            cout << "Currently, the front pointer is indicating the element at the front of the circular queue, and the rear pointer is pointing to the last-inserted element at the back of the circular queue." << endl
                                 << endl;
                            obj4.delay();

                            cout << "Enter element you want to insert in Queue: ";
                            cin >> num;

                            obj4.circularEnqueue(num);
                            cout << endl;

                            obj4.displayCircularQueue(opt);

                            cout << endl
                                 << "With the addition of a new element in the circular queue, the rear pointer has been incremented, and it now points to the newly added element at the back of the circular queue, while the front pointer remains at the front of the circular queue." << endl
                                 << endl;
                            obj4.delay();
                        }

                        else if (opt == 2)
                        {

                            cout << endl
                                 << "1) Removes the front element from the circular queue." << endl
                                 << "2) The next element in line becomes the new front." << endl
                                 << "3) If the front reaches the end of the queue, it wraps around to the beginning." << endl
                                 << "4) Ensures efficient use of space and allows continuous cycling of elements." << endl
                                 << endl;

                            obj4.delay();

                            obj4.displayInitialCircular();

                            cout << "Following the deletion of an element in the circular queue, the front pointer is now directed towards the next element in the circular queue, while the rear pointer remains at the position of the last-inserted element at the back of the circular queue." << endl
                                 << endl;
                            obj4.delay();

                            obj4.displayCircularQueue(opt);

                            cout << endl
                                 << "After the deletion of the last element in the circular queue, both the front and rear pointers are decremented. The rear pointer now points to the new last element at the back of the circular queue, while the front pointer indicates the second element as the new front of the circular queue." << endl
                                 << endl;
                            obj4.delay();
                        }
                        else if (opt == 3)
                        {
                            break;
                        }
                    }

                    // Double Ended Queue

                    else if (option == 3)
                    {
                        cout << endl
                             << "A double-ended queue, or deque, allows insertion and deletion from both the front and rear, providing flexibility in managing elements from both ends." << endl
                             << endl;

                        int op;

                        if (opt == 1)
                        {

                            cout << endl
                                 << "Q5) Where do you want to insert in Deque" << endl
                                 << endl
                                 << "Press 1 to insert at front" << endl
                                 << "Press 2 to insert at rear" << endl
                                 << "-----------------------------" << endl
                                 << endl
                                 << "Enter: ";
                            cin >> op;
                            cout << endl
                                 << "-----------------------------" << endl;

                            int num;

                            if (op == 1)
                            {

                                cout << endl
                                     << "1) Adds a new element to the front of the double-ended queue." << endl
                                     << "2) The newly added element becomes the new front." << endl
                                     << "3) Can be used for efficiently adding elements at the beginning." << endl
                                     << endl;

                                obj5.delay();

                                obj5.displayInitialQueue();

                                cout << "With the insertion of a new element at the front of the double-ended queue, the front pointer is now indicating the newly added element at the front, while the rear pointer points to the last-inserted element at the back of the double-ended queue." << endl
                                     << endl;
                                obj5.delay();

                                cout << "Enter the number you want to insert at front: ";
                                cin >> num;

                                obj5.doubleEndedEnqueue(num, op);
                                cout << endl;

                                obj5.displayDoubleEndedQueue(opt, op);

                                cout << endl
                                     << "With the addition of a new element at the front of the double-ended queue, the front pointer has been updated to indicate the newly added element at the front, while the rear pointer still points to the last-inserted element at the back of the double-ended queue." << endl
                                     << endl;
                                obj5.delay();
                            }
                            else if (op == 2)
                            {

                                cout << endl
                                     << "1) Adds a new element to the rear of the double-ended queue." << endl
                                     << "2) The newly added element becomes the last in the queue." << endl
                                     << "3) Allows for efficient addition of elements to the end." << endl
                                     << endl;

                                obj5.delay();

                                obj5.displayInitialQueue();

                                cout << "With the addition of a new element at the rear of the double-ended queue, the rear pointer has been updated to indicate the newly added element at the back, while the front pointer remains at the front of the double-ended queue." << endl
                                     << endl;
                                obj5.delay();

                                cout << "Enter the number you want to insert at rear: ";
                                cin >> num;

                                obj5.doubleEndedEnqueue(num, op);
                                cout << endl;

                                obj5.displayDoubleEndedQueue(opt, op);

                                cout << endl
                                     << "With the addition of a new element at the rear of the double-ended queue, the rear pointer has been incremented, and it now points to the newly added element at the back of the double-ended queue, while the front pointer remains at the front of the double-ended queue." << endl
                                     << endl;
                                obj5.delay();
                            }
                        }
                        else if (opt == 2)
                        {

                            cout << endl
                                 << "Q5) Where do you want to delete in Deque" << endl
                                 << endl
                                 << "Press 1 to delete at front" << endl
                                 << "Press 2 to delete at rear" << endl
                                 << "-----------------------------" << endl
                                 << endl
                                 << "Enter: ";
                            cin >> op;
                            cout << endl
                                 << "-----------------------------" << endl;

                            if (op == 1)
                            {

                                cout << endl
                                     << "1) Removes the front element from the double-ended queue." << endl
                                     << "2) The next element in line becomes the new front." << endl
                                     << "3) Enables removal of elements from the front efficiently." << endl
                                     << endl;

                                obj5.delay();

                                obj5.displayInitialQueue();

                                cout << "Following the deletion of an element from the front of the double-ended queue, the front pointer moves to the next element, while the rear pointer stays at the position of the last-inserted element at the back." << endl
                                     << endl;
                                obj5.delay();

                                obj5.displayDoubleEndedQueue(opt, op);

                                cout << endl
                                     << "Following the removal of the last element in the double-ended queue, both the front and rear pointers are decremented. The rear pointer now points to the new last element at the back, while the front pointer indicates the second element as the new front." << endl
                                     << endl;
                                obj5.delay();
                            }
                            else if (op == 2)
                            {

                                cout << endl
                                     << "1) Removes the rear element from the double-ended queue." << endl
                                     << "2) The next element in line becomes the new rear." << endl
                                     << "3) Allows for efficient removal of elements from the end." << endl
                                     << endl;

                                obj5.delay();

                                obj5.displayInitialQueue();

                                cout << "Following the deletion of an element from the rear of the double-ended queue, the rear pointer is decremented, and it now points to the new last-inserted element at the back, while the front pointer remains at the front of the double-ended queue." << endl
                                     << endl;
                                obj5.delay();

                                obj5.displayDoubleEndedQueue(opt, op);

                                cout << endl
                                     << "After removing the last element from the rear of the double-ended queue, both front and rear pointers are decremented. The rear pointer now points to the new last element, and the front pointer indicates the second element as the new front." << endl
                                     << endl;
                                obj5.delay();
                            }
                        }
                        else if (opt == 3)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        } while (choose != 5);
    } while (choice != 4);
}

// -------------------------- Stack And Queue ends here -----------------------

// ---------------------- HashTable starts here -------------------------

class HashNode
{
public:
    int key;
    int value;
    HashNode *next;

    HashNode(int v) : value(v), next(nullptr)
    {
        // Calculate key from the value
        key = value % 10; // Update this calculation based on your requirements
    }
};

class LinkedList
{
public:
    HashNode *head;

    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        HashNode *current = head;
        while (current != nullptr)
        {
            HashNode *next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(int value)
    {
        HashNode *newNode = new HashNode(value);
        newNode->next = head;
        head = newNode;
    }

    void remove(int key)
    {
        HashNode *current = head;
        HashNode *prev = nullptr;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    // Node to be deleted is the head of the list
                    head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }
    }

    void display()
    {
        HashNode *current = head;
        while (current != nullptr)
        {
            clock_t start_time = clock();
            int delay_seconds = 0.75;
            while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
                ;
            cout << "(" << current->value << ")";
            current = current->next;
        }
    }
};

class Hash
{
private:
    int capacity;
    LinkedList *table;

public:
    Hash(int cap) : capacity(cap)
    {
        table = new LinkedList[capacity];
    }

    ~Hash()
    {
        delete[] table;
    }

    int divisionHash(int key)
    {
        return key % capacity;
    }

    int midSquareHash(int key)
    {
        int square = key * key;
        int digits = 0;
        int temp = square;
        while (temp > 0)
        {
            digits++;
            temp /= 10;
        }
        int middleDigits = (digits / 2) - 1;
        int result = square;
        for (int i = 0; i < middleDigits; ++i)
        {
            result /= 10;
        }
        return result % capacity;
    }

    void separateChaining(int value)
    {
        clock_t start_time = clock();
        int delay_seconds = 1;
        while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
            ;
        cout << "Inserting value : " << value << endl;
        int key = value % capacity;
        int index = divisionHash(key);
        cout << "Inserting " << value << " at index " << index << endl;
        table[index].insert(value);
    }

    // Linear probing
    void linearProbing(int value)
    {
        int key = value % capacity;
        int index = divisionHash(key);
        cout << "Inserting value: " << value << endl;
        while (table[index].head != nullptr)
        {
            // Handle collision using linear probing
            cout << "Collision at index " << index << " ,using linear probing.\n";
            index = (index + 1) % capacity;
        }
        cout << "Inserting " << value << " at index " << index << endl;
        table[index].insert(value);
    }

    // Quadratic probing
    void quadraticProbing(int value)
    {
        int key = value % capacity;
        int index = divisionHash(key);
        int i = 1;
        cout << "Inserting :" << value << endl;
        while (table[index].head != nullptr)
        {
            // Handle collision using quadratic probing
            cout << "Collision at index " << index << " using quadratic probing.\n";
            index = (index + i * i) % capacity;
            i++;
        }
        cout << "Inserting " << value << " at index " << index << endl;
        table[index].insert(value);
    }

    // Double hashing
    void doubleHashing(int value)
    {
        int key = value % capacity;
        int index1 = divisionHash(key);
        int index2 = midSquareHash(value);
        int index = index1;
        cout << "Inserting value: " << value << endl;
        clock_t start_time = clock();
        int delay_seconds = 1;
        while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
            ;
        int i = 1;
        while (table[index].head != nullptr)
        {
            // Handle collision using double hashing
            cout << "Collision at index " << index << " using double hashing.\n";
            index = (index1 + i * index2) % capacity;
            i++;
        }
        cout << "Inserting " << value << " at index " << index << endl;
        table[index].insert(value);
    }

    void singledoubleHashing(int value)
    {
        cout << "Inserting value : " << value << endl;
        int key = value % capacity;
        cout << "The key is : " << key << endl;
        int index1 = divisionHash(key);
        cout << "index1 after division hash function is : " << index1 << endl;
        int index2 = midSquareHash(value);
        cout << "index2 after mid square hash function is : " << index2 << endl;
        int index = index1;
        cout << "Inserting value: " << value << endl;
        clock_t start_time = clock();
        int delay_seconds = 1;
        while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
            ;
        int i = 1;
        while (table[index].head != nullptr)
        {
            // Handle collision using double hashing
            cout << "Collision at index " << index << " using double hashing.\n";
            cout << "The calculation is : " << index1 << " + " << i << " * " << index2 << " % " << capacity << endl;
            index = (index1 + i * index2) % capacity;
            i++;
        }
        cout << "Inserting " << value << " at index " << index << endl;
        table[index].insert(value);
    }

    // Display the hash table
    void display()
    {
        for (int i = 0; i < capacity; ++i)
        {
            cout << "[" << i << "]: ";
            clock_t start_time = clock();
            int delay_seconds = 1;
            while ((clock() - start_time) / CLOCKS_PER_SEC < delay_seconds)
                ;
            table[i].display();
            cout << endl;
        }
    }
};

void mainHash()
{

    while (true)
    {
        Hash hashtable(10);
        int capacity = 10;
        int choice;
        cout << "\n";
        cout << "-------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Which type of Hashing are you eager to learn today!!!" << endl;
        cout << "For Seperate Chaining, Press 1." << endl;
        cout << "For Linear Probing, Press 2." << endl;
        cout << "For Quadratic Probing, Press 3." << endl;
        cout << "For Double Hashing, Press 4." << endl;
        cout << "Go Back, Press 5." << endl;
        cout << "To Exit, Press 6." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        clearScreen();

        switch (choice)
        {
        case 1:
            cout << "\n";
            cout << "-------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "Seperate chaining is performed when a collision occurs during the implmentation of a hash function" << endl;
            cout << "In seperate chaining we make an array of capacity n and strore heads of different linked lists at each index" << endl;
            cout << "While there is no collison in the keys of the hash table the values are inserted at the heads of the seperate linked lists" << endl;
            cout << "However when a COLLISION occurs the value is added to the tail of the linked list at the colliding Index" << endl;
            cout << "The index is calculated using the hash function which in this case is value % capacity of hash table" << endl;
            cout << "The demonstration is shown below: \n\n"
                 << endl;
            hashtable.separateChaining(12);
            hashtable.separateChaining(22);
            hashtable.separateChaining(34);
            hashtable.separateChaining(42);
            hashtable.separateChaining(10);
            hashtable.separateChaining(33);
            hashtable.separateChaining(59);
            hashtable.separateChaining(28);
            cout << "\n\n\n";
            hashtable.display();
            break;
        case 2:
            cout << "\n";
            cout << "-------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "Linear Probing is performed when a collision occurs during the implmentation of a hash function" << endl;
            cout << "In Linear Probing we make an array of capacity n and strore the value at the first available index calculated by key" << endl;
            cout << "While there is no collison in the keys of the hash table the values are inserted at the calculated key index of the array" << endl;
            cout << "However when a COLLISION occurs the value is added to the next available index in the array after the key index" << endl;
            cout << "BE CAREFUL THE NUMBERS OF INSERTION SHOULD NOT SURPASS ARRAY SIZE IN THIS CASE" << endl;
            cout << "The demonstration is shown below: \n\n"
                 << endl;
            hashtable.linearProbing(12);
            hashtable.linearProbing(22);
            hashtable.linearProbing(34);
            hashtable.linearProbing(42);
            hashtable.linearProbing(10);
            hashtable.linearProbing(1);
            hashtable.linearProbing(5);
            hashtable.linearProbing(57);
            hashtable.linearProbing(17);
            hashtable.linearProbing(29);
            hashtable.display();
            break;
        case 3:
            cout << "\n";
            cout << "-------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "Quadratic Probing is performed when a collision occurs during the implmentation of a hash function" << endl;
            cout << "In Quadratic Probing we make an array of capacity n and strore the value at the first available index calculated by key" << endl;
            cout << "While there is no collison in the keys of the hash table the values are inserted at the calculated key index of the array" << endl;
            cout << "However when a COLLISION occurs the value is added to the next available index calculated by the Hash function in the array after the key index\n"
                 << endl;
            cout << "The hash function for the quadratic Probing is: index = (index + i * i) % capacity" << endl;
            cout << "BE CAREFUL THE NUMBERS OF INSERTION SHOULD NOT SURPASS ARRAY SIZE IN THIS CASE" << endl;
            cout << "The demonstration is shown below: \n\n"
                 << endl;
            hashtable.quadraticProbing(12);
            hashtable.quadraticProbing(22);
            hashtable.quadraticProbing(34);
            hashtable.quadraticProbing(42);
            hashtable.quadraticProbing(10);
            hashtable.quadraticProbing(1);
            hashtable.quadraticProbing(5);
            hashtable.quadraticProbing(57);
            hashtable.quadraticProbing(17);
            hashtable.quadraticProbing(29);
            hashtable.display();
            cout << "\n\n\nThe downside of using quadratic probing is that if value is not found at certain indexes the function can go into an infinite loop in trying to find an available index " << endl;
            break;
        case 4:
            cout << "\n";
            cout << "-------------------------------------------------------------------------------------\n"
                 << endl;
            cout << "Double Hashing is performed when a collision occurs during the implmentation of a hash function" << endl;
            cout << "In Double Hashing we make an array of capacity n and strore the value at the first available index calculated by key" << endl;
            cout << "While there is no collison in the keys of the hash table the values are inserted at the calculated key index of the array" << endl;
            cout << "However when a COLLISION occurs, The next index is calculated by the formula: index = (index1 + i * index2) % capacity" << endl;
            cout << "index1 is calculated by division method which is: index = value % capacity" << endl;
            cout << "index2 is calculatd by mid-square method which is : squaring the key, taking the middle digits, and using them as the hash value." << endl;
            cout << "BE CAREFUL THE NUMBERS OF INSERTION SHOULD NOT SURPASS ARRAY SIZE IN THIS CASE" << endl;
            cout << "The demonstration is shown below: \n\n"
                 << endl;
            hashtable.doubleHashing(12);
            hashtable.doubleHashing(13);
            hashtable.doubleHashing(32);
            hashtable.doubleHashing(45);
            hashtable.doubleHashing(10);
            hashtable.doubleHashing(1);
            hashtable.doubleHashing(66);
            hashtable.singledoubleHashing(55);
            hashtable.doubleHashing(16);
            hashtable.doubleHashing(29);
            hashtable.display();
            break;

        case 5:
            return;
        case 6:
            exit(0);
        default:
            cout << "\nInvalid choice." << endl;
            break;
        }
    }
}

// ---------------------- HashTable ends here -------------------------

// -------------------------Binary Tree Starts Here -------------------------

class AVLNode
{
public:
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;
};

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int num)
    {
        if (root == NULL)
        {
            root = new TreeNode(num);
            cout << "Value Inserted as root node!" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (num == temp->value)
                {
                    cout << "Value Already exist,"
                         << "Insert another value!" << endl;
                    return;
                }
                else if ((num < temp->value) && (temp->left == NULL))
                {
                    temp->left = new TreeNode(num);
                    cout << "Reached to endpoint of tree where there is no Value at the left of " << temp->value << "\n\t so the value Inserted to the left of " << temp->value << endl;
                    break;
                }
                else if (num < temp->value)
                {
                    cout << "On Comparing " << num << " with " << temp->value << "\n\t" << num << " is less than " << temp->value << " so move towards left subtree" << endl;
                    temp = temp->left;
                }
                else if ((num > temp->value) && (temp->right == NULL))
                {
                    temp->right = new TreeNode(num);
                    cout << "Reached to endpoint of tree where there is no Value at the right of " << temp->value << "\n\t so the value Inserted to the Right of " << temp->value << endl;
                    break;
                }
                else
                {
                    cout << "On Comparing " << num << " with " << temp->value << "\n\t" << num << " is greater than " << temp->value << " so move towards right subtree" << endl;
                    temp = temp->right;
                }
                this_thread::sleep_for(chrono::seconds(2));
            }
        }
    }
    void insert(TreeNode *r, int num)
    {
        if (root == NULL)
        {
            root = new TreeNode(num);
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (num == temp->value)
                {
                    cout << "Value Already exist,"
                         << "Insert another value!" << endl;
                    return;
                }
                else if ((num < temp->value) && (temp->left == NULL))
                {
                    temp->left = new TreeNode(num);
                    break;
                }
                else if (num < temp->value)
                {
                    temp = temp->left;
                }
                else if ((num > temp->value) && (temp->right == NULL))
                {
                    temp->right = new TreeNode(num);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    void print2D(TreeNode *r, int space)
    {
        if (r == NULL)
            return;
        space += SPACE;
        print2D(r->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
            cout << " ";
        cout << r->value << "\n";
        print2D(r->left, space);
    }
    TreeNode *Search(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (v == temp->value)
                {
                    cout << "We have reached to the value you have searched" << endl;
                    return temp;
                }
                else if (v < temp->value)
                {
                    cout << "On Comparing " << v << " with " << temp->value << "\n\t" << v << " is less than " << temp->value << " so move towards left subtree" << endl;
                    temp = temp->left;
                }
                else
                {
                    cout << "On Comparing " << v << " with " << temp->value << "\n\t" << v << " is greater than " << temp->value << " so move towards right subtree" << endl;
                    temp = temp->right;
                }
                this_thread::sleep_for(chrono::seconds(3));
            }
            return NULL;
        }
    }
    TreeNode *ssearch(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (v == temp->value)
                {
                    return temp;
                }
                else if (v < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    cout << "On Comparing " << v << " with " << temp->value << "\n\t" << v << " is greater than " << temp->value << " so move towards right subtree" << endl;
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }
    int height(TreeNode *r)
    {
        if (r == NULL)
            return -1;
        else
        {
            int lheight = height(r->left);
            int rheight = height(r->right);
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *root, int k)
    {
        if (root == NULL)
            return root;
        if (root->value > k)
        {
            cout << "On Comparing " << k << " with " << root->value << "\n\t" << k << " is less than " << root->value << " so move towards left subtree" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            root->left = deleteNode(root->left, k);
            return root;
        }
        else if (root->value < k)
        {
            cout << "On Comparing " << k << " with " << root->value << "\n\t" << k << " is greater than " << root->value << " so move towards right subtree" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            root->right = deleteNode(root->right, k);
            return root;
        }
        cout << "Found the value we want to delete" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        if (root->left == NULL)
        {
            cout << "The node has no left subtree so attach the right subtree of it with its parent Node \n\t and delete the node" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            cout << "The node has no right subtree so attach the left subtree of it with its parent Node \n\t and delete the node" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else
        {

            cout << "The node has both, the right subtree and the left subtree\nFind the successor of Node:" << k << "\n\tNOTE: If you want to learn how to find successor,select it in main menu" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            TreeNode *succParent = root;
            // Find successor
            TreeNode *succ = root->right;
            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            }
            /* Delete successor.  Since successor is always left child of its parent.we can safely make successor's right right child as left of its parent. If there is no succ, then assign succ->right to succParent->right*/
            if (succParent != root)
            {
                cout << "if the node has any right subtree so attach it with its parent's node'" << k << endl;
                this_thread::sleep_for(chrono::seconds(3));
                succParent->left = succ->right;
            }
            else
            {

                succParent->right = succ->right;
            }

            cout << "Replace the value of successor with node's value and then delete successor node which was " << succ->value << endl;
            this_thread::sleep_for(chrono::seconds(7));
            root->value = succ->value;

            // Delete Successor and return root
            delete succ;
            return root;
        }
    }
    void insertinfo()
    {

        cout << "INSERTION METHOD TECHNIQUE IN BST: " << endl;
        cout << endl
             << " - Start at the root of the tree." << endl
             << " - Compare the value to be inserted with the current node's value." << endl
             << " - If the value is less than the current node's value, move to the left subtree;" << endl
             << "   if greater, move to the right subtree." << endl
             << " - Repeat this process until you find an empty spot (a null link), where the new node can be inserted." << endl
             << endl;
    }
    void searchinfo()
    {

        cout << "SEARCH METHOD TECHNIQUE IN BST: " << endl;
        cout << endl
             << "1.Start from the Root:" << endl
             << "\t -Begin the search from the root of the BST." << endl
             << "2.Compare with Root:" << endl
             << "\t - If the root is null or its value is equal to the target value, the search is successful, and the current node is the result." << endl
             << "\t - If the target value is less than the root's value, move to the left subtree." << endl
             << "\t - If the target value is greater than the root's value, move to the right subtree." << endl
             << "3.Recursion:" << endl
             << "\t - Apply the search algorithm recursively to the chosen subtree (left or right) until a match is found or a leaf node is reached." << endl
             << "4.Result:" << endl
             << "\t - If a node with the target value is found, return a pointer to that node." << endl
             << "\t - If the target value is not present in the BST, return null to indicate that the value is not in the tree." << endl
             << endl;
    }
    void deleteinfo()
    {

        cout << "DELETION METHOD TECHNIQUE IN BST: " << endl;
        cout << endl
             << "1.Start from the Root:" << endl
             << "\t -Begin the search from the root of the BST." << endl
             << "2.Compare with Root:" << endl
             << "\t - If the root is null or its value is equal to the target value, the search is successful, and the node to be deleted is found." << endl
             << "\t - If the target value is less than the root's value, move to the left subtree." << endl
             << "\t - If the target value is greater than the root's value, move to the right subtree." << endl
             << "3.Recursion:" << endl
             << "\t - Apply the search algorithm recursively to the chosen subtree (left or right) until a match is found or a leaf node is reached." << endl
             << "4.Result:" << endl
             << "\t - If a node with the target value is found, replace it with left most child of its subtree." << endl
             << "\t - If the target value is not present in the BST, return null to indicate that the value is not in the tree." << endl
             << endl;
    }
    void inorder(TreeNode *root, int level)
    {
        if (root != NULL)
        {
            // Recursively traverse the left subtree
            if (root->left != NULL)
            {
                cout << "   Going to the left subtree..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                inorder(root->left, level + 1);
            }
            // Print the current node's data and level between traversing left and right subtrees
            cout << "Level " << level << ": Visiting Node " << root->value << endl;
            this_thread::sleep_for(chrono::seconds(2));

            // Recursively traverse the right subtree
            if (root->right != NULL)
            {
                cout << "   Going to the right subtree..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                inorder(root->right, level + 1);
            }
        }
    }

    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->value << "  ";
        inorder(root->right);
    }

    void preorder(TreeNode *root, int level)
    {
        if (root != NULL)
        {
            // Print the current node's data and level

            cout << "Level " << level << ": Visiting Node " << root->value << endl;
            this_thread::sleep_for(chrono::seconds(2));
            // Recursively traverse the left subtree
            if (root->left != NULL)
            {
                cout << "   Going to the left subtree..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                preorder(root->left, level + 1);
            }
            // Recursively traverse the right subtree
            if (root->right != NULL)
            {
                cout << "   Going to the right subtree..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                preorder(root->right, level + 1);
            }
        }
    }
    void preorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->value << "  ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(TreeNode *root, int level)
    {
        if (root != NULL)
        {
            // Recursively traverse the left subtree
            if (root->left != NULL)
            {
                cout << "   Going to the left subtree..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                postorder(root->left, level + 1);
            }
            // Recursively traverse the right subtree
            if (root->right != NULL)
            {
                cout << "   Going to the right subtree..." << endl;
                this_thread::sleep_for(chrono::seconds(2));
                postorder(root->right, level + 1);
            }
            // Print the current node's data and level after traversing its subtrees
            cout << "Level " << level << ": Visiting Node " << root->value << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
    }

    void postorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->value << "  ";
    }
    void printBinaryTreeVertical(TreeNode *root, int space = 0, int level = 0)
    {
        const int spacing = 4;

        if (root == nullptr)
        {
            return;
        }

        space += spacing;
        if (root->right != NULL)
            printBinaryTreeVertical(root->right, space, level + 1);

        cout << setw(level * spacing) << ' ' << root->value << endl;
        if (root->left != NULL)
            printBinaryTreeVertical(root->left, space, level + 1);
    }

    void drawTree(TreeNode *root)
    {
        cout << "Tree : " << endl;
        printBinaryTreeVertical(root);
    }
    TreeNode *findPredecessor(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->value == key)
        {
            if (root->left != NULL)
            {
                TreeNode *tmp = root->left;
                cout << "Process:" << endl;
                cout << "Left Child of " << key << " is " << tmp->value << endl;
                cout << "Traversing through the subtree to findout Rightmost Element of Leftchild" << endl;
                while (tmp->right != NULL)
                {
                    tmp = tmp->right;
                    cout << tmp->value << "  ";
                }
                cout << endl
                     << endl
                     << "Predecessor of Node " << key << " is : " << tmp->value << endl
                     << endl
                     << endl;
                return tmp;
            }
            else
            {

                cout << "Node is not present at the left of it so unable to find Predecessor of it" << endl;

                return NULL;
            }
        }
        if (root->value > key)
        {
            findPredecessor(root->left, key);
        }
        else
        {
            findPredecessor(root->right, key);
        }
        return NULL;
    }
    TreeNode *findSuccessor(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->value == key)
        {
            if (root->right != NULL)
            {
                TreeNode *tmp = root->right;
                cout << "Right Child of " << key << " is " << tmp->value << endl;
                cout << "Traversing through the subtree to findout leftmost Element of Rightchild" << endl;
                while (tmp->left)
                {

                    tmp = tmp->left;
                    cout << tmp->value << "  ";
                }
                cout << endl
                     << endl
                     << "Successor of Node " << key << " is : " << tmp->value << endl
                     << endl
                     << endl;
                return tmp;
            }
            else
            {
                cout << "Node is not present at the right of it so unable to find Successor of it" << endl;
                return NULL;
            }
        }
        if (root->value > key)
        {
            findSuccessor(root->left, key);
        }
        else
        {
            findSuccessor(root->right, key);
        }
        return NULL;
    }
};

class avlTree
{
public:
    AVLNode *root;
    avlTree()
    {
        root = NULL;
    }

    int height(AVLNode *temp)
    {
        int h = 0;
        if (temp != NULL)
        {
            int l_height = height(temp->left);
            int r_height = height(temp->right);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        return h;
    }
    AVLNode *minValueNode(AVLNode *node)
    {
        AVLNode *current = node;
        while (current->left != NULL)
            current = current->left;

        return current;
    }
    int diff(AVLNode *temp)
    {
        cout << endl
             << "Let " << temp->data << " be the root and calculate the height of left and right subtree:" << endl;
        int l_height = height(temp->left);
        cout << "1.Height of left subtree: " << l_height << endl;
        int r_height = height(temp->right);
        cout << "2.Height of right subtree: " << r_height << endl;
        int b_factor = l_height - r_height;
        cout << "3.Balance Factor of root->" << temp->data << " is " << b_factor << endl
             << endl;

        return b_factor;
    }

    AVLNode *rr_rotation(AVLNode *parent)
    {
        if (parent->right != NULL && parent->right->right != NULL)
            cout << "Detected Right-Right Case starting from AVLNode->" << parent->data << " -> " << parent->right->data << " -> " << parent->right->right->data << endl;
        else if (parent->right != NULL && parent->right->right == NULL)
            cout << "Right-Right Rotate starting from Node->" << parent->data << " -> " << parent->right->data << endl;
        else if (parent->right == NULL && parent->right->right == NULL)
            cout << "Right-Right Rotate starting from AVLNode->" << parent->data << endl;

        AVLNode *temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;

        return temp;
    }

    AVLNode *ll_rotation(AVLNode *parent)
    {
        if (parent->left != NULL && parent->left->left != NULL)
            cout << "Detected a Left-Left case starting from Node->" << parent->data << " -> " << parent->left->data << " -> " << parent->left->left->data << endl;
        else if (parent->left != NULL && parent->left->left == NULL)
            cout << "Left-Left Rotate starting from Node->" << parent->data << " -> " << parent->left->data << endl;
        if (parent->left == NULL && parent->left->left == NULL)
            cout << "Left-Left Rotate starting from Node->" << parent->data << endl;
        AVLNode *temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        return temp;
    }

    AVLNode *lr_rotation(AVLNode *parent)
    {
        cout << "Detected a Left-Right case starting from Node->" << parent->data << " -> " << parent->left->data << " -> " << parent->left->right->data << endl;
        AVLNode *temp;
        temp = parent->left;
        parent->left = rr_rotation(temp);
        return ll_rotation(parent);
    }

    AVLNode *rl_rotation(AVLNode *parent)
    {
        cout << "Detected a Right-Left case starting from Node->" << parent->data << " -> " << parent->right->data << " -> " << parent->right->left->data << endl;
        AVLNode *temp;
        temp = parent->right;
        parent->right = ll_rotation(temp);
        return rr_rotation(parent);
    }

    AVLNode *balance(AVLNode *temp)
    {
        int bal_factor = diff(temp);

        if (bal_factor > 1)
        {
            if (diff(temp->left) > 0)
            {
                temp = ll_rotation(temp);
            }
            else
            {
                temp = lr_rotation(temp);
            }
        }
        else if (bal_factor < -1)
        {
            if (diff(temp->right) > 0)
            {
                temp = rl_rotation(temp);
            }
            else
            {
                temp = rr_rotation(temp);
            }
        }

        return temp;
    }

    void display(AVLNode *ptr, int level)
    {
        if (ptr != NULL)
        {
            display(ptr->right, level + 1);
            cout << endl;
            if (ptr == root)
            {
                cout << "Root -> ";
            }
            for (int i = 0; i < level && ptr != root; i++)
            {
                cout << "        ";
            }
            cout << ptr->data;
            display(ptr->left, level + 1);
        }
    }

    AVLNode *balanceTree(AVLNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        AVLNode *newRoot = new AVLNode();
        newRoot->data = root->data;
        newRoot->left = balanceTree(root->left);
        newRoot->right = balanceTree(root->right);

        newRoot = balance(newRoot);
        return newRoot;
    }

    void printBinaryTreeVertical(AVLNode *root, int space = 0, int level = 0)
    {
        const int spacing = 4;

        if (root == nullptr)
        {
            return;
        }

        space += spacing;
        if (root->right != NULL)
            printBinaryTreeVertical(root->right, space, level + 1);

        cout << setw(level * spacing) << ' ' << root->data << endl;
        if (root->left != NULL)
            printBinaryTreeVertical(root->left, space, level + 1);
    }

    void drawTree(AVLNode *root)
    {
        cout << "Tree : " << endl;
        printBinaryTreeVertical(root);
    }

    AVLNode *insert(AVLNode *root, int value)
    {
        if (root == NULL)
        {
            root = new AVLNode;
            root->data = value;
            root->left = NULL;
            root->right = NULL;

            return root;
        }

        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        else
        {
            cout << "\n\tValue already exists!" << endl;
        }

        return root;
    }
    void inorder(AVLNode *root, int level)
    {
        if (root != NULL)
        {
            // Recursively traverse the left subtree
            if (root->left != NULL)
            {
                cout << "   Going to the left subtree..." << endl;
                inorder(root->left, level + 1);
            }
            // Print the current node's data and level between traversing left and right subtrees
            cout << "Level " << level << ": Visiting Node " << root->data << endl;

            // Recursively traverse the right subtree
            if (root->right != NULL)
            {
                cout << "   Going to the right subtree..." << endl;
                inorder(root->right, level + 1);
            }
        }
    }

    void inorder(AVLNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << "  ";
        inorder(root->right);
    }

    void preorder(AVLNode *root, int level)
    {
        if (root != NULL)
        {
            // Print the current node's data and level
            cout << "Level " << level << ": Visiting Node " << root->data << endl;

            // Recursively traverse the left subtree
            if (root->left != NULL)
            {
                cout << "   Going to the left subtree..." << endl;
                preorder(root->left, level + 1);
            }
            // Recursively traverse the right subtree
            if (root->right != NULL)
            {
                cout << "   Going to the right subtree..." << endl;
                preorder(root->right, level + 1);
            }
        }
    }
    void preorder(AVLNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << "  ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(AVLNode *root, int level)
    {
        if (root != NULL)
        {
            // Recursively traverse the left subtree
            if (root->left != NULL)
            {
                cout << "   Going to the left subtree..." << endl;
                postorder(root->left, level + 1);
            }
            // Recursively traverse the right subtree
            if (root->right != NULL)
            {
                cout << "   Going to the right subtree..." << endl;
                postorder(root->right, level + 1);
            }
            // Print the current node's data and level after traversing its subtrees
            cout << "Level " << level << ": Visiting Node " << root->data << endl;
        }
    }
    AVLNode *deleteNode(AVLNode *root, int key)
    {
        // STEP 1: PERFORM STANDARD BST DELETE
        if (root == NULL)
        {
            cout << "Step 1: The tree is empty. Nothing to delete." << endl;
            return root;
        }

        // If the key to be deleted is smaller
        // than the root's key, then it lies
        // in the left subtree
        if (key < root->data)
        {
            cout << "Step 1: Going to the left subtree." << endl;
            root->left = deleteNode(root->left, key);
        }

        // If the key to be deleted is greater
        // than the root's key, then it lies
        // in the right subtree
        else if (key > root->data)
        {
            cout << "Step 1: Going to the right subtree." << endl;
            root->right = deleteNode(root->right, key);
        }

        // if key is the same as root's key, then
        // this is the node to be deleted
        else
        {
            // Node with only one child or no child
            if ((root->left == NULL) || (root->right == NULL))
            {
                AVLNode *temp = root->left ? root->left : root->right;

                // No child case
                if (temp == NULL)
                {
                    cout << "Step 1: Node with no child." << endl;
                    temp = root;
                    root = NULL;
                }
                else // One child case
                {
                    cout << "Step 1: Node with one child." << endl;
                    *root = *temp; // Copy the contents of the non-empty child
                    free(temp);
                }
            }
            else
            {
                // Node with two children: Get the inorder successor (smallest in the right subtree)
                AVLNode *temp = minValueNode(root->right);

                // Copy the inorder successor's data to this node
                root->data = temp->data;

                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->data);
            }
        }

        // If the tree had only one node
        // then return
        if (root == NULL)
        {
            cout << "Step 1: The only node in the tree is deleted." << endl;
            return root;
        }

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        root->height = 1 + max(height(root->left), height(root->right));

        // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
        int balance = diff(root);

        // If this node becomes unbalanced,
        // then there are 4 cases

        // Left Left Case
        if (balance > 1 && diff(root->left) >= 0)
        {
            cout << "Step 2: Update height and balance factor. Node is balanced." << endl;
            return rr_rotation(root);
        }

        // Left Right Case
        if (balance > 1 && diff(root->left) < 0)
        {
            root->left = ll_rotation(root->left);
            cout << "Step 2: Left-Right Case. Performing left rotation on left child." << endl;
            return rr_rotation(root);
        }

        // Right Right Case
        if (balance < -1 && diff(root->right) <= 0)
        {
            cout << "Step 2: Update height and balance factor. Node is balanced." << endl;
            return ll_rotation(root);
        }

        // Right Left Case
        if (balance < -1 && diff(root->right) > 0)
        {
            root->right = rr_rotation(root->right);
            cout << "Step 2: Right-Left Case. Performing right rotation on right child." << endl;
            return ll_rotation(root);
        }

        cout << "Step 2: Update height and balance factor. Node is balanced." << endl;
        return root;
    }

    void postorder(AVLNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "  ";
    }

    bool checkInput(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
            {
                return false;
            }
        }
        return true;
    }
    bool deleteTree(AVLNode *root)
    {
        if (root == NULL)
        {
            return true; // Base case: an empty subtree is considered deleted
        }

        // Recursively delete the left and right subtrees
        bool leftDeleted = deleteTree(root->left);
        bool rightDeleted = deleteTree(root->right);

        // Delete the current node
        delete root;

        // Return true only if both left and right subtrees are deleted successfully
        return leftDeleted && rightDeleted;
    }
    int validate(string str)
    {
        if (checkInput(str))
        {
            return 100;
        }
        else
        {
            return -1;
        }
    }
    void deleteinfo()
    {
        cout << "1.Search for the Node to Delete:" << endl;
        cout << "\tStart from the root and traverse the tree to find the node with the specified key." << endl;
        cout << "2.Standard BST Delete:" << endl;
        cout << "\tIf the node has no children or one child, delete it directly." << endl;
        cout << "\tIf the node has two children, find its in-order successor (smallest node in the right subtree)," << endl;
        cout << "\tcopy its data to the current node, and then recursively delete the in-order successor." << endl;
        cout << "3.Update Heights:" << endl;
        cout << "\tAfter deletion, traverse back up from the deleted node towards the root," << endl;
        cout << "\tupdating the height of each ancestor node based on the maximum height of its left and right subtrees, plus 1." << endl;
        cout << "4.Check Balance Factor:" << endl;
        cout << "\tFor each ancestor node, calculate the balance factor (difference in height between left and right subtrees)." << endl;
        cout << "5.Balancing Cases:" << endl;
        cout << "  Four possible cases for imbalance:" << endl;
        cout << "\t -Left-Left (LL): Requires a right rotation." << endl;
        cout << "\t -Right-Right (RR): Requires a left rotation." << endl;
        cout << "\t -Left-Right (LR): Requires a left rotation on the left child followed by a right rotation." << endl;
        cout << "\t -Right-Left (RL): Requires a right rotation on the right child followed by a left rotation." << endl;
        cout << "6.Repeat Until Balanced:" << endl;
        cout << "\tContinue this process, recursively checking and fixing imbalances up to the root of the tree." << endl;
    }
    void rotationsinfo()
    {
        cout << "In AVL tree rotations, we encounter four cases:\n\n";
        cout << "Abnormality occurs when 1 < Balance_Factor < -1\n\n";
        // Left-Left Case
        cout << "1. Left-Left Case:\n";
        cout << "   - Occurs when a new node is inserted into the left subtree of the left child.\n";
        cout << "   - Requires a right rotation to balance the tree.\n\n";

        // Right-Right Case
        cout << "2. Right-Right Case:\n";
        cout << "   - Occurs when a new node is inserted into the right subtree of the right child.\n";
        cout << "   - Requires a left rotation to balance the tree.\n\n";

        // Left-Right Case
        cout << "3. Left-Right Case:\n";
        cout << "   - Occurs when a new node is inserted into the right subtree of the left child.\n";
        cout << "   - Requires a left rotation followed by a right rotation to balance the tree.\n\n";

        // Right-Left Case
        cout << "4. Right-Left Case:\n";
        cout << "   - Occurs when a new node is inserted into the left subtree of the right child.\n";
        cout << "   - Requires a right rotation followed by a left rotation to balance the tree.\n\n";
    }
    void insertioninfo()
    {
        cout << "INSERTION METHOD TECHNIQUE: " << endl;
        cout << "1.Normal BST insertion: " << endl
             << "\t - Start at the root of the tree." << endl
             << "\t - Compare the value to be inserted with the current node's value." << endl
             << "\t - If the value is less than the current node's value, move to the left subtree;" << endl
             << "\t   if greater, move to the right subtree." << endl
             << "\t - Repeat this process until you find an empty spot (a null link), where the new node can be inserted." << endl
             << "2.Update Heights:" << endl
             << "\t - After inserting the new node, update the height of each ancestor node along the path to the root." << endl
             << "\t - The height of a node is the maximum height of its left and right subtrees, plus 1." << endl
             << "3.Balance the Tree: " << endl
             << "\t - Check the balance factor of each ancestor node along the path to the root." << endl
             << "\t - If the balance factor of any node becomes greater than 1 or less than -1, the tree is unbalanced." << endl
             << "\t - Perform rotations to restore balance: " << endl
             << "\t\t * Left-Left Rotation: " << endl
             << "\t\t   Occurs when a new node is inserted into the left subtree of the left child. Requires a right rotation." << endl
             << "\t\t * Right-Right Rotation: Occurs when a new node is inserted into the right subtree of the right child." << endl
             << "\t\t   Requires a left rotation." << endl
             << "\t\t * Left-Right Rotation: Occurs when a new node is inserted into the right subtree of the left child. " << endl
             << "\t\t   Requires a left rotation followed by a right rotation." << endl
             << "\t\t * Right-Left Rotation: Occurs when a new node is inserted into the left subtree of the right child." << endl
             << "\t\t   Requires a right rotation followed by a left rotation." << endl
             << endl;
    }
};

void learnAVL()
{
    int choice, item, c, i = 0;
    string str;
    avlTree avl;

    while (1)
    {

        cout << "\n---------------------" << endl;
        cout << "AVL Tree Tutor" << endl;
        cout << "\n---------------------" << endl;
        cout << "Select a topic you want to learn" << endl;
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.Display Tree" << endl;
        cout << "3.Delete Element" << endl;
        cout << "4.Balance Tree" << endl;
        cout << "5.PreOrder traversal" << endl;
        cout << "6.InOrder traversal" << endl;
        cout << "7.PostOrder traversal" << endl;
        cout << "8.Go Back" << endl;
        cout << "0.Exit" << endl;
        cout << "\nEnter your Choice: ";
        cin >> choice;
        avl.root = avl.insert(avl.root, 30);
        avl.root = avl.insert(avl.root, 20);
        avl.root = avl.insert(avl.root, 40);
        avl.root = avl.insert(avl.root, 10);
        avl.root = avl.insert(avl.root, 25);
        avl.root = avl.insert(avl.root, 35);
        avl.root = avl.insert(avl.root, 50);
        avl.root = avl.balanceTree(avl.root);
        clearScreen();
        switch (choice)
        {
        case 1:
            avl.insertioninfo();
            this_thread::sleep_for(chrono::seconds(7));
            cout << endl
                 << "The Tree is already populated using random values" << endl
                 << "Tree: " << endl;
            avl.printBinaryTreeVertical(avl.root);
            cout << "Enter the value you want to insert (NOTE: Don't repeat the values): ";
            cin >> str;
            c = avl.validate(str);
            if (c == 100)
            {
                cout << "INSERTION: " << endl;
                avl.root = avl.insert(avl.root, stoi(str));
                avl.drawTree(avl.root);
                this_thread::sleep_for(chrono::seconds(3));
                avl.rotationsinfo();
                this_thread::sleep_for(chrono::seconds(5));
                cout << "BALANCING: " << endl
                     << "Before Balancing : " << endl;
                avl.drawTree(avl.root);
                this_thread::sleep_for(chrono::seconds(2));
                cout << endl
                     << "Process of Balancing the Tree: " << endl;
                avl.root = avl.balanceTree(avl.root);
                this_thread::sleep_for(chrono::seconds(2));
                cout << "After Balancing : ";
                avl.drawTree(avl.root);
                this_thread::sleep_for(chrono::seconds(3));
            }
            else
            {
                cout << "\n\t\tInvalid Input!" << endl;
            }

            break;
        case 2:
            if (avl.root == NULL)
            {
                cout << "Tree is Empty" << endl;
                break;
            }
            avl.drawTree(avl.root);
            break;
        case 3:
            avl.deleteinfo();
            this_thread::sleep_for(chrono::seconds(7));
            cout << endl;
            cout << endl
                 << "The Tree is already populated using random values" << endl
                 << "Tree: " << endl;
            avl.drawTree(avl.root);
            cout << "Enter the value you want to delete: ";
            cin >> str;
            c = avl.validate(str);
            if (c == 100)
            {
                cout << "DELETION: " << endl;
                AVLNode *temp = avl.deleteNode(avl.root, stoi(str));
                this_thread::sleep_for(chrono::seconds(3));
                cout << "Tree after DELETION: " << endl;
                avl.drawTree(avl.root);
                this_thread::sleep_for(chrono::seconds(3));
            }
            else
            {
                cout << "\n\t\tInvalid Input!" << endl;
            }
            break;

        case 4:
            //        	if (avl.root == NULL) {
            //                cout << "Tree is Empty" << endl;
            //                break;
            //            }
            avl.deleteTree(avl.root);
            avl.root = NULL;
            avl.rotationsinfo();
            this_thread::sleep_for(chrono::seconds(7));
            cout << endl
                 << "The Tree is already populated using random values" << endl
                 << "Tree: " << endl;
            avl.root = avl.insert(avl.root, 30);
            avl.root = avl.insert(avl.root, 15);
            avl.root = avl.insert(avl.root, 40);
            avl.root = avl.insert(avl.root, 10);
            avl.root = avl.insert(avl.root, 20);
            avl.root = avl.insert(avl.root, 35);
            avl.root = avl.insert(avl.root, 50);
            avl.root = avl.insert(avl.root, 18);
            avl.root = avl.insert(avl.root, 60);
            avl.root = avl.insert(avl.root, 9);
            avl.root = avl.insert(avl.root, 8);
            avl.root = avl.insert(avl.root, 19);
            avl.root = avl.insert(avl.root, 38);
            avl.root = avl.insert(avl.root, 36);
            avl.root = avl.insert(avl.root, 70);
            cout << "Before Balancing : " << endl;
            avl.drawTree(avl.root);
            this_thread::sleep_for(chrono::seconds(2));
            cout << endl
                 << "Process of Balancing the Tree: " << endl;
            avl.root = avl.balanceTree(avl.root);
            this_thread::sleep_for(chrono::seconds(7));
            cout << "After Balancing : " << endl;
            avl.drawTree(avl.root);
            this_thread::sleep_for(chrono::seconds(3));
            avl.deleteTree(avl.root);
            avl.root = NULL;
            break;

        case 5:
            //        	if (avl.root == NULL) {
            //                cout << "Tree is Empty" << endl;
            //                break;
            //            }
            cout << "PREORDER TRAVERSAL METHOD: " << endl;
            cout << "1.Visit the Root:" << endl
                 << "\tStart at the root of the tree and visit the root node." << endl;
            cout << "2.Traverse Left Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the left subtree." << endl;
            cout << "3.Traverse Right Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the right subtree." << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << endl
                 << "The Tree is already populated using random values" << endl;
            avl.drawTree(avl.root);
            cout << "Process of Preorder Traversal : " << endl;
            avl.preorder(avl.root, 0);
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl
                 << "Preorder Traversal : ";
            avl.preorder(avl.root);
            this_thread::sleep_for(chrono::seconds(3));
            avl.deleteTree(avl.root);
            avl.root = NULL;
            cout << endl;
            break;
        case 6:
            //        	if (avl.root == NULL) {
            //                cout << "Tree is Empty" << endl;
            //                break;
            //            }
            cout << "INORDER TRAVERSAL METHOD: " << endl;

            cout << "1.Traverse Left Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the left subtree." << endl;
            cout << "2.Visit the Root:" << endl
                 << "\tStart at the root of the tree and visit the root node." << endl;
            cout << "3.Traverse Right Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the right subtree." << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << endl
                 << "The Tree is already populated using random values" << endl;

            avl.drawTree(avl.root);
            cout << "Process of Inorder Traversal : " << endl;
            avl.inorder(avl.root, 0);
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl
                 << "Inorder Traversal : ";
            avl.inorder(avl.root);
            this_thread::sleep_for(chrono::seconds(3));
            avl.deleteTree(avl.root);
            avl.root = NULL;
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl;
            break;
        case 7:
            //        	if (avl.root == NULL) {
            //                cout << "Tree is Empty" << endl;
            //                break;
            //            }
            cout << "POSTORDER TRAVERSAL METHOD: " << endl;
            cout << "1.Traverse Left Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the left subtree." << endl;
            cout << "2.Traverse Right Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the right subtree." << endl;
            cout << "3.Visit the Root:" << endl
                 << "\tStart at the root of the tree and visit the root node." << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << endl
                 << "The Tree is already populated using random values" << endl;
            avl.drawTree(avl.root);
            cout << "Process of Postorder Traversal : " << endl;
            avl.postorder(avl.root, 0);
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl
                 << "Postorder Traversal : ";
            avl.postorder(avl.root);
            this_thread::sleep_for(chrono::seconds(3));
            avl.deleteTree(avl.root);
            avl.root = NULL;
            cout << endl;
            break;
        case 8:
            return;
        case 0:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
}

void learnBST()
{
    BST obj;
    TreeNode *temp;
    while (1)
    {
        cout << endl
             << "-----------------------------------" << endl;
        cout << "------------BST TUTOR-------------- " << endl;
        cout << "-----------------------------------" << endl;
        cout << "Which concept do you want to learn? " << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. PreOrder Traversal" << endl;
        cout << "5. InOrder Traversal" << endl;
        cout << "6. PostOrder Traversal" << endl;
        cout << "7. Finding Minimum value of Tree" << endl;
        cout << "8. Finding Maximum value of Tree" << endl;
        cout << "9. Finding Height Tree" << endl;
        cout << "10. Finding Successor of Node" << endl;
        cout << "11. Finding Predecessor of Node" << endl;
        cout << "12. Go Back" << endl;
        cout << "0. Exit Program" << endl;
        cout << "Option: ";
        int option;
        cin >> option;
        obj.insert(obj.root, 30);
        obj.insert(obj.root, 20);
        obj.insert(obj.root, 40);
        obj.insert(obj.root, 10);
        obj.insert(obj.root, 25);
        obj.insert(obj.root, 35);
        obj.insert(obj.root, 50);
        clearScreen();
        if (option == 0)
        {
            exit(1);
        }
        else if (option == 12)
        {
            break;
        }
        else if (option == 1)
        {
            obj.insertinfo();
            this_thread::sleep_for(chrono::seconds(7));
            cout << endl
                 << "The Tree is already populated using random values" << endl
                 << "Tree: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "Enter the value you want to insert (NOTE: Don't repeat the values): ";
            int num;
            cin >> num;
            cout << "INSERTION: " << endl;
            obj.insert(num);
            cout << "Tree: " << endl;
            obj.print2D(obj.root, 5);

            this_thread::sleep_for(chrono::seconds(5));
        }
        else if (option == 2)
        {
            obj.searchinfo();
            this_thread::sleep_for(chrono::seconds(10));
            cout << endl
                 << "Tree: " << endl;
            obj.print2D(obj.root, 5);
            cout << "Enter the value you want to search in BST: ";
            int val;
            cin >> val;
            temp = obj.Search(val);
            if (temp != NULL)
            {
                cout << "Value is present in the tree" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
            else
            {
                cout << "Value NOT found" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }
        else if (option == 3)
        {
            obj.deleteinfo();
            this_thread::sleep_for(chrono::seconds(2));
            cout << endl;
            cout << endl
                 << "The Tree is already populated using random values" << endl
                 << "Tree: " << endl;
            obj.drawTree(obj.root);
            cout << "Enter the value you want to delete: ";
            int num;
            cin >> num;
            cout << "Implementing DELETION: " << endl;
            temp = obj.deleteNode(obj.root, num);
            cout << "Tree after DELETION: " << endl;
            obj.drawTree(obj.root);
        }
        else if (option == 4)
        {
            cout << "PREORDER TRAVERSAL METHOD: " << endl;
            cout << "1.Visit the Root:" << endl
                 << "\tStart at the root of the tree and visit the root node." << endl;
            cout << "2.Traverse Left Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the left subtree." << endl;
            cout << "3.Traverse Right Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the right subtree." << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << endl
                 << "The Tree is already populated using random values" << endl;
            obj.drawTree(obj.root);
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Process of Preorder Traversal : " << endl;
            obj.preorder(obj.root, 0);
            cout << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "Preorder Traversal : ";
            obj.preorder(obj.root);
            cout << endl;
        }
        else if (option == 5)
        {
            //        	if (obj.root == NULL) {
            //                cout << "Tree is Empty" << endl;
            //                break;
            //            }
            cout << "INORDER TRAVERSAL METHOD: " << endl;

            cout << "1.Traverse Left Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the left subtree." << endl;
            cout << "2.Visit the Root:" << endl
                 << "\tStart at the root of the tree and visit the root node." << endl;
            cout << "3.Traverse Right Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the right subtree." << endl;
            cout << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << "The Tree is already populated using random values" << endl;

            obj.drawTree(obj.root);
            this_thread::sleep_for(chrono::seconds(3));
            cout << "Process of Inorder Traversal : " << endl;

            obj.inorder(obj.root, 0);
            cout << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "Inorder Traversal : ";
            obj.inorder(obj.root);
            cout << endl;
        }
        else if (option == 6)
        {
            cout << "POSTORDER TRAVERSAL METHOD: " << endl;
            cout << "1.Traverse Left Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the left subtree." << endl;
            cout << "2.Traverse Right Subtree:" << endl
                 << "\tRecursively perform a preorder traversal on the right subtree." << endl;
            cout << "3.Visit the Root:" << endl
                 << "\tStart at the root of the tree and visit the root node." << endl;
            cout << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << "The Tree is already populated using random values" << endl;
            obj.drawTree(obj.root);
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Process of Postorder Traversal : " << endl;
            obj.postorder(obj.root, 0);
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl

                 << "Postorder Traversal : ";
            obj.postorder(obj.root);
            cout << endl;
        }
        else if (option == 7)
        {
            obj.drawTree(obj.root);
            cout << "To find the Minimum value of the BST:\n\tWe have to traverse through BST to find the leftmost element of tree." << endl;
            this_thread::sleep_for(chrono::seconds(3));
            temp = obj.root;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            cout << "Minimum Value of the Tree: " << temp->value << endl
                 << endl;
            delete temp;
        }
        else if (option == 8)
        {
            obj.drawTree(obj.root);
            cout << "To find the Maximum value of the BST:\n\tWe have to traverse through BST to find the rightmost element of tree." << endl;
            temp = obj.root;
            this_thread::sleep_for(chrono::seconds(3));
            while (temp->left != NULL)
            {
                temp = temp->right;
            }
            cout << "Maximum Value of the Tree: " << temp->value << endl
                 << endl;
        }
        else if (option == 9)
        {
            cout << "HEIGHT OF BST: " << endl
                 << "The height of a Binary Tree is defined as the maximum depth of any leaf node from the root node.\nThat is, it is the length of the longest path from the root node to any leaf node." << endl;
            cout << "Since the height of the tree is defined as the largest path from the root to a leaf,\n We can recursively compute the height of the left and right sub-trees." << endl;
            cout << "We can apply the definition of the height on the sub-trees now." << endl;
            cout << "We observe that it is the maximum between the left and the right sub-trees and then add one." << endl
                 << "Since the height of the tree is the maximum height of the sub-tree + 1,\n we keep doing this, until the sub-tree becomes NULL" << endl
                 << endl;
            this_thread::sleep_for(chrono::seconds(7));
            obj.drawTree(obj.root);
            cout << "For which Node you want to find the height: " << endl;
            int num;
            cin >> num;
            temp = obj.ssearch(num);
            if (temp != NULL)
            {
                cout << "Height of Tree considering the root Element to be " << num << ": " << obj.height(temp) << endl
                     << endl;
                cout << "Height of Tree: " << obj.height(obj.root) << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
            else
            {
                cout << "Value not found" << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }
        else if (option == 11)
        {
            obj.drawTree(obj.root);
            cout << "PREDECESSOR: " << endl;
            cout << "If its left subtree is not null\nThen predecessor will be the right most child of left subtree or left child itself." << endl
                 << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "For which Node you want to find the Predecessor: ";
            int num;
            cin >> num;
            temp = obj.ssearch(num);
            if (temp != NULL)
            {
                obj.findPredecessor(temp, num);
                this_thread::sleep_for(chrono::seconds(2));
            }
            else
            {
                cout << "Value not found" << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }
        else if (option == 10)
        {
            obj.drawTree(obj.root);
            cout << "SUCCESSOR: " << endl;
            cout << "If the right subtree of Node is not NULL,\nThe successor will be the left most child of right subtree or right child itself." << endl
                 << endl;
            this_thread::sleep_for(chrono::seconds(3));
            cout << "For which Node you want to find the Successor: ";
            int num;
            cin >> num;
            temp = obj.Search(num);
            if (temp != NULL)
            {
                obj.findSuccessor(temp, num);
                cout << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
            else
            {
                cout << "Value not found" << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }
        else
        {
            cout << "Wrong Choice" << endl;
        }
    }
    return;
}

void learnTree()
{
    int choice;
    while (1)
    {
        cout << "Which type of tree you want to learn?" << endl
             << "1.Binary Search Tree" << endl
             << "2.AVL Tree" << endl
             << "3.Go Back" << endl
             << "0.Exit" << endl
             << "Option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            learnBST();
            break;
        case 2:
            learnAVL();
            break;
        case 3:
            return;
        case 0:
            exit(0);
        default:
            cout << "Invalid Input!" << endl;
        }
        clearScreen();
    }
}

// -------------------------Binary Tree Ends Here -------------------------

// ------------------------- Graphs starts here ----------------------

class GraphNode
{
public:
    int data;
    GraphNode *next;
    GraphNode(int value) : data(value) { next = NULL; }
};

class Graph
{
public:
    int vertices, edges = 0;
    GraphNode **adjacencyList;
    int **adjacencyMatrix;
    Graph(int v)
    {
        vertices = v;
        adjacencyList = new GraphNode *[vertices];
        for (int i = 0; i < v; i++)
        {
            adjacencyList[i] = nullptr;
        }
        adjacencyMatrix = new int *[vertices];
        for (int i = 0; i < v; i++)
        {
            adjacencyMatrix[i] = new int[vertices];
            for (int j = 0; j < v; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }
    // for start
    void addEdge(int from, int to, int weight = 0)
    {
        // Add edge at 'from'
        GraphNode *newnodeatfrom = new GraphNode(to);
        newnodeatfrom->next = adjacencyList[from];
        adjacencyList[from] = newnodeatfrom;
        // Maintain Matrix for Dijkstra's Algorithm
        adjacencyMatrix[from][to] = weight;
        adjacencyMatrix[to][from] = weight;
        // Add edge at 'to'
        GraphNode *newnodeatto = new GraphNode(from);
        newnodeatto->next = adjacencyList[to];
        adjacencyList[to] = newnodeatto;
        edges++;
    }
    // for user
    void addedge(int from, int to, int weight = 0)
    {
        // Add edge at 'from'
        GraphNode *newnodeatfrom = new GraphNode(to);
        newnodeatfrom->next = adjacencyList[from];
        adjacencyList[from] = newnodeatfrom;
        cout << "1.Make a new GraphNode with the value " << to << " and insert it in the adjacencyList[" << from << "]" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        // Add edge at 'to'
        GraphNode *newnodeatto = new GraphNode(from);
        newnodeatto->next = adjacencyList[to];
        adjacencyList[to] = newnodeatto;
        cout << "  Make a new GraphNode with the value " << from << " and insert it in the adjacencyList[" << to << "]" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        // Maintain Matrix for Dijkstra's Algorithm
        adjacencyMatrix[from][to] = weight;
        adjacencyMatrix[to][from] = weight;
        cout << "2.Update the weight in adjacencyMatrix by inserting the " << weight << "\n  adjacencyMatrix[" << from << "][" << to << "] & adjacencyMatrix[" << to << "][" << from << "] = " << weight << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "3.Increment Edges Count" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        edges++;
    }

    void printgraph()
    {
        cout << "Adjacency List: " << endl;
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex " << i << " is connected to : ";
            GraphNode *temp = adjacencyList[i];
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        printmatrix();
    }
    bool searchEdge(int from, int to)
    {
        cout << "Beginning at the source vertex (" << from << ")." << endl;
        cout << "Traversing the adjacency list of the source vertex." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        GraphNode *temp = adjacencyList[from];
        int i = 1;
        while (temp != nullptr)
        {
            cout << i << " - " << temp->data << endl;
            cout << "Checking if " << temp->data << " matches the destination vertex (" << to << ")." << endl;
            if (temp->data == to)
            {
                cout << "Edge found between " << from << " and " << to << endl;
                this_thread::sleep_for(chrono::seconds(2));
                return true;
            }
            temp = temp->next;
            this_thread::sleep_for(chrono::seconds(2));
        }
        cout << "Edge not found between " << from << " and " << to << endl;
        this_thread::sleep_for(chrono::seconds(2));
        this_thread::sleep_for(chrono::seconds(5));
        return false;
    }

    void removeEdge(int from, int to)
    {
        cout << "Traversing the Adjacency list of the source vertex " << from << " to search for the destination vertex (" << to << ")" << endl;
        // Remove edge at 'from'
        GraphNode *fromtemp = adjacencyList[from];
        GraphNode *fromprev = NULL;
        int i = 1;
        bool flag = false;
        while (fromtemp != NULL)
        {
            cout << i << " - " << fromtemp->data << endl;
            cout << "Checking if " << fromtemp->data << " matches the destination vertex (" << to << ")." << endl;
            if (fromtemp->data == to)
            {
                cout << "Edge found between " << from << " and " << to << endl
                     << "Deleting the edge in the list of " << from << endl;
                flag = true;
                if (fromprev == NULL)
                {
                    adjacencyList[from] = fromtemp->next;
                }
                else
                {
                    fromprev->next = fromtemp->next;
                }
                delete fromtemp;
                break;
            }
            this_thread::sleep_for(chrono::seconds(2));
            fromprev = fromtemp;
            fromtemp = fromtemp->next;
        }
        this_thread::sleep_for(chrono::seconds(2));

        // Remove edge at 'to'
        i = 1;
        GraphNode *totemp = adjacencyList[to];
        GraphNode *toprev = NULL;
        cout << "1.Traversing the Adjacency list of the source vertex " << to << " to search for the destination vertex (" << from << ")" << endl;
        while (totemp != NULL)
        {
            cout << i << " - " << totemp->data << endl;
            cout << "Checking if " << totemp->data << " matches the destination vertex (<<" << from << ")." << endl;

            if (totemp->data == from)
            {
                cout << "Edge found between " << to << " and " << from << endl
                     << "Deleting the edge in the list of " << to << endl;
                if (toprev == NULL)
                {
                    adjacencyList[to] = totemp->next;
                }
                else
                {
                    toprev->next = totemp->next;
                }
                delete totemp;
                break;
            }
            this_thread::sleep_for(chrono::seconds(2));
            toprev = totemp;
            totemp = totemp->next;
        }
        this_thread::sleep_for(chrono::seconds(2));
        // update matrix
        if (flag)
            cout << "Setting adjacencyMatrix[" << from << "][" << to << "] and adjacencyMatrix[" << to << "][" << from << "] to 0\nDecrementing the edge count" << endl
                 << endl;
        else
            cout << "No match is found after iterating through the adjacency list, the edge does not exist." << endl
                 << endl;
    }

    void DFS(int v)
    {
        stack<int> s;
        queue<int> arr;
        cout << "Initialized an empty STACK" << endl
             << "Start from the source vertex " << v << " of the graph." << endl;
        cout << "Push the vertex " << v << ". Mark the vertex as visited. " << endl
             << "Traversing through the vertices" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        bool *visited = new bool[vertices]{false};
        s.push(v);
        while (!s.empty())
        {
            int currentvertex = s.top();
            s.pop();
            cout << "Pop the vertex: " << currentvertex << " and mark it visited if it is not" << endl;
            if (!visited[currentvertex])
            {
                arr.push(currentvertex);
                visited[currentvertex] = true;
            }
            this_thread::sleep_for(chrono::seconds(2));
            GraphNode *temp = adjacencyList[currentvertex];
            int i = 0;
            cout << "Exploring and pushing all unvisited neighbors of the " << currentvertex << " vertex in the stack." << endl;
            while (temp != NULL)
            {
                cout << "\t" << i << " - " << temp->data << endl;
                if (!visited[temp->data])
                {
                    cout << "\t " << temp->data << " is not visited so push it in the stack" << endl;
                    s.push(temp->data);
                }
                else
                {
                    cout << "\t " << temp->data << " is visited so don't push it in the stack" << endl;
                }
                temp = temp->next;
                this_thread::sleep_for(chrono::seconds(2));
                i++;
            }
        }
        this_thread::sleep_for(chrono::seconds(3));
        cout << endl;
        cout << "DFS Traversal Result: " << endl;
        while (!arr.empty())
        {
            int c = arr.front();
            arr.pop();
            cout << c << "  ";
        }
        delete[] visited;
    }

    void BFS(int v)
    {
        queue<int> q;
        queue<int> arr;
        cout << "Initialized an empty QUEUE" << endl
             << "Start from the source vertex " << v << " of the graph." << endl;
        cout << "Enqueue the vertex" << v << ".Mark the vertex as visited." << endl
             << "Traversing through the vertices" << endl;
        bool *visited = new bool[vertices]{false};
        q.push(v);
        while (!q.empty())
        {
            int currentvertex = q.front();
            q.pop();
            cout << "Dequeue the vertex: " << currentvertex << " and mark it visited if it is not" << endl;
            if (!visited[currentvertex])
            {
                arr.push(currentvertex);
                visited[currentvertex] = true;
            }
            this_thread::sleep_for(chrono::seconds(2));
            GraphNode *temp = adjacencyList[currentvertex];
            int i = 1;
            cout << "Exploring and enqueuing all unvisited neighbors of the " << currentvertex << " vertex." << endl;
            while (temp != NULL)
            {
                cout << "\t" << i << " - " << temp->data << endl;
                if (!visited[temp->data])
                {
                    cout << "\t " << temp->data << " is not visited so enqueue it" << endl;
                    q.push(temp->data);
                }
                else
                {
                    cout << "\t " << temp->data << " is visited so don't enqueue it" << endl;
                }
                temp = temp->next;
                this_thread::sleep_for(chrono::seconds(2));
            }
            cout << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
        cout << endl;
        cout << "BFS Traversal Result: " << endl;
        while (!arr.empty())
        {
            int c = arr.front();
            arr.pop();
            cout << c << "  ";
        }
        delete[] visited;
    }
    bool isCycle(int current, bool *visited, int parent, stack<int> &path)
    {
        cout << "\tMarking " << current << " as visited and pushing it in path" << endl;
        visited[current] = true;
        path.push(current);

        GraphNode *temp = adjacencyList[current];
        cout << "Doing DFS Traversal of AdjacencyList at " << current << endl;
        this_thread::sleep_for(chrono::seconds(1));
        while (temp != nullptr)
        {
            int nextVertex = temp->data;

            if (!visited[nextVertex])
            {
                if (isCycle(nextVertex, visited, current, path))
                {
                    return true;
                }
            }
            else if (nextVertex != parent)
            {
                cout << "Cycle is detected, return true;" << endl;
                cout << "Cycle Path: ";
                stack<int> printStack;
                while (!path.empty())
                {
                    int vertex = path.top();
                    path.pop();
                    printStack.push(vertex);
                    if (vertex == nextVertex)
                    {
                        break;
                    }
                }

                while (!printStack.empty())
                {
                    cout << printStack.top() << " ";
                    printStack.pop();
                }

                cout << nextVertex << endl;

                return true;
            }

            temp = temp->next;
        }

        path.pop();
        return false;
    }

    bool checkCycle()
    {
        bool *visited = new bool[vertices]{false};

        for (int i = 0; i < vertices; ++i)
        {
            stack<int> path;
            cout << "isCycle function called for " << i << endl;
            if (!visited[i] && isCycle(i, visited, -1, path))
            {
                cout << "CYCLE EXIST" << endl;
                delete[] visited;
                return true;
            }
            else
            {
                cout << "\tIt is visited so skip it." << endl;
            }
        }

        cout << "IT'S NOT A CYCLE" << endl;
        delete[] visited;
        return false;
    }

    int minDistance(int *distance, bool *visited) const
    {
        // Initialize min value
        int min = INT_MAX, min_index;

        for (int i = 0; i < vertices; i++)
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i];
                min_index = i;
            }

        return min_index;
    }

    void dijkstra(int **matrix, int source)
    {
        cout << " - Initializing distance and visited array" << endl;
        int *distance = new int[vertices];
        /* The output array:distance[i] will hold the shortest distance from src to i*/

        bool *visited = new bool[vertices];
        /* visited[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized*/
        cout << " - Initializing all the distances as infinite and visited as false" << endl;
        /* Initialize all distances as INFINITE and *visited as false*/
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
            distance[i] = INT_MAX;
        }

        // Distance of source vertex from itself is always 0
        cout << " - Mark the distance[" << source << "] as 0" << endl;
        distance[source] = 0;

        // Find shortest path for all vertices
        for (int count = 0; count < vertices - 1; count++)
        {
            /* Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.*/
            int min = minDistance(distance, visited);
            cout << " - Picked the minimum distance index = " << min << " from the unvisited vertices and marking it true in visited array" << endl;

            // Mark the picked vertex as processed
            visited[min] = true;
            cout << " - Updating distance value of the adjacent vertices of the picked vertex " << min << "\n   which are not yet visited" << endl;
            // Update distance value of the adjacent vertices of the picked vertex.
            for (int i = 0; i < vertices; i++)
            {

                /* Update distance[v] only if is not in visited, there is an edge from min to i, and total weight of path from source to i through min is smaller than current value of distance[i]*/
                if (!visited[i] && matrix[min][i] && distance[min] != INT_MAX && distance[min] + matrix[min][i] < distance[i])
                {
                    distance[i] = distance[min] + matrix[min][i];
                    cout << "Updating distance[" << i << "] : " << distance[i] << " to (" << distance[min] << " + " << matrix[min][i] << ") " << endl;
                }
            }

            this_thread::sleep_for(chrono::seconds(4));
        }
        cout << endl
             << endl
             << "Printing the Updated distance array" << endl;
        // print the constructed distance array
        cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < vertices; i++)
            cout << i << "         " << distance[i] << endl;
    }

    void PRIM()
    {
        cout << endl
             << "Initializing array[source,destination,weight] and visited array" << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(2));
        bool *visited = new bool[vertices]{false};
        int **array = new int *[vertices - 1];
        for (int i = 0; i < vertices - 1; i++)
        {
            array[i] = new int[3];
        }
        cout << endl
             << "Mark visited[0] = true" << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << endl
             << "Running a loop until all the edges(vertices-1) are saved" << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << endl
             << "Save all the minimum edges of Graph in array" << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(2));
        visited[0] = true;
        int sum = 0;
        for (int i = 0; i < vertices - 1; i++)
        {
            int min = INT_MAX;
            int row = 0;
            int col = 0;
            cout << "Calculating minimum weighted edge of the matrix with the unvisited vertex by traversing through whole matrix" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            for (int r = 0; r < vertices; r++)
            {
                if (visited[r])
                    for (int c = 0; c < vertices; c++)
                    {
                        if (min > adjacencyMatrix[r][c])
                        {
                            if (!visited[c] && adjacencyMatrix[r][c] != 0)
                            {
                                min = adjacencyMatrix[r][c];
                                row = r;
                                col = c;
                            }
                        }
                    }
            }
            cout << "Minimum weighted edge in Matrix is " << row << " - " << col << " with weight " << min << endl
                 << "Marking the Destination " << col << " as visited.(visited[destination] = true)\n and saving it in edge and its weight in array" << endl
                 << endl;
            this_thread::sleep_for(chrono::seconds(2));
            visited[col] = true;
            // from
            array[i][0] = row;
            // to
            array[i][1] = col;
            // weight
            array[i][2] = adjacencyMatrix[row][col];
            sum += adjacencyMatrix[row][col];
        }
        this_thread::sleep_for(chrono::seconds(2));
        cout << endl
             << "PRIM'S Algorithm Result: " << endl;
        for (int i = 0; i < vertices - 1; i++)
        {
            cout << array[i][0] << " - " << array[i][1] << " : " << array[i][2] << endl;
        }
        cout << "Answer: " << sum << endl;
    }
    void mergesort(int **&array, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergesort(array, low, mid);
            mergesort(array, mid + 1, high);
            merge(array, low, mid, high);
        }
    }

    void merge(int **&array, int low, int mid, int high)
    {
        int i = low, j = mid + 1, k = 0;
        int arr[high - low + 1][3] = {0};

        while (i <= mid && j <= high)
        {
            if (array[i][2] > array[j][2])
            {
                arr[k][0] = array[j][0];
                arr[k][1] = array[j][1];
                arr[k++][2] = array[j++][2];
            }
            else
            {
                arr[k][0] = array[i][0];
                arr[k][1] = array[i][1];
                arr[k++][2] = array[i++][2];
            }
        }

        while (i <= mid)
        {
            arr[k][0] = array[i][0];
            arr[k][1] = array[i][1];
            arr[k++][2] = array[i++][2];
        }

        while (j <= high)
        {
            arr[k][0] = array[j][0];
            arr[k][1] = array[j][1];
            arr[k++][2] = array[j++][2];
        }

        // Copy the merged array back to the original array
        for (int s = 0; s <= high - low; s++)
        {
            array[low + s][0] = arr[s][0];
            array[low + s][1] = arr[s][1];
            array[low + s][2] = arr[s][2];
        }
    }
    void UNION(int x, int y, int *p)
    {
        int rx = find(x, p);
        int ry = find(y, p);
        if (rx == ry)
            return;
        p[ry] = rx;
    }
    int find(int x, int *p)
    {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x], p);
    }
    void Kruskal()
    {
        cout << endl
             << " - Initialized an array of edges[source,destination,weight] of length(edge count)" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        int **array = new int *[edges];
        for (int i = 0; i < edges; i++)
        {
            array[i] = new int[3];
        }
        int k = 0;
        cout << " - Saving all the edges in the array of edges" << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Saved Unsorted Edges in Array: " << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(2));
        for (int i = 0; i < vertices; i++)
        {
            for (int j = i + 1; j < vertices; j++)
            {
                if (adjacencyMatrix[i][j])
                {
                    array[k][0] = i;
                    array[k][1] = j;
                    array[k][2] = adjacencyMatrix[i][j];
                    cout << " " << k + 1 << ". Edge: " << i << " - " << j << ", Weight: " << adjacencyMatrix[i][j] << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                    k++;
                }
            }
        }
        cout << endl
             << " - Sort all the edges of the array on the basis of weight" << endl
             << endl
             << "Saved Sorted Edges in Array: " << endl;
        this_thread::sleep_for(chrono::seconds(2));
        // Merge sort
        mergesort(array, 0, edges - 1);
        for (int i = 0; i < edges; i++)
        {
            cout << " " << i << ". Edge: " << array[i][0] << " - " << array[i][1] << ", Weight: " << array[i][2] << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }

        int **w = new int *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            w[i] = new int[3];
            w[i][0] = -1;
            w[i][1] = -1;
            w[i][2] = -1;
        }

        int *parent = new int[vertices];
        for (int i = 0; i < vertices; i++)
        {
            parent[i] = i;
        }
        cout << endl
             << " - Iterating through the sorted edges" << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(2));
        int count = 0;
        int sum = 0;
        for (int e = 0; count < vertices - 1; e++)
        {
            int rx = find(array[e][0], parent);
            int ry = find(array[e][1], parent);
            cout << "Comparing " << array[e][0] << " and " << array[e][1] << " representatives: " << rx << " and " << ry << endl;
            this_thread::sleep_for(chrono::seconds(1));

            if (rx != ry)
            {
                int wgt = array[e][2];
                w[e][0] = array[e][0];
                w[e][1] = array[e][1];
                w[e][2] = wgt;
                UNION(rx, ry, parent);
                cout << "UNION: Merging sets with representatives " << rx << " and " << ry << endl;
                this_thread::sleep_for(chrono::seconds(1));
                count++;
                sum += wgt;
                cout << "Added Edge to MST: " << w[e][0] << " - " << w[e][1] << " : " << w[e][2] << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout << "Skipping Edge: " << array[e][0] << " - " << array[e][1] << " : " << array[e][2] << " (Forms a cycle)" << endl
                 << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
        this_thread::sleep_for(chrono::seconds(3));
        cout << endl
             << "Kruskal's Algorithm Result: " << endl;
        for (int i = 0; i < vertices - 1; i++)
        {
            cout << w[i][0] << " - " << w[i][1] << " : " << w[i][2] << endl;
        }
        cout << "Answer: " << sum << endl;
    }

    void printmatrix()
    {
        cout << endl
             << "Adjacency Matrix: " << endl;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adjacencyMatrix[i][j] << "   ";
            }
            cout << endl;
        }
    }
    void insertinfo()
    {
        cout << "1.Creates a new GraphNode with value to and inserts it at the beginning of the adjacency list for the vertex from.\n  Also Creates a new GraphNode with value from and inserts it at the beginning of the adjacency list for the vertex to" << endl;
        cout << "2.Updates the corresponding entry in the adjacency matrix with the given weight(if any otherwise 0)." << endl;
        cout << "3.Increments the edges count." << endl
             << endl;
    }
    void searchinfo()
    {
        cout << "1.Begin at the source vertex (from)." << endl;
        cout << "2.Traverse the adjacency list of the source vertex." << endl;
        cout << "3.Check each adjacent vertex in the adjacency list to see if it matches the destination vertex (to)." << endl;
        cout << "4.If a match is found, the edge exists between the source (from) and destination (to) vertices." << endl;
        cout << "5.If no match is found after iterating through the adjacency list, the edge does not exist." << endl
             << endl;
    }
    void deleteinfo()
    {
        cout << "1.Traverse the adjacency list of the source vertex (let's call it from) & then,\nSearch for the destination vertex (to) within the adjacency list." << endl;
        cout << "2.Once the edge is found, remove the corresponding entry from the adjacency list of from." << endl;
        cout << "3.Since the graph is undirected, also remove the  edge (from) by traversing the adjacency list of 'to' and removing the corresponding entry." << endl;
        cout << "4.Set adjacencyMatrix[from][to] and adjacencyMatrix[to][from] to 0\n  to indicate that the edge between u and v is removed." << endl;
        cout << "5.If match is found after iterating through the adjacency list, Decrement the edge count." << endl;
        cout << "6.If no match is found after iterating through the adjacency list, the edge does not exist." << endl
             << endl;
    }
};

void learnGraphs()
{

    while (1)
    {
        Graph g(5);
        g.addEdge(0, 1, 1);
        g.addEdge(1, 2, 3);
        g.addEdge(1, 3, 5);
        g.addEdge(3, 4, 9);
        g.addEdge(4, 2, 7);
        cout << endl
             << "-----------------------------------------------------------------" << endl;
        cout << "--------------------------GRAPH TUTOR----------------------------" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Which concept of Graphs you want to learn? " << endl;
        cout << "1.  Insert Edge" << endl;
        cout << "2.  Search Edge" << endl;
        cout << "3.  Delete Edge" << endl;
        cout << "4.  BFS(Breadth-First Search) Traversal" << endl;
        cout << "5.  DFS(Depth-First Search) Traversal" << endl;
        cout << "6.  Cycle Detection" << endl;
        cout << "7.  Finding Shortest path using Dijkstra's Algorithm" << endl;
        cout << "8.  Prim's algorithm for finding MST(Minimum Spanning Tree)" << endl;
        cout << "9.  Kruskal's algorithm for finding MST(Minimum Spanning Tree)" << endl;
        cout << "10. Print Graph" << endl;
        cout << "11. Go Back" << endl;
        cout << "0. Exit Program" << endl;
        cout << "Option: ";
        int option;
        cin >> option;

        clearScreen();
        if (option == 0)
        {
            exit(1);
        }
        else if (option == 11)
        {
            break;
        }
        else if (option == 1)
        {
            g.insertinfo();
            this_thread::sleep_for(chrono::seconds(5));
            cout << endl
                 << "The Graph is already populated using random edges" << endl
                 << "Graph: " << endl;
            g.printgraph();
            cout << endl;
            int from, to, weight;
            cout << "Enter the edge information you want to insert(NOTE: Don't repeat any edge): \nNOTE:Don't exceed the limit of maximum vertices which is 5" << endl
                 << "FROM: ";
            cin >> from;
            cout << "TO: ";
            cin >> to;
            cout << "Do you want to insert Weight?[1 or 0]: ";
            cin >> weight;
            if (weight)
            {
                cout << "WEIGHT: ";
                cin >> weight;
                cout << "INSERTION: " << endl;
                g.addedge(from, to, weight);
            }
            else
            {
                cout << "INSERTION: " << endl;
                g.addedge(from, to, 0);
            }
            cout << "Graph: " << endl;
            g.printgraph();
        }
        else if (option == 2)
        {
            g.searchinfo();
            this_thread::sleep_for(chrono::seconds(8));
            cout << "Graph: " << endl;
            g.printgraph();
            cout << endl;
            int from, to;
            cout << "Enter the edge information you want to Search: " << endl
                 << "FROM: ";
            cin >> from;
            cout << "TO: ";
            cin >> to;
            cout << "SEARCH: " << endl;
            g.searchEdge(from, to);
        }
        else if (option == 3)
        {
            g.deleteinfo();
            this_thread::sleep_for(chrono::seconds(2));
            cout << endl;
            cout << endl
                 << "The Graph is already populated using random values" << endl
                 << "Graph: " << endl;
            g.printgraph();
            int from, to;
            cout << "Enter the edge information you want to Delete: " << endl
                 << "FROM: ";
            cin >> from;
            cout << "TO: ";
            cin >> to;
            cout << "DELETION: " << endl;
            g.removeEdge(from, to);
            cout << "Graph after DELETION: " << endl;
            g.printgraph();
        }
        else if (option == 4)
        {
            cout << "BFS Traversal: " << endl;
            cout << "Use QUEUE to keep track of the vertices to be visited in the order they are discovered.Start with an empty queue." << endl
                 << "\tStart at the source vertex of the Graph and visit the source vertex." << endl;
            cout << "2.Enqueue the starting vertex.Mark the starting vertex as visited." << endl;
            cout << "3.While the queue is not empty:" << endl
                 << "\t - Dequeue a vertex from the front of the queue." << endl
                 << "\t - Explore and enqueue all unvisited neighbors of the dequeued vertex." << endl
                 << "\t - Mark each visited neighbor as visited and enqueue it." << endl;
            this_thread::sleep_for(chrono::seconds(7));
            cout << endl
                 << "The Graph is already populated using random values" << endl;
            g.printgraph();
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Process of BFS Traversal : " << endl;
            g.BFS(0);
            cout << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
        else if (option == 5)
        {
            cout << "DFS Traversal: " << endl;
            cout << "Use STACK to keep track of the vertices to be visited in the order they are discovered.Start with an empty Stack." << endl
                 << "\tStart at the source vertex of the Graph and visit the source vertex" << endl;
            cout << "2.Enqueue the starting vertex.Mark the starting vertex as visited." << endl;
            cout << "3.While the stack is not empty:" << endl
                 << "\t - Pop a vertex from the top of the stack." << endl
                 << "\t - Explore and push all unvisited neighbors of the popped vertex." << endl
                 << "\t - Mark each visited neighbor as visited and push it in the stack." << endl;
            this_thread::sleep_for(chrono::seconds(7));
            cout << endl
                 << "The Graph is already populated using random values" << endl;
            g.printgraph();
            this_thread::sleep_for(chrono::seconds(2));
            cout << endl
                 << "Process of DFS Traversal : " << endl;
            g.DFS(0);
            cout << endl;
        }
        else if (option == 6)
        {
            cout << "Make two Function checkCycle & isCycle" << endl;
            cout << "-checkCycle Function:" << endl
                 << "\t 1.calls the isCycle function to check if there is a cycle starting from that vertex\n\t   for each unvisited vertex" << endl;
            cout << "\t 2.If a cycle is found during the iteration, the function prints that a cycle exists" << endl
                 << "-isCycle Function: " << endl;
            cout << "\t 1.Mantain a stack named path\n\t 2.Do DFS Traversal" << endl
                 << "\t 3.After visiting all neighbors, pop the current vertex from the path stack.\n\t 4.If a cycle is detected, return true; otherwise, return false." << endl;
            cout << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << "The Graph is already populated using random values" << endl;
            g.printgraph();
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Process of Cycle Detection : " << endl;
            g.checkCycle();
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl;
        }
        else if (option == 7)
        {
            cout << "Dijkstra's algorithm for finding the shortest paths from a source vertex:" << endl;
            cout << "1.Initialize distances{infinite} and visited{false} array" << endl
                 << "2.Declare distance of source vertex from itself as 0\n3.Find shortest path for all vertices" << endl;
            cout << "\t - Pick the minimum distance vertex from the set of vertices not yet processed." << endl
                 << "\t - Mark the picked vertex as processed" << endl;
            cout << "\t - Update distance value of the adjacent vertices of the picked vertex." << endl
                 << "4.Print the constructed distance array" << endl;
            cout << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << "The Graph is already populated using random values" << endl;
            g.printgraph();
            this_thread::sleep_for(chrono::seconds(2));
            cout << "Process of Dijkstra's algorithm : " << endl;
            g.dijkstra(g.adjacencyMatrix, 0);
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl;
        }
        else if (option == 8)
        {
            cout << "PRIM's algorithm for finding MST(Minimum Spanning Tree): " << endl
                 << endl
                 << "FACT: Minimum Spanning Tree has Edges = Vertices-1" << endl
                 << endl
                 << " - Initialize an array to keep track of visited vertices and a 2D array to store the edges[source,destination,weight]" << endl;
            cout << " - Also initialize a sum variable = 0 & Mark the first vertex as visited.\n   Run a loop in which  find the minimum-weight edge that connects a visited vertex to an unvisited vertex." << endl;
            cout << " - Update the source and destination variables to store the indices of the minimum-weight edge." << endl;
            cout << " - Mark the newly selected vertex visited[destination] as visited" << endl
                 << endl;
            this_thread::sleep_for(chrono::seconds(7));
            cout << "The Graph is already populated using random values" << endl;
            g.printgraph();
            this_thread::sleep_for(chrono::seconds(2));
            cout << endl
                 << "Process of PRIM's algorithm : " << endl;
            g.PRIM();
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl;
        }
        else if (option == 9)
        {
            cout << "KRUSKAL's algorithm for finding MST(Minimum Spanning Tree): " << endl
                 << endl
                 << "FACT: Minimum Spanning Tree has Edges = Vertices-1" << endl
                 << endl
                 << "UNION Function: merges the sets containing elements x and y." << endl;
            cout << "FIND Function:finds the representative element (root) of the set to which element x belongs.\nKRUSKAL Function: \n - Mantain a variable to find the sum of Minimum weighted Edges\n - Initializes an array array to store all edges in the graph." << endl;
            cout << " - Sorts the edges based on their weights.\n - Initializes an array parent for the UNION-Find data structure." << endl;
            cout << " - Iterates through the sorted edges, adding them to the MST if they do not create a cycle.\n - The final MST edges and their weights are stored in the array w" << endl;
            this_thread::sleep_for(chrono::seconds(7));
            cout << endl;
            cout << "The Graph is already populated using random values" << endl;
            g.printgraph();
            this_thread::sleep_for(chrono::seconds(2));
            cout << endl
                 << "Process of KRUSKAL's algorithm : " << endl;
            g.Kruskal();
            this_thread::sleep_for(chrono::seconds(3));
            cout << endl;
        }
        else if (option == 10)
        {
            cout << "Graph: " << endl;
            g.printgraph();
        }
        else
        {
            cout << "Wrong Choice" << endl;
        }
    }
    return;
}

// ------------------------- Graphs ends here ----------------------

int main()
{

    cout << "------------------- WELCOME TO DATA STRUCTURE LEARNING PLATFORM ------------------- " << endl
         << endl;

    int option;

    do
    {
        cout << endl
             << "Q) What do you want to learn" << endl
             << endl;
        cout << "Press 1 for learning Linked List" << endl
             << "Press 2 for learning Stacks And Queues" << endl
             << "Press 3 for learning Binary Tree" << endl
             << "Press 4 for learning Hashing" << endl
             << "Press 5 for learning Graphs" << endl
             << "Press 6 for exit" << endl
             << "------------------------------------------" << endl
             << endl
             << "Enter: ";
        cin >> option;
        cout << endl
             << "------------------------------------------" << endl;

        clearScreen();

        switch (option)
        {
        case 1:

            mainLL();
            break;

        case 2:

            mainStackAndQueue();
            break;

        case 3:

            learnTree();
            break;

        case 4:

            mainHash();
            break;

        case 5:
            learnGraphs();
            break;

        case 6:

            exit(1);

        default:

            cout << "Invalid Input. Try Again";
            break;
        }

    } while (option != 6);

    return 0;
}