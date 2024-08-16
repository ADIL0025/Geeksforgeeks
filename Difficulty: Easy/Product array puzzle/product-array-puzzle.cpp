//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        vector<long long int> ans;
        long long int f=1;
        int count=0;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                f=f*nums[i];
            
            if(nums[i]==0){
                count++;
                ind=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(count==0)
                ans.push_back(f/nums[i]);
            if(count>1)
                ans.push_back(0);
            if(count==1) 
            {
                if(i==ind) ans.push_back(f);
                else{
                    ans.push_back(0);
                }
                
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends