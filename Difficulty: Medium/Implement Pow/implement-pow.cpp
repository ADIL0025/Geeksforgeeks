//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    double solve(double b, int e){
        if(e==1) return b;
        double temp=solve(b,e/2);
        if(e%2) return temp*temp*b;
        return temp*temp;
    }
    double power(double b, int e) {
        // code here
        if(e==0) return 1;
        if(e<0) b=(double)1/b;
        e=abs(e);
        return solve(b,e);
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends