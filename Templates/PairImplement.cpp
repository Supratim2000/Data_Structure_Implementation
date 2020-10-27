#include<iostream>
#include "Pair.cpp"
using namespace std;

int main()
{
    Pair<int, char> myPair1(10, 'u');
    Pair<int, char> myPair2(69, 'y');
    Pair<int, char> myPair3(45, 'a');

    myPair1.setX(93);

    cout << myPair1.getX() << " ---> " << myPair1.getY() << endl;
    cout << myPair2.getX() << " ---> " << myPair2.getY() << endl;
    cout << myPair3.getX() << " ---> " << myPair3.getY() << endl;

    return 0;
}