#include <iostream>
using namespace std;
#include "Node.hpp"

//Time complexity :- O(n)
void print(Node<int> *p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//Time complexity :- O(n)
int size(Node<int> *head)
{
    int count = 0;
    while (head != nullptr)
    {
        head = head->next;
        count++;
    }
    return count;
}

//Time complexity :- O(n^2)
Node<int> *takeInput()
{
    cout << "Enter -1 if you want to terminate process" << endl;
    int data;
    cout << "Enter data in node: ";
    cin >> data;
    Node<int> *head = nullptr;
    while (data != -1)
    {
        Node<int> *newNode = new Node<int>(data);
        if (head == nullptr)
            head = newNode;
        else
        {
            Node<int> *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Enter data in node: ";
        cin >> data;
    }
    return head;
}

//Time complexity :- O(n)
Node<int> *optimisedTakeInput()
{
    cout << "Enter -1 if you want to terminate process" << endl;
    int data;
    cout << "Enter data in node: ";
    cin >> data;
    Node<int> *head = nullptr;
    Node<int> *tail = nullptr;
    while (data != -1)
    {
        Node<int> *newNode = new Node<int>(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            //Or we can write :- ||| tail = tail -> next; |||
        }
        cout << "Enter data in node: ";
        cin >> data;
    }
    return head;
}

//Time complexity :- O(n)
Node<int> *insertNode(Node<int> *head, int i, int data)
{
    if (i < 0)
        cout << "Invalid position" << endl;
    else
    {
        Node<int> *newNode = new Node<int>(data);
        Node<int> *temp = head;
        if (i == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            for (int j = 0; j < i - 1 && temp != nullptr; j++)
                temp = temp->next;
            if (temp != nullptr)
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else
                cout << "Out of bound" << endl;
        }
    }
    return head;
}

//Time complexity :- O(n)
Node<int> *deleteNode(Node<int> *head, int i)
{
    if (i < 0)
        cout << "Invalid Index" << endl;
    else
    {
        Node<int> *temp = head;
        if (i == 0)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            for (int j = 0; j < i - 1 && temp != nullptr; j++)
                temp = temp->next;
            if (temp != nullptr)
            {
                Node<int> *a = temp->next;
                Node<int> *b = a->next;
                temp->next = b;
                delete a;
            }
            else
                cout << "Out of bound" << endl;
        }
    }
    return head;
}

int main()
{
    //Static allocation
    /*Node<int> n1(1);
    Node<int>* head = &n1;

    Node<int> n2(2);

    head->next = &n2;

    cout<<head->data<<" "<<head->next->data<<endl;*/

    //Dynamic Allocation
    /*Node<int> *n1 = new Node<int>(10);
    Node<int> *n2 = new Node<int>(20);

    Node<int> *head = n1;
    n1->next = n2;

    cout<<head->data<<" "<<head->next->data<<endl;*/

    Node<int> *head = optimisedTakeInput();
    print(head);
    cout << size(head) << endl;
    head = deleteNode(head, 3);
    print(head);
    cout << size(head) << endl;

    return 0;
}