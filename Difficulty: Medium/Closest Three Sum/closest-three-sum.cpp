//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value


class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
         sort(arr.begin(),arr.end());
        int n = arr.size(),mini = INT_MAX,ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(i>0 and arr[i] == arr[i-1])
                continue;
            int j= i+1;
            int k=n-1;
            while(j<k)
            {
                int sum = arr[i]+arr[j] +arr[k];
                if(sum == target)
                    return target;
                else if(sum > target)
                {
                    
                    k--;
                }
                else
                {
                    
                    j++;
                }
                if(abs(sum-target) <= mini)
                {
                    if(mini ==abs(sum-target) )
                        ans = max(ans,sum);
                    else
                        ans = sum;
                    mini = abs(sum-target);
                    
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
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends