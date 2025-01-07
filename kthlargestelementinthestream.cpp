#include<iostream>
#include<vector>
#include<functional>
#include<queue>

using namespace std;

class KthLargest
{
    vector<int> nums;
    int k;
    priority_queue<int, vector<int>, less<int> > maxheap;

    void populateQueue()
    { 
        for(int ele : nums)
        {
            maxheap.push(ele);
        }
    }

    void popKelement()
    {
        for(int i = 0; i<k-2; i++)
        {
            maxheap.pop();
        }
    }

    public:
    void add(vector<int> &nums, int k);
    int addValue(int num);

};

void KthLargest:: add(vector<int> &nums, int k)
{
    for(int x: nums)
    {
        this->nums.push_back(x);
    }
    this->k = k;
    populateQueue();
    popKelement();
}

int KthLargest:: addValue(int num)
{
    nums.push_back(num);

    //find the kth element and return
    maxheap.push(num);
    maxheap.pop();
    return maxheap.top();

}
int main()
{

    vector<int> nums = { 9, 12, 35, 10, 4, 9, 11, 33, 25, 66, 13};
    int k=2;
    KthLargest obj;
    obj.add(nums, k);
    cout<<obj.addValue(80)<<endl;

    return 0;

}