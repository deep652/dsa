#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>

using namespace std;

class Comp
{
    public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};


vector<int> topKFrequestNumber(vector<int> nums, int k)
{
    // custom comparator using lamdas
    // auto cmp = [](pair<int, int> p1, pair<int,int> p2){ return p2.second<p1.second;};
    // priority_queue< pair<int,int>, vector< pair<int,int> >, decltype(cmp)> que(cmp);

    //custom comparator using functor
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> que;

    //we can achive the  above using comparator functions too, but I am getting error, need to 
    //debug that a bit


    unordered_map<int, int> freq;

    for(int ele: nums)
    {
        freq[ele]++;
    }

    for(pair<int, int> ele: freq)
    {
        que.push(ele);

        if(que.size()>k)
        {
            que.pop();   
        }
    }

    vector<int> res;

    while(!que.empty())
    {
        res.push_back(que.top().first);
        que.pop();
    }

    return res;
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = 2;
    vector<int> res = topKFrequestNumber(nums, k);

    cout<<"Top " <<k<< " frequent numbers are ";
    for(int x: res)
    {
        cout<<x<<"\t";
    }
    cout<<endl;
    return 0;
}