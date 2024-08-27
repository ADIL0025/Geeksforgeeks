//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool compare(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second>b.second;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        vector<pair<int,int>>ans(mp.begin(),mp.end());
        sort(ans.begin(),ans.end(),compare);
        vector<int>res;
        for(auto it:ans)
        {
            while(it.second--)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends