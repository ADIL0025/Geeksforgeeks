//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    string compareFrac(string str) {
        
        int a, b, c, d;
        sscanf(str.c_str(), "%d/%d, %d/%d", &a, &b, &c, &d);

        
        int left = a * d;
        int right = b * c;

        if (left > right) {
            return to_string(a) + "/" + to_string(b);
        } else if (left < right) {
            return to_string(c) + "/" + to_string(d);
        } else {
            return "equal";
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends