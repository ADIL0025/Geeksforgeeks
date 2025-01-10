//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        
        // your code here
    unordered_set<char>ans;
    int left=0;
    int total=0;
    for(int right=0;right<s.size();right++ ){
        while(ans.find(s[right])!=ans.end()){
            ans.erase(s[left]);
            left++;
        }
        ans.insert(s[right]);
        total=max(total,right-left+1);
    }
    return total;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends