#include<iostream>
#define size 10
using namespace std;

int hashfn(int val)
{
    return val%size;
}

int Search(int hash[],int key)
{
    int index=hashfn(key);
    int i=0;
    while(hash[(index+i*i)%size]!=0 && hash[(index+i*i)%size]!=key)
        i++;
    if (hash[(index+i*i)%size]==0)
        return -1;
    return (index+i*i)%size;
}

int Probe(int hash[],int key)
{
    int index=hashfn(key);
    int i=0;
    while(hash[(index+i*i)%size]!=0)
        i++;
    return (index+i*i)%size;
}

void insert(int hash[],int key)
{
    int index=hashfn(key);
    if(hash[index])
        index=Probe(hash,key);
    hash[index]=key;
}

int main()
{
    int hash[size]={0};
    insert(hash, 23);
    insert(hash, 43);
    insert(hash, 13);
    insert(hash, 27);

    for(int i=0;i<size;i++)
        cout<<hash[i]<<" ";
    cout<<endl;

    cout << Search(hash, 23) << " ";
    cout << Search(hash, 43) << " ";
    cout << Search(hash, 13) << " ";
    cout << Search(hash, 27) << " ";
    cout<<endl;

    return 0;
}
