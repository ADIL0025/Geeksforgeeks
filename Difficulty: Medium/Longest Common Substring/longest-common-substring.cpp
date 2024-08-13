//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
       int Len = 0;
        string str;
        
        int i=0;
     while(i<str1.size()){
            str = "";
           int j=i;
           while(j<str1.size()){
                str += str1[j];
                if(str2.find(str) <= str2.size()){
                    Len = max(Len,j-i+1);
                   // j++;
                }j++;
            }
            i++;
        }
        
        return Len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends