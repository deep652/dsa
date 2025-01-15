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

//BAsed on the understand, we don;t need to pass the pair, only the key type is needed to 
//write the compatator 

//Note the belwo will not work, as the comparator is for priorty queue where elements are pairs

// class Comp
// {
//     public:
//     bool operator()(const int e1, const int e2) const
//     {
//         return e1 > e2; //if asc order , to change this or to make this desc order change the condition so that it stays true 
//         //for decending order, i mean if you want e2 to come before e1 than for decending order you 6 to come beofre 5
//         // this means if e1 is 5 and e2 6 and I want 6 to come befor, i must write the condition so that it return true
//         /// in this very case which is e2 < e1
//         // or simplely reverse the order 
//     }
// };


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