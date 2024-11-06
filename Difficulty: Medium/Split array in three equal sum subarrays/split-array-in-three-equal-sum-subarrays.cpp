//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int n = arr.size();
        int total_sum = 0;

        // Calculate total sum of array elements
        for (int num : arr) {
            total_sum += num;
        }

        // If total sum is not divisible by 3, no solution exists
        if (total_sum % 3 != 0) {
            return {-1, -1};
        }

        int target_sum = total_sum / 3;
        int current_sum = 0;
        int first_index = -1, second_index = -1;

        // Find the first part end index
        for (int i = 0; i < n; ++i) {
            current_sum += arr[i];
            if (current_sum == target_sum) {
                first_index = i;
                break;
            }
        }

        // If we couldn't find the first part, return {-1, -1}
        if (first_index == -1) {
            return {-1, -1};
        }

        // Reset current_sum and find the second part end index
        current_sum = 0;
        for (int j = first_index + 1; j < n; ++j) {
            current_sum += arr[j];
            if (current_sum == target_sum) {
                second_index = j;
                break;
            }
        }

        // Check if both indices are found and that the remaining part equals the target sum
        if (second_index != -1 && second_index < n - 1) {
            return {first_index, second_index};
        }

        return {-1, -1};
    }
};



//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends