//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        vector<int> kmp(string s){
            int n=s.size();
            vector<int> lps(n,0);
            
            for(int i=1;i<n;i++){
                int prev_ind=lps[i-1];
                
                while(prev_ind>0&&s[i]!=s[prev_ind]){
                    prev_ind=lps[prev_ind-1];
                }
                
                if(s[i]==s[prev_ind]){
                    lps[i]=prev_ind+1;
                }else{
                    lps[i]=0;
                }
                
                
                
            }
            return lps;
            
            
        }
        vector <int> search(string pat, string txt)
        {
            //code here
             string res=pat+'#'+txt;
            vector<int> lps=kmp(res);
            vector<int> ans;
            int m = pat.size();

            
            for(int i=m+1;i<lps.size();i++){
                if(lps[i]==m){
                    ans.push_back(i-2*m);
                }
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends