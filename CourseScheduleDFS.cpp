#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    //check if node is not visited
    //mark node visited
    //proccess the node
    //go to all the neighbours
    //repeat

    if(visited[s])
        return;

     visited[s] = true;

     cout<< "visiiting ->"<<s<<endl;

    vector<int> neighbours = adj[s];

    for(int i=0; i<neighbours.size(); i++)
    {
        dfs(adj, visited, neighbours[i]);
    }

    return;
    
}

bool dfs_recursionStack(vector<vector<int>> &adj, vector<bool> &visited,vector<bool> &recStack, int s)
{
    //check if node is not visited
    //mark node visited
    //proccess the node
    //go to all the neighbours
    //repeat

    if(recStack[s] == true)
    {
        cout<<"cycle exits"<<endl;
        return true;
    }


    if(visited[s])
        return;
        
    visited[s] = true;
    recStack[s] = true;

     cout<< "visiiting ->"<<s<<endl;

    vector<int> neighbours = adj[s];

    for(int i=0; i<neighbours.size(); i++)
    {
        if(dfs_recursionStack(adj, visited, recStack, neighbours[i]));
            return true;
    }
    recStack[s] = false; //backtrack
    return false;
    
}
int main()
{
    //DG without cycle
    // vector<vector<int>> pre = {
    //     {1, 0}, {2, 0}, {3, 1}, {3, 2}};

    // int nc = 4;

    //DG with cycle
    vector<vector<int>> pre = {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {1, 3}};
    int nc = 4;

    vector<vector<int> > adjList(nc);

    // for(int i=0; i<pre.size(); i++)
    // {
    //     adjList[pre[i][1]].push_back(pre[i][0]);
    // }

    for(auto x: pre)
    {
        adjList[x[1]].push_back(x[0]);
    }
    //adjlist

    for(auto x: adjList)
    {
        for(int i = 0; i<x.size(); i++)
        {
            cout<<x[i]<<"\t";
        }
        cout<<endl;
    }
    vector<bool> visited(nc, false);

    //dfs(adjList, visited, 0);

    vector<bool> rec(nc, false);

    dfs_recursionStack(adjList, visited, rec, 0);



    return 0;
}