//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends



class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<vector<int>>vt;
        for(int i=0;i<n;i++){
            vt.push_back({abs(arr[i]-brr[i]),i});
        }
        sort(vt.rbegin(),vt.rend());
        int cnt1=0,cnt2=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            int indx=vt[i][1];
            if(arr[indx]>=brr[indx]){
                if(cnt1<x){
                    ans+=arr[indx];
                    cnt1++;
                }
                else{
                    ans+=brr[indx];
                    cnt2++;
                }
            }
            else{
                 if(cnt2<y){
                    ans+=brr[indx];
                    cnt2++;
                }
                else{
                    ans+=arr[indx];
                    cnt1++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends