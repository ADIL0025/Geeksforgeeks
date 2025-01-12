//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int max_area = 0;
        int i = 0;
        int n = arr.size();
        int j = n - 1;
        while(i<j)
        {
            max_area = max(max_area, (j-i) * min(arr[i],arr[j]));
            if(arr[i] < arr[j])
            i++;
            else
            j--;
        }
        return max_area;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends