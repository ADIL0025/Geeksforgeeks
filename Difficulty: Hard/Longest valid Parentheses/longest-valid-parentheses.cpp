//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string S) {
        // code here
        stack<char>s1;
        stack<int>s2;
        s2.push(-1);
        int n=S.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(S[i]=='('){
                s1.push('(');
                s2.push(i);
            }
            else{
                if(s1.empty()){
                    s2.push(i);
                }
                else if(s1.top()=='('){
                    s1.pop();
                    s2.pop();
                    ans=max(ans,i-s2.top());
                }
                else{
                    s2.push(i);
                }
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends