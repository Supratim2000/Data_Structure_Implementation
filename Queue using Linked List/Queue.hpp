template <typename T>
class Node
{
    public:
        T data;
        Node<T> *next;

        Node(T data)
        {
            this->data = data;
            next = nullptr;
        }
};

template <typename T>
class Queue
{
    private:
        Node<T> *head;
        Node<T> *tail;
        int Size;
    public:
        //Parameterised constructor
        Queue()
        {
            Size = 0;
            head = nullptr;
            tail = nullptr;
        }

        //Returning if queue is empty
        bool isEmpty()
        {
            return head == nullptr;
        }

        //Returning size
        int size()
        {
            return Size;
        }

        //Inserting data
        void enqueue(T element)
        {
            Node<T> *newNode = new Node<T>(element);
            if(isEmpty())
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail=newNode;
            }
            Size++;
        }

        //Returning first element
        T front()
        {
            return isEmpty()?0:head->data;
        }

        //Deleting data
        T dequeue()
        {
            if(isEmpty())
                return 0;
            T ans = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            Size--;
            return ans;
        }       
};