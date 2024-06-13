//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       int p1 = 1, p2 = 1, p3 =1, mod = 1e9 + 7;
       for(int i = 3; i <= n; i++)
       {
           int cur = (p1 + p2) % mod;
           p1 = p2;
           p2 = p3;
           p3= cur;
       }
       
       return p3;
     
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends