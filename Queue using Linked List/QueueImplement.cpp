#include<iostream>
using namespace std;
#include "Queue.hpp"

int main()
{
    Queue<int> myque;

    myque.enqueue(10);
    myque.enqueue(20);
    myque.enqueue(30);
    myque.enqueue(40);
    myque.enqueue(50);
    myque.enqueue(60);

    cout << myque.front() << endl;
    cout << myque.dequeue() << endl;
    cout << myque.dequeue() << endl;
    cout << myque.dequeue() << endl;

    cout << myque.size() << endl;
    cout << myque.isEmpty() << endl;

    return 0;
}