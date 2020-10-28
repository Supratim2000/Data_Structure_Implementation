#include<iostream>
using namespace std;
#include "Queue.hpp"

int main()
{
    Queue<int> myque(5);

    myque.enqueue(10);
    myque.enqueue(20);
    myque.enqueue(30);
    myque.enqueue(40);
    

    cout<<myque.dequeue()<<endl;
    cout<<myque.dequeue()<<endl;

    myque.enqueue(50);
    myque.enqueue(60);

    cout<<myque.front()<<endl;
    cout<<myque.size()<<endl;
    cout<<boolalpha<<myque.isEmpty()<<endl;
}