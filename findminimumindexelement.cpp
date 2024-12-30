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



int findRotationIndexSimplied(vector<int> &nums)
{
    int l=0, r=nums.size()-1, mid;
    if(nums[l] < nums[r])
        return -1;

    while(l<r)
    {
        mid = l+ (r - l)/2;
        
        if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])
        {
            return mid;
        }

        //Based on the recent learning, this should be simplied to check only which half is sorted,
        //  which we can do by simply checking left and mid i.e. if (nums[left] < nums[mid]) this ensures
        //  that the first half is sorted and the number lies in 
        //  the unsorted half, so move left and rignt to the unsorted part of the array
        if(nums[l] < nums[mid])
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
    vector<int> nums = {  7, 9, 10, 17, 1, 2, 3, 4, 5, 6};
    cout<<"Index of minimum element is -> "<<findRotationIndexSimplied(nums)<<endl;
    return 0;
}