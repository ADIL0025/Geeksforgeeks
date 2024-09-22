//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        const auto n{int(arr.size())};
        int h[n+1];
        memset(h,0,sizeof h);
        for(int i: arr){
            ++h[i];
        }
        vector<int> theNums(2,-1);
        std::function<bool()> isDone = [&theNums](){
            return *min_element(theNums.begin(),theNums.end()) > -1;
        };
        for(int i{1};i<=n;++i){
            if(h[i]==2){
                theNums.front()=i;
            }
            else if(h[i]==0){
                theNums.back()=i;
            }
            if(isDone()){
                return theNums;
            }
        }
        return {};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends