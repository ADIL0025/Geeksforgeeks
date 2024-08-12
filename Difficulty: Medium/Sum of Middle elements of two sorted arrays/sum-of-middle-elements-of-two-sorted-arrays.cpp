//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        if(arr2.size() < arr1.size()) {
            return SumofMiddleElements(arr2, arr1);
        }
        
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        int lo = 0, hi = n1;
        
        while(lo <= hi) {
            int cut1 = (lo+hi) >> 1;
            int cut2 = (n1 + n2 + 1)/2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];
            
            int r1 = cut1 == n1 ? INT_MAX : arr1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : arr2[cut2];
            
            if((l1<=r2) && (l2<=r1)) {
                if((n1+n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2));
                }
                else {
                    return max(l1, l2);
                }
            }
            else if(l1 > r2) {
                hi = cut1-1;
            }
            else {
                lo = cut1+1;
            }
        }
        
        return 0.0;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends