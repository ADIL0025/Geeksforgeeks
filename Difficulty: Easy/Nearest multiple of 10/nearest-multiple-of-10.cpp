//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        int flag = 0;
        int m=n;
        if(n!=1){
            if(str[n-1]>'5'){
                while(str[n-2]=='9'){
                    str[n-2]='0';
                    n--;
                    if(n==1){
                        flag=1;
                    }
                }
                if(!flag){
                    ++str[n-2];
                }
            }
            str[m-1]='0';

        }
        else {
            if(str[n-1]>'5'){
                flag=1;
            }
            str[n-1]='0';
        }
        string s;
        if(flag) s='1'+str;
        else s= str;
        return s;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends