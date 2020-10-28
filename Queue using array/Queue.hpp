template<typename T>
class Queue
{
    private:
        //Data members
        T *data;
        int nextIndex;
        int firstIndex;
        int Size;
        int Capacity;

    public:
        //Parameterised Constructor
        Queue(int Capacity)
        {   this->Capacity = Capacity;
            data = new T[Capacity]; 
            nextIndex = 0;
            firstIndex = -1;
            Size = 0;
        }

        //Returns number of elements in Queue.
        int size()
        {
            return Size;
        }

        //Returns is Queue is Empty.
        bool isEmpty()
        {
            return size() == 0;
        }

        //Insert element in Queue
        void enqueue(T element)
        {
            if(size() == Capacity)
                cout<<"Queue Overflow"<<endl;
            else
            {
                data[nextIndex] = element;
                nextIndex = (nextIndex + 1) % Capacity;
                if(firstIndex == -1)
                    firstIndex = 0;
                Size++;
            }
        }

        //Returns the first element in Queue
        T front()
        {
            if(isEmpty())
            {
                cout<<"Queue empty"<<endl;
                return 0;
            }
            return data[firstIndex];
        }

        //Removes element from Queue
        T dequeue()
        {
            if(size() == 0)
            {
                cout<<"Queue Underflow"<<endl;
                return 0;
            }
            T ans = data[firstIndex];
            firstIndex = (firstIndex + 1) % Capacity;
            Size--;
            if(Size == 0)
            {
                firstIndex = -1;
                nextIndex = 0;
            }
            return ans; 
        }

};