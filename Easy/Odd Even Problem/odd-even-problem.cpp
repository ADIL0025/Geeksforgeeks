//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string oddEven(string S) {
        int X=0;
        int Y=0;
        
        int freq[26];
        memset(freq,0,sizeof(freq));
        
        for(int i=0;i<S.size();i++){
               freq[S[i]-97]++;    
            
        }
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                if(i%2==0 && freq[i]%2!=0)
                     Y++;
                if(i%2!=0 && freq[i]%2==0)
                     X++;
                
            }
        }
        
        // cout<<X<<" "<<Y<<endl;
        if((X+Y)%2==0)
            return("EVEN");
        return("ODD");
    }


};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends