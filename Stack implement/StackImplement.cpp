#include<iostream>
#include<climits>
#include "Stack.cpp"
using namespace std;

int main()
{
    Stack<char> stk(5);
    stk.push('o');
    stk.push('s');
    stk.push('a');
    stk.push('f');
    stk.push('j');
    stk.push('y');
    cout << stk.top() << endl;

    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;

    cout << stk.Size() << endl;

    return 0;
}
