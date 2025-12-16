#include <iostream>
#include <string>

using namespace std;

struct Node
{
    char data;
    Node *next;
};

void printTrain(Node *head)
{
    cout << "Train: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void addToEnd(Node *&head, char val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addToFront(Node *&head, char val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAfter(Node *head, char target, char val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            Node *newNode = new Node();
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
}

void updateNode(Node *head, char oldVal, char newVal)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == oldVal)
        {
            temp->data = newVal;
            return;
        }
        temp = temp->next;
    }
}

void deleteNode(Node *&head, char val)
{
    if (head == NULL)
        return;

    if (head->data == val)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
}

bool searchNode(Node *head, char val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *head = NULL;

    cout << "Train Simulation Start" << endl;

    addToEnd(head, 'A');
    addToEnd(head, 'C');
    addToEnd(head, 'D');
    cout << "Added A, C, D to end:" << endl;
    printTrain(head);

    addToFront(head, 'Z');
    cout << "Added Z to front:" << endl;
    printTrain(head);

    insertAfter(head, 'A', 'B');
    cout << "Inserted B after A:" << endl;
    printTrain(head);

    updateNode(head, 'Z', 'E');
    cout << "Updated Z to E:" << endl;
    printTrain(head);

    deleteNode(head, 'C');
    cout << "Delete C:" << endl;
    printTrain(head);

    bool foundB = searchNode(head, 'B');
    bool foundC = searchNode(head, 'C');
    cout << "Search: Found B? " << (foundB ? "Yes" : "No") << " | Found C? " << (foundC ? "Yes" : "No") << endl;

    cout << "Final Train Formation" << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}