//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>>v;
        map<map<char,int>,vector<string>>mm;
        vector<map<char,int>>m;
        for(int i=0;i<arr.size();i++){
            map<char,int>temp;
            for(int j=0;j<arr[i].size();j++){
                temp[arr[i][j]]++;
            }
            bool flag=false;
            for(int i=0;i<m.size();i++){
                if(m[i]==temp){
                    flag=true;
                }
            }
            if(!flag) m.push_back(temp);
            mm[temp].push_back(arr[i]);
        }
        vector<string>temp;
        for(auto j:mm){
           for(auto k:j.second){
               temp.push_back(k);
           }
           v.push_back(temp);
           temp.clear();
        }
        sort(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends