#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>

using namespace std;

int maxSumSubarray(vector<int> &arr, int k)
{
    int i=0, j=0, sum=0;
    int global_sum = INT_MIN;
    while(j<arr.size())
    {
        sum += arr[j];

        if(j-i+1 == k)
        {

            if(global_sum < sum)
                global_sum = sum;

            sum -= arr[i];
            i++;
        }
        j++;
    }
    return global_sum;
}

int maxSumSubarrayDistinct(vector<int> &arr, int k)
{
    int i=0, j=0, sum=0;
    int global_sum = INT_MIN;
    map<int, int> freq;
    bool flag = false;
    while(j<arr.size())
    {
        sum += arr[j];
        freq[arr[j]]++;

        if(j-i+1 == k)
        {
            for(pair<int,int> x: freq)
            {
                if(x.second>2)
                {
                    flag = true;
                }
                

            }

            if(global_sum < sum && flag == false)
                global_sum = sum;

            sum -= arr[i];
            freq[arr[i]] --;
            i++;
            flag = false;
        }
        j++;
    }
    return global_sum;
}

// This won't work because if we remove one duplicate from window, it will remove other occurances too
//take the below example, I want to remove one occurance of 9, but it is removing the second occurance od
//9 too, making the unique_elements size to always 2, while I am assuming the size of the unique elements will
//be equal to window size

// int maxSumSubarrayDistinctOptimised(vector<int> &arr, int k)
// {
//     int i=0, j=0, sum=0;
//     int global_sum = INT_MIN;
//     unordered_set<int> uniqueElements;
//     while(j<arr.size())
//     {
//         sum += arr[j];
//         uniqueElements.insert(arr[j]);

//         // while(uniqueElements.size()<(j-i+1)) //the window must have duplicates
//         // {
//         //     sum -= arr[i];
//         //     uniqueElements.erase(arr[i]);
//         //     i++;
//         // }

//         if((j-i+1 )== k)
//         {
//             cout<<"size of windiw is "<<j-i+1<<endl;
//             cout<<"size of uniquw elements is "<<uniqueElements.size()<<endl;
//             if(uniqueElements.size() == j-i+1)
//             {
//                 global_sum = max(global_sum, sum);
//             }
            
//             sum -= arr[i];
//             uniqueElements.erase(arr[i]);
//             i++;
//         }
//         j++;
//     }
//     return (global_sum == INT_MIN) ? 0 : global_sum;
// }

//lets work through this and try to minimise the number of ilterantion for map


int maxSumSubarrayDistinctOptimised(vector<int> &arr, int k)
{
    int i=0, j=0, sum=0;
    int global_sum = INT_MIN;
    map<int, int> freq;
    bool flag = false;
    while(j<arr.size())
    {
        sum += arr[j];
        freq[arr[j]]++;

        while(freq[arr[j]]>1)
        {
            freq[arr[i]]--;
            sum = sum-arr[i];
            if(freq[arr[i]] == 0)
            {
                freq.erase(arr[i]);
            }
            i++;
        }
        if(j-i+1 == k)
        {
                global_sum = max(global_sum, sum);
                sum -= arr[i];
                freq[arr[i]]--;
                if(freq[arr[i]] == 0)
                    freq.erase(arr[i]);

                i++;
               // cout<<"global sum "<<global_sum<<"local sum "<<sum<<endl;
        }
        j++;
    }
    return global_sum;
}

int main()
{
    // vector<int> arr = {2, 1, 5, 1, 3, 2};
    // int k=3;

    // vector<int> arr = {4, 4, 4};

    // vector<int> arr = {9, 2, 9, 5, 6};
    // int k=3;


    // vector<int> arr = {1, 5, 4, 2, 9, 9, 9};
    // int k = 3;

    vector<int> arr = {9,18,10,13,17,9,19,2,1,18};
    int k=5;

    cout<<"Maximum sum subaary of size "<<k<<" is "<<maxSumSubarrayDistinctOptimised(arr, k)<<endl;

    return 0;
}