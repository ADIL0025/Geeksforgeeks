//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  #define ll long long
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int n = arr.size();
        if(n==1) return 0;
        for(ll i: arr){
            pq.push(i);
        }
        ll ans = 0;
        while(!pq.empty()){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ans += (a+b);
            if(pq.empty()) return ans;
            else pq.push(a+b);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends