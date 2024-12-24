#include<iostream>
#include<vector>

using namespace std;

void kadane_maxsum(vector<int> arr, vector<int> &res)
{
    int global_sum = INT_MIN;
    int local_sum = 0;
    int s=0;
    int e=0;

    for(int i=0; i<arr.size(); i++)
    {
        local_sum += arr[i];

        if(local_sum < arr[i] )
        {
            local_sum = arr[i];
            s = i;
        }
            
        if(global_sum < local_sum)
        {
            global_sum = local_sum;
            e = i;
        }         

    }
    res.push_back(global_sum);
    res.push_back(s);
    res.push_back(e);
    return;

}

void compress_1d(vector<vector<int>> &arr, int s, int e, vector<int> &temp)
{
    int sum = 0;
    for(int i=0; i<arr[0].size(); i++)
    {
        for(int j=s; j<=e; j++)
        {
            sum += arr[j][i];
        }
        temp.push_back(sum);
        sum = 0;
    }
}

int main()
{
    // vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3 };
    // vector<int> res;

    // kadane_maxsum(arr, res);

    // cout<<"Array is "<<endl;
    // for(int x : arr)
    // {
    //     cout<<x<<"\t";
    // }
    // cout<<endl;

    // cout<<"Maximum subset sum is "<< res[0]<<endl;
    // cout<<"Subset is "<<endl;
    // int s = res[1], e = res[2];
    // for(int i=s; i<=e; i++)
    // {
    //     cout<<arr[i]<<"\t";
    // }
    // cout<<endl;

    /* Advanced kadane to reduce 2d in 1d*/

    vector<vector<int>> arr = {
    {1, 2, -1, -4, -20},
    {-8, -3, 4, 2, 1},
    {3, 8, 10, 1, 3},
    {-4, -1, 1, 7, -6} 
    };

    vector<int> res;
    int start_row = 0;
    int end_row = 0;
    vector<int> temp;
    int max_subset = INT_MIN;
    int final_start_row = 0,final_end_row = 0, final_start_col, final_end_col;
    for(; start_row < arr.size(); start_row++)
    {
        end_row = start_row;
        for(; end_row<arr.size();end_row++ )
        {
            temp.clear();
            compress_1d(arr, start_row, end_row, temp);
            res.clear();
            kadane_maxsum(temp, res);
            if(max_subset < res[0])
            {
                max_subset = res[0];
                final_start_row = start_row;
                final_end_row = end_row;
                final_start_col = res[1];
                final_end_col = res[2]; 
            }
        }
    }

    cout<<"Maximum subset sum is " << max_subset<<"start row : "<< final_start_row<<"End row :"
     <<final_end_row<< "start col " <<final_start_col<<"end col " <<final_end_col<<endl;

    return 0;


}
