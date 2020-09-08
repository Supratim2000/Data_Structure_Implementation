#define Chains_h

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H,int key)
{
    struct Node *t,*p=*H,*q=nullptr;
    t=new Node;
    t->data=key;
    t->next=nullptr;

    if(p==nullptr)
        *H=t;
    else
    {
        while(p!=nullptr && p->data<key)
        {
            q=p;
            p=p->next;
        }
        if(p==*H)
        {
            t->next=p;
            p=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

struct Node* Search(struct Node **H,int key)
{
    struct Node *p=*H;
    while(p!=nullptr)
    {
        if(p->data==key)
            return p;
        p=p->next;
    }
    return nullptr;
}