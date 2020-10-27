#include<iostream>
using namespace std;

template<typename T>
class Node
{
    public:
        T data;
        Node<T> *next;
        
        Node(T data)
        {
            this->data=data;
            next=nullptr;
        }
};

template<typename T>
class Stack
{
    private:
        Node<T>* head;
        int Size;

    public:
        Stack()
        {
            head=nullptr;
            Size=0; 
        }
        int size()
        {
            return Size;
        }

        bool isEmpty()
        {
            return head==nullptr?true:false;
        }

        void push(T element)
        {
            Node<T> *newNode=new Node<T>(element);
            newNode->next=head;
            head=newNode;
            Size++;
        }

        T pop()
        {
            if(isEmpty())
                return 0;
            T ans=head->data;
            Node<T> *temp=head;
            head=head->next;
            delete temp;
            Size--;
            return ans;
        }

        T top()
        {
            return head==nullptr?0:head->data;
        }
};