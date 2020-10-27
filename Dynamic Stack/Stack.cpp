#include <iostream>
#include <climits>
using namespace std;

template<typename T>
class Stack
{
private:
    T *data;
    int nextIndex;
    int capacity;
    int defaultCapacity = 5;

public:
    Stack()
    {
        capacity = defaultCapacity;
        data = new T[capacity];
        nextIndex = 0;
    }

    int Size()
    {
        return nextIndex;
    }

    bool isEmpyt()
    {
        return nextIndex == 0;
    }

    bool isFull()
    {
        return capacity == nextIndex;
    }

    //To insert element in Stack
    void push(T element)
    {
        if (isFull())
        {
            T *newData = new T[capacity * 2];
            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    //To remove element in Stack
    int pop()
    {
        if (isEmpyt())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        T temp = data[nextIndex - 1];
        nextIndex--;
        return temp;
    }

    //Reads the top most element in Stack
    int top()
    {
        if (isEmpyt())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};
