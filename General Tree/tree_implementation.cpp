#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include "TreeNode.hpp"
using namespace std;
typedef long long ll;

void printTree(TreeNode<ll>* root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<" :";
    for(ll i=0;i<root->child.size();i++)
        cout<<root->child.at(i)->data<<" ";
    cout<<endl;
    for(ll i=0;i<root->child.size();i++)
        printTree(root->child.at(i));
}

void deleteTree(TreeNode<ll>* root)
{
    if(root==nullptr)
        return;
    for(ll i=0;i<root->child.size();i++)
        deleteTree(root->child.at(i));
    delete root;
}

void preOrder(TreeNode<ll>* root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    for(ll i=0;i<root->child.size();i++)
        preOrder(root->child.at(i));
}

void postOrder(TreeNode<ll>* root)
{
    if(root==nullptr)
        return;
    for(ll i=0;i<root->child.size();i++)
        postOrder(root->child.at(i));
    cout<<root->data<<" ";
}

TreeNode<ll>* takeInput()
{
    ll data,n;
    cout<<"Input data: ";
    cin>>data;
    TreeNode<ll>* root=new TreeNode<ll>(data);
    cout<<"Enter number of children of "<<data<<" : ";
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        TreeNode<ll>* node=takeInput();
        root->child.push_back(node);
    }
    return root;
}

TreeNode<ll>* takeInputLevelWise()
{
    ll data;
    cout<<"Enter root data: ";
    cin>>data;
    TreeNode<ll>* root=new TreeNode<ll>(data);
    queue<TreeNode<ll>*> pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty())
    {
        TreeNode<ll>* currentNode=pendingNode.front();
        pendingNode.pop();
        ll n;
        cout<<"Enter number of children of "<<currentNode->data<<" : ";
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            ll ch;
            cout<<"Enter no."<<i+1<<" child of "<<currentNode->data<<" : ";
            cin>>ch;
            TreeNode<ll>* node=new TreeNode<ll>(ch);
            currentNode->child.push_back(node);
            pendingNode.push(node);
        }
    }
    return root;
}

void LevelOrderTraversal(TreeNode<ll>* root)
{
    if(root==nullptr)
        return;
    queue<TreeNode<ll>*> pendingNode;
    pendingNode.push(root);
    cout<<root->data<<" ";
    while(!pendingNode.empty())
    {
        TreeNode<ll>* currentNode=pendingNode.front();
        pendingNode.pop();
        for(ll i=0;i<currentNode->child.size();i++)
        {
            cout<<currentNode->child[i]->data<<" ";
            pendingNode.push(currentNode->child[i]);
        }
    }
}

ll countNodes(TreeNode<ll>* root)
{
    if(root==nullptr)
        return 0;
    ll count=0;
    for(ll i=0;i<root->child.size();i++)
        count+=countNodes(root->child[i]);
    return count+1;
}

ll sumOfNodes(TreeNode<ll>* root)
{
    if(root==nullptr)
        return 0;
    ll sum=0;
    for(ll i=0;i<root->child.size();i++)
        sum+=sumOfNodes(root->child[i]);
    sum+=root->data;
    return sum;
}

ll maxNode(TreeNode<ll>* root)
{
    if(root==nullptr)
        return LLONG_MIN;
    ll mx=root->data;
    for(ll i=0;i<root->child.size();i++)
        mx=max(mx,maxNode(root->child[i]));
    return mx;
}

ll height(TreeNode<ll>* root)
{
    if(root==nullptr)
        return 0;
    ll ans=0;
    for(ll i=0;i<root->child.size();i++)
        ans=max(ans,height(root->child[i]));
    return ans+1;
}

void printAtLevelK(TreeNode<ll>* root,ll k)
{
    if(root==nullptr)
        return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    for(ll i=0;i<root->child.size();i++)
        printAtLevelK(root->child[i],k-1);
}

void printLeafNodes(TreeNode<ll>* root)
{
    if(root==nullptr)
        return;
    if(root->child.empty())
    {
        cout<<root->data<<" ";
        return;
    }
    for(ll i=0;i<root->child.size();i++)
        printLeafNodes(root->child[i]);
}

ll countLeafNodes(TreeNode<ll>* root)
{
    if(root==nullptr)
        return 0;
    ll count=0;
    if(root->child.empty())
        return 1;
    for(ll i=0;i<root->child.size();i++)
        count+=countLeafNodes(root->child[i]);
    return count;
}

int main()
{
    // 1 3 2 3 4 2 5 6 1 9 0 0 2 7 8 0 0 0
    TreeNode<ll>* root=takeInputLevelWise();
    printTree(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    LevelOrderTraversal(root);
    cout<<endl;
    cout<<countNodes(root)<<endl;
    cout<<sumOfNodes(root)<<endl;
    cout<<maxNode(root)<<endl;
    cout<<height(root)<<endl;
    printAtLevelK(root,2);
    cout<<endl;
    printLeafNodes(root);
    cout<<endl;
    cout<<countLeafNodes(root)<<endl;

    deleteTree(root);

    return 0;
}