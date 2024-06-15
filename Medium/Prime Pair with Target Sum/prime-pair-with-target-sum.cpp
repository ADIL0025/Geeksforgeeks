//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends



class Solution {
  public:
    vector<int> sieve(int n){
        vector<bool> v(n+1,true);
        vector<int> ans;
        for(int i=2;i<n;i++){
            if(v[i]){
                for(int j=i*2 ; j<=n ; j = j+i){
                    v[j] = false;
                }
            }
        }
        for(int i=2;i<n+1;i++){
            if(v[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> getPrimes(int n) {
        // code here
        vector<int> tmp = sieve(n);
        int i=0;
        int j=tmp.size()-1;
        while(i<=j){
            if(tmp[i] + tmp[j] == n)return {tmp[i],tmp[j]};
            else if(tmp[i] + tmp[j] < n){
                i++;
            }else{
                j--;
            }
        }
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends