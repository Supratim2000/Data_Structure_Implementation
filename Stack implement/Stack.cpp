#include <iostream>
#include<climits>
using namespace std;

template <typename T>
class Stack
{
    private:
        T *data;
        int nextIndex;
        int capacity;

    public:
        Stack(int capacity)
        {
            this->capacity = capacity;
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
            if(isFull())
                cout<<"Stack is full"<<endl;
            else
            {
                data[nextIndex] = element;
                nextIndex++;
            }
        }

        //To remove element in Stack 
        T pop()
        {
            if(isEmpyt())
            {
                cout<<"Stack is Empty"<<endl;
                return (T)'\0';
            }
            T temp = data[nextIndex-1];
            nextIndex--;
            return temp;
        }

        //Reads the top most element in Stack
        T top()
        {
            if(isEmpyt())
            {
                cout<<"Stack is empty"<<endl;
                return (T) '\0';
            }
            return data[nextIndex-1];
        }
};
