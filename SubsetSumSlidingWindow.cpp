#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

class SubsetSumSlidingWindow
{
    private:
    //vector<int> nums = {4, 4, 4};
    public:
    //SubsetSumSlidingWindow(vector<int> &num):num{nums};
    long long maximumSubarraySum(vector<int> & nums, int k);

};

long long SubsetSumSlidingWindow :: maximumSubarraySum(vector<int>& nums, int k) 
{
        //write the algorthm to find all subarray of size k, along with a flag wether the duplicate id
        //involved or not
        int i=0, j=0;
        int n = nums.size();
        long long sum = 0;
        bool flag = false;
        map<int, int> freq;
        vector< pair<long long, bool > > ans;

        while(j<n)
        {
            
            sum += nums[j]; 
            freq[nums[j]]++;

            if((j-i+1) == k)
            {
                for(auto x:freq)
                {
                    if(x.second>1)
                    {
                        flag = true;
                        break;
                    }
                }
                
                ans.push_back(make_pair(sum,flag));
                flag = false;
                sum -= nums[i]; 
                freq[nums[i]]--;

                if (freq[nums[i]] == 0) {
                freq.erase(nums[i]);

            }
                
                i++;
            }
            j++;
        }

        long long sumans = 0;
        for(auto it = ans.begin(); it!=ans.end();it++)
        {
            cout<<it->first<<" ->"<<it->second<<endl;
            if(it->second == false && sumans < it->first )
            {
               sumans = it->first;   
            }
        }

        return sumans;
}

int main()
{
    vector<int> nums = {1,5,4,2,9,9,9};
    SubsetSumSlidingWindow obj;
    cout<<obj.maximumSubarraySum(nums, 3);

    return 0;
}
