//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
       int n=arr1.size();
        int m=arr2.size();
        int i=0;
        int j=0;
        int s2=0,s1=0,ans=0;
        while(i<n && j<m)
        {
            if(arr1[i]<arr2[j])
            {
                s1+=arr1[i];
                i++;
            }
            else if(arr2[j]<arr1[i])
            {
                s2+=arr2[j];
                j++;
            }
            else 
            {
                ans+=max(s1,s2)+arr1[i];
                i++;
                j++;
                s1=0;
                s2=0;
            }
        }
        while(i<n){s1+=arr1[i];i++;}
        while(j<m){s2+=arr2[j];j++;}
        return ans+max(s1,s2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends