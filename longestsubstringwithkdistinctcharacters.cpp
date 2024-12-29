#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int longestSubstring(string s, int k)
{
    int n = s.length();
    if (k == 0 || n == 0) return 0;
    if (k > n) return n;

    int i = 0, j=0, localWindowSize = 0, globalWIndowSize = INT_MIN;
    map<char, int> freq;

    while(j<n)
    {
        freq[s[j]]++;
        while(freq.size() > k)
        {
            freq[s[i]]--;
            if(freq[s[i]] == 0)
            {
                cout<<"Erasing ith element as "<<i <<"-> " <<s[i]<<endl;
                freq.erase(s[i]);
            }
            i++;
        }
        if(freq.size() == k)
        {
            localWindowSize = j-i+1;
            globalWIndowSize = max(globalWIndowSize, localWindowSize);
        }
        j++;
    }

    return globalWIndowSize;

}
int main()
{
    string s = "aabacbebebeaaaaa";
    int k = 3;
    //cout<<"Maximum window size is : " <<
    cout<< longestSubstring(s, k)<<endl;
    
    return 0;
}