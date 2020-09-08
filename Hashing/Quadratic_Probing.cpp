#include <iostream>
#define size 10
using namespace std;

int HashFunc(int key)
{
    return key % size;
}

int Probe(int H[], int key)
{
    int index = HashFunc(key);
    int i = 0;
    while (H[(index + i*i) % size])
        i++;
    return (index + i*i) % size;
}

void Insert(int H[], int key)
{
    int index = HashFunc(key);
    if (H[index])
        index = Probe(H, key);
    H[index] = key;
}

int Search(int H[], int key)
{
    int index = HashFunc(key);
    int i = 0;
    if (H[index] == 0)
        return -1;
    while (H[(index + i*i) % 10] != key && H[(index + i*i) % 10] != 0)
        i++;
    if (H[(index + i*i) % 10] == 0)
        return -1;
    return (index + i*i) % 10;
}

int main()
{
    int Hash[size] = {0};
    Insert(Hash, 12);
    Insert(Hash, 25);
    Insert(Hash, 35);
    Insert(Hash, 26);

    cout << Search(Hash, 35) << endl;

    return 0;
}