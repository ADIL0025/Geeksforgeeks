//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>s ;
        int n= x.size();
        if(n%2!=0) return false;
        
        s.push(x[0]);
        
        for(int i =1;i<n;i++)
        {
            if(s.empty())
            {
                s.push(x[i]);
            }
            
            else 
            {
                char temp= s.top();
                if(temp=='(' && x[i]==')')
                s.pop();
                
                else if(temp=='{' && x[i]=='}')
                s.pop();
                
                else if(temp=='[' && x[i]==']')
                s.pop();
                
                else 
                s.push(x[i]);
            }
        }
        
        if(s.empty()) return true;
        
        else return false;
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends