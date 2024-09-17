//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
         sort(arr.begin(),arr.end());
        int n=arr.size(),ans=arr[n-1]-arr[0];
        int maxi,mini;
        
        // for min diff the operation should be in form of
        // +++++pivotIndex------
        // we will try for all index as pivot
        
        for(int i=1;i<n;i++){
            
            if(arr[i]-k<0)continue;// setting a pivotindex must insure the number should
                                  //be positive
                                  
            mini=min(arr[0]+k,arr[i]-k);// all the el before i having +K
            
            maxi=max(arr[n-1]-k,arr[i-1]+k);// all the el from i have -K
            
            ans=min(ans,abs(maxi-mini));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends