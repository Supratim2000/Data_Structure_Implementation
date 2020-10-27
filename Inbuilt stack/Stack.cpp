#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);

    cout << stk.top() << endl;

    stk.pop();
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;
    cout << boolalpha << stk.empty() << endl;
    stk.pop();
    cout << stk.top() << endl;
    cout << stk.size() << endl;
    stk.pop();
    cout << stk.top() << endl;
    stk.pop();
    cout << stk.top() << endl;

    cout << boolalpha << stk.empty() << endl;

    return 0;
}