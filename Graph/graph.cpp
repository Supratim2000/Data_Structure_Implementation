#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef long long ll;

void BfsForConnectedComponents(vector<ll> graph[],vector<bool>& vis,ll src)
{
    queue<ll> pendingVertices;
    pendingVertices.push(src);
    vis[src]=true;
    while(!pendingVertices.empty())
    {
        ll currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(ll i=0;i<graph[currentVertex].size();i++)
        {
            if(!vis[graph[currentVertex][i]])
            {
                pendingVertices.push(graph[currentVertex][i]);
                vis[graph[currentVertex][i]]=true;
            }
        }
    }
}


void DfsForConnectedComponents(vector<ll> graph[],vector<bool>& vis,ll src)
{
    vis[src]=true;
    cout<<src<<" ";
    for(int i=0;i<graph[src].size();i++)
    {
        if(!vis[graph[src][i]])
        {
            DfsForConnectedComponents(graph,vis,graph[src][i]);
        }
    }
}

void DFS(vector<ll> graph[],ll n)
{
    vector<bool> vis;
    for(ll i=0;i<n;i++)
        vis.push_back(false);
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
            DfsForConnectedComponents(graph,vis,i);
    }    
}

void BFS(vector<ll> graph[],ll n)
{
    vector<bool> vis;
    for(ll i=0;i<n;i++)
        vis.push_back(false);
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
            BfsForConnectedComponents(graph,vis,i);
    }    
}

int main()
{
    fstream infile;
    infile.open("F:\\Placement related\\Coding Ninjas DSA\\Lecture-17(Graph-3)\\Graph\\input.txt",ios::in);
    if(!infile)
    {
        cout<<"Could not open file"<<endl;
        return 0;
    }

    ll n,e;
    infile>>n>>e;
    
    vector<ll> graph[n];
    for(ll i=0;i<e;i++)
    {
        ll u,v;
        infile>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout<<"DFS Traversal: ";
    DFS(graph,n);
    cout<<endl;
    cout<<"BFS Traversal: ";
    BFS(graph,n);
    cout<<endl;

    /*for(ll i=0;i<n;i++)
    {
        cout<<"vertex "<<i<<": ";
        for(ll j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<" ,";
        cout<<endl;
    }*/

    return 0;
}