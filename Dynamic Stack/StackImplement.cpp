#include<iostream>
#include "Stack.cpp"
using namespace std;

int main()
{
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(70);
    stk.push(80);

    cout << stk.Size() << endl;

    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.top() << endl;
    cout << stk.pop() << endl;

    stk.push(200);

    cout << stk.Size() << endl;

    cout << stk.isEmpyt() << endl;

    return 0;
}