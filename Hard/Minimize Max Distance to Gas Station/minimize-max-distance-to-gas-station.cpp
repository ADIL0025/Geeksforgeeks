//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(double mid,vector<int>&arr)
    {
        int cnt=0;
        for(int i=1;i<arr.size();i++)
        {
            double distance = arr[i] - arr[i - 1];
            if (distance > mid) {
             cnt += ceil(distance / mid) - 1;
            }
        }
        return cnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n=stations.size();
        double low=0,high=*max_element(stations.begin(),stations.end());
        double diff=1e-6,ans;
        while(high-low>diff)
        {
            double mid=low+(high-low)/2.0;
            int ch=f(mid,stations);
            if(ch>k) low=mid;
            else 
            {
                ans=mid;
                high=mid;
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
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends