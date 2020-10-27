#include<iostream>
#include "stack.cpp"
using namespace std;

int main()
{
    Stack<char> stk;
    stk.push(100);
    stk.push(101);
    stk.push(102);
    stk.push(103);
    stk.push(104);

    cout << stk.top() << endl;

    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;

    cout << stk.size() << endl;

    cout << stk.isEmpty() << endl;

    return 0;
}