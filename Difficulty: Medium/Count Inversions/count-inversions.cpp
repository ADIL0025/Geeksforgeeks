//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
         int n = arr.size();
        vector<int> temp(n);
        return mergeSortAndCount(arr, temp, 0, n - 1);
    }

private:
    // Helper function to merge two halves of the array and count inversions.
    int mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
        int i = left;    // Starting index for the left subarray
        int j = mid + 1; // Starting index for the right subarray
        int k = left;    // Starting index for the temporary array
        int inv_count = 0;

        // Merge the two subarrays while counting inversions.
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i + 1); // Count inversions
            }
        }

        // Copy the remaining elements of the left subarray (if any).
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy the remaining elements of the right subarray (if any).
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the sorted subarray into the original array.
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return inv_count;
    }

    // Helper function to perform merge sort and count inversions.
    int mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right) {
        int inv_count = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in the left subarray.
            inv_count += mergeSortAndCount(arr, temp, left, mid);

            // Count inversions in the right subarray.
            inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

            // Count split inversions between the two halves.
            inv_count += mergeAndCount(arr, temp, left, mid, right);
        }

        return inv_count;

    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends