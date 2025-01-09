//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int,int> mp;
        int count = 0;
        vector<int> ans;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
            if(mp[arr[i]]==1){
                count++;
            }
        }
        ans.push_back(count);
        int j = k,i=0;
        while(j<arr.size()){
           mp[ arr[i]]--;
           if(mp[arr[i]]==0){
               count--;
           }
           mp[arr[j]]++;
           
           if(mp[arr[j]]==1){
                count++;
            }
            i++;
            j++;
            ans.push_back(count);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends