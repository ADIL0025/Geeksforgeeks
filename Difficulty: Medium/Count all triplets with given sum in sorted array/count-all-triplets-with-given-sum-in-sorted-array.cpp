//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countTriplets(vector<int> &array, int target) {
        // Code Here
        sort(array.begin(), array.end());
        int output=0;
        int n=array.size();
        for(int i=0; i<n; i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                if(array[i]+array[start]+array[end]==target){
                    if(array[start]==array[end]){
                        int number=end-start+1;
                        output+=(number*(number-1))/2;
                        start=n;
                    }
                    else{
                        int value=array[start];
                        int a=0;
                        while(array[start]==value){
                            a++;
                            start++;
                        }
                        value=array[end];
                        int b=0;
                        while(array[end]==value){
                            end--;
                            b++;
                        }
                        output+=a*b;
                    }
                }
                else if(array[i]+array[start]+array[end]>target){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return output;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends