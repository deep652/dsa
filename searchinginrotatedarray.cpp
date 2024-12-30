#include<iostream>
#include<vector>

using namespace std;

int searchInRotatedSortedArray(vector<int> &nums, int key)
{
    int left = 0, right = nums.size()-1, mid;
    while(left <= right)
    {
        mid = left + (right - left)/2;

        if(key == nums[mid])
            return mid;

        if(nums[left] <= nums[mid])
        {
            //left half is sorted - > acending order
            if(key >= nums[left] && key < nums[mid]) // 4 5 6 assume mid is 6 left is 4
            {
                right = mid - 1;
            }
            else
                left = mid + 1;

        }
        else
        {
            if(key > nums[mid] && key <= nums[right]) // 1 2 3 assume mid is 1 and right is 3
            {
                 left = mid + 1; //movement is considering the array as a whole
            }
            else
                right = mid - 1;
        }
    }

    return -1;

}
int main()
{

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2 };
    int key = 4;

    int result = searchInRotatedSortedArray(nums, key);

    if(result != -1)
        cout<<"key "<<key <<" Found at : "<<result<<endl;
    else
        cout<<"key doesn't exists in the vector"<<endl;
    
    return 0;
}