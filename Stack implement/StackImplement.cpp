#include<iostream>
#include "Stack.cpp"
using namespace std;

int main()
{
    Stack stk(4);

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);

    cout<<stk.top()<<endl;

    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;

    cout<<stk.Size()<<endl;

    cout<<boolalpha<<stk.isEmpyt()<<endl;
    cout<<boolalpha<<stk.isFull()<<endl;

    return 0;
}