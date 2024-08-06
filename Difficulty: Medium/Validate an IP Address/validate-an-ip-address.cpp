//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isValid(string str) {
        int count=0;
        int num=-1;
        for(int i=0;i<str.length();i++){
            if(str[i]=='.'){
                count++;
                if(num<0 || num>255){
                    return 0;
                }
                num=-1;
            }
            if(str[i]>='0' && str[i]<='9'){
                int a=str[i]-'0';
                if(num<0){
                    num=0;
                }
                
                num=num*10+a;
            }
            if(str[i]!='.' && (str[i]<'0' || str[i]>'9')){
                return 0;
            }
            if((i==0 || (i>=1 && str[i-1]=='.')) && str[i]=='0' && (i<str.length()-1 && str[i+1]!='.')){
                return 0;
            }
        }
        if(count!=3){
            return 0;
        }
        if(num<0 || num>255){
            return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends