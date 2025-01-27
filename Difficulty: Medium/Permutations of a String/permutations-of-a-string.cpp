//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public: 
  
    void permu(int index,string &s,vector<string>&ans,set<string>&st)
    {
        
        if(index==s.size())
        {  
            if(st.find(s)==st.end()) 
            {
            ans.push_back(s); 
            st.insert(s);
            
            }
            return; 
        }
        
        
        
        for(int i=index;i<s.size();i++)
        {
            swap(s[i],s[index]);
            permu(index+1,s,ans,st);
            swap(s[i],s[index]);
        }
    }
    vector<string> findPermutation(string &s) {
        set<string>st;
        vector<string>ans;
        permu(0,s,ans,st);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends