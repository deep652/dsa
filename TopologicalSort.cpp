#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class CourseSchedule
{
    private:
    vector<vector<int>> prerequiste;
    int noOfEdges = 8;

    vector<int> NoOfCourses;

    public:
    CourseSchedule(vector<vector<int>> &pre): prerequiste(pre)
    {}
    void createAdjList(vector<vector<int> > &adjList);
    void populateDegree(vector<int> &indegree);
};

void CourseSchedule :: populateDegree(vector<int> & indegree)
{
    for(auto x : prerequiste)
    {
        for(auto it = x.begin(); it!=x.end(); it++)
        {
            indegree[*it]++;
            it++;
            
        }
    }
    cout<<endl;
}

void CourseSchedule:: createAdjList(vector<vector<int> > &adjList)
{

}
int main()
{
     vector<vector<int>> pre = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}};

    int nc = 4;
    
    //{
    //         {1, 0},
    //         {2, 1}, {3, 2}, {4, 3}, {5, 4}, {6, 2}, {1, 6}, {7, 1}};
    //int nc = 6;

    vector<int> inDegree(nc,0);
    CourseSchedule obj(pre);
    obj.populateDegree(inDegree);
    for(auto x: inDegree)
    {
        cout<<x<<" " << endl;
    }

    vector<vector<int>> adjList(nc);

    // for(auto it=pre.begin(); it!=pre.end(); it++)
    // {
    //     adjList}(*it)[1]].push_back((*it)[0]);   
    // }

    for(int i=0; i<pre.size(); i++)
    {
        adjList[pre[i][1]].push_back(pre[i][0]);
    }

    for(int i=0; i<adjList.size(); i++)
    {
        cout<<i<<"-> ";
        for(int j=0; j<adjList[i].size(); j++)
        {
            cout<<adjList[i][j]<<"\t";
        }
        cout<<endl;
    }

    // this part is the main logic for topological sort
    //Add all vertices with 
    // in-degree
    // =
    // 0
    // in-degree=0 to a queue. -->> this we can get with inDegree[0] -->> nope, you will have to find it
    // While the queue is not empty:
    // Dequeue a vertex, add it to the result.
    // For all its neighbors, reduce their in-degree by 1.
    // If in-degree of a neighbor becomes 0, enqueue it.

    queue<int> q;

    for(int i=0; i<inDegree.size(); i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
            
        }
    }

    vector<int> result;
    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);
        vector<int> neighbours = adjList[vertex];

        for(int i=0; i<neighbours.size(); i++)
        {
            inDegree[neighbours[i]]--;
            if(inDegree[neighbours[i]] == 0)
            {
                q.push(neighbours[i]);
            }
        }
    }

    if(result.size() != nc)
    {
        cout<<" Cycle exits, No Topological sort "<<endl;
        return 0;
    }

    cout<<"print result vector"<<endl;
    return 0;
}

