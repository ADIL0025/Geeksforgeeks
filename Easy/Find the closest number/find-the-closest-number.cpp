//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid;
        }
        
        // Determine the closest value around the found position
        int closest = arr[low];
        if (low > 0) {
            if (abs(arr[low] - k) < abs(arr[low - 1] - k)) {
                closest = arr[low];
            } else if (abs(arr[low] - k) > abs(arr[low - 1] - k)) {
                closest = arr[low - 1];
            } else { // If the differences are the same, return the greater value
                closest = max(arr[low], arr[low - 1]);
            }
        }
        
        return closest;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends