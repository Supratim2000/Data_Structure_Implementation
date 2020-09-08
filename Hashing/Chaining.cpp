#include<iostream>
#include "chains.hpp"
#define size 10
using namespace std;

int HashFunc(int key)
{
    return key%size;
}

void Insert(struct Node *hash[],int key)
{
    int index=HashFunc(key);
    SortedInsert(&hash[index],key);
}

struct Node* KeySearch(struct Node *hash[],int key)
{
    int index=HashFunc(key);
    return Search(&hash[index],key);
}

int main()
{
    struct Node *hash[size];
    for(int i=0;i<10;i++)
        hash[i]=nullptr;
    
    Insert(hash,23);
    Insert(hash,13);
    Insert(hash,33);

    struct Node* temp=KeySearch(hash,24);
    if(temp!=nullptr)
        cout<<"Key found"<<endl;
    else
        cout<<"Key not found"<<endl;

    return 0;
}