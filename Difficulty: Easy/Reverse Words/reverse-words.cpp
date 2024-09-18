//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stack<string> st;
        string word = "";
        string ans = "";

        // Traverse the string to split words based on '.'
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '.') {
                // Push the current word to the stack and reset it
                st.push(word);
                word = "";
            } else {
                // Accumulate the characters for the current word
                word += str[i];
            }
        }

        // Push the last word into the stack (after loop ends)
        st.push(word);

        // Build the reversed string by popping from the stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            // Add a dot only if the stack is not empty to avoid extra dot at the end
            if (!st.empty()) {
                ans += '.';
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends