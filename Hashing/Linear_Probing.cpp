#include<iostream>
#define size 10
using namespace std;

int hashfn(int val)
{
    return val%size;
}

int Search(int hash[],int val)
{
    int i=0;
    int index=hashfn(val);
    if(hash[index]==val)
        return index;
    else
    {
        while(hash[(index+i)%10]!=0 && hash[(index+i)%10]!=val)
            i++;
        if (hash[(index+i)%10]==0)
            return -1;
        return (index+i)%10;
    }
}

int Probe(int hash[],int key)
{
    int index=hashfn(key);
    int i=0;
    while(hash[(index+i)%size])
        i++;
    return (index+i)%size;
}

void Insert(int hash[],int key)
{
    int index=hashfn(key);
    if(hash[index])
        index=Probe(hash,key);
    hash[index]=key;
}

int main()
{
    int hash[size]={0};
    Insert(hash, 26);
    Insert(hash, 30);
    Insert(hash, 45);
    Insert(hash, 23);
    Insert(hash, 25);
    Insert(hash, 43);
    Insert(hash, 74);
    Insert(hash, 19);
    Insert(hash, 29);

    for(int i=0;i<size;i++)
        cout<<hash[i]<<" ";
    cout<<endl;

    cout<<Search(hash, 23)<<" ";
    cout<<Search(hash, 25)<<" ";
    cout<<Search(hash, 39)<<" ";
    cout<<endl;

    return 0;
}
