#include<iostream>
using namespace std;
#include "Queue.hpp"

int main()
{
    Queue<int> myque(3);

    myque.enqueue(10);
    myque.enqueue(20);
    myque.enqueue(30);
    myque.enqueue(40);
    myque.enqueue(50);
    myque.enqueue(60);
    myque.enqueue(70);
    myque.enqueue(80);
    myque.enqueue(90);
    myque.enqueue(100);
    myque.enqueue(110);
    myque.enqueue(120);
    myque.enqueue(130);

    cout<<myque.size()<<endl;

    return 0;
}