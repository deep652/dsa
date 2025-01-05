#include<iostream>
#include<vector>
#include<functional>

using namespace std;

//Comparator functions
bool CompAsc(int e1, int e2)
{
    return e1 < e2; //true means e1 will be placed before e2     5 < 6 or 5 will come before 6 
}

bool CompDesc(int e1, int e2)
{
    return e2 < e1; //true means e2 will be placed before e1     6 < 5 or 6 will come before 5 -> desc order
}

//Comparator functor - > a class or struct overloaping () parenthesis operator

class CompFunctor
{
    public:
    bool operator()(int e1, int e2)
    {
        return e1 < e2; // the above stands true here also
    }
};

//lamda

auto CompLamda = [](int e1, int e2){ return e1 < e2;};


int main()
{
    vector<int> nums = {1, 9, 5, 6, 8, 2, 4, 10, 40, 33, 24, 36, 67, 21, 55};

    for(int x: nums)
    {
        cout<<x<<"\t";
    }
    cout<<endl;
    //sorting of vector based on comparator function, functor, and lamda functions

    //Sorting based on comparator function

    // sort(nums.begin(), nums.end(), CompDesc);

    //sort(nums.begin(), nums.end(), CompFunctor()); //here in sort it is expecting a metho
    //TO_DO what is the difference between giving comparator in sort and mentioning defalut comparator
    //while declarating priority queue


    //sort(nums.begin(), nums.end(), CompLamda);

    for(int x: nums)
    {
        cout<<x<<"\t";
    }
    cout<<endl;

}