#include<iostream>
#include<vector>

using namespace std;

int findRotationIndex(vector<int> &nums)
{
    int l=0, r=nums.size(), mid;
    if(nums[l] < nums[r])
        return -1;

    while(l<r)
    {
        mid = l+ (r - l)/2;
        
        if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])
        {
            return mid;
        }

        if(nums[mid] > nums[l] && nums[mid] > nums[r] ) //normal sorted array retian this property
        {
            //move l to unsorted part, as the smalled resides there
            l = mid ;
        }
        else
        {
            r = mid;
        }
    }
    return -1;


}

int main()
{
    vector<int> nums = {  5, 6, 7, 9, 10, 17, 1, 2, 3, 4};
    cout<<"Index of minimum element is -> "<<findRotationIndex(nums)<<endl;
    return 0;
}