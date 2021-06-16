#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

template<typename T>
class TreeNode
{
    public:
        T data;
        vector<TreeNode<T>*> child;
        TreeNode(T data)
        {
            this->data=data;
        }  
        ~TreeNode()
        {
            for(ll i=0;i<child.size();i++)
                delete child.at(i);
        }
};