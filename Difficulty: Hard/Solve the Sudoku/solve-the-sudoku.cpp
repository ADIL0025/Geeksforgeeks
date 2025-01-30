//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
        bool isSafe(vector<vector<int>> &mat, int i, int j, int num, 
            vector<int> &row, vector<int> &col, vector<int> &box) {
      
        if( (row[i] & (1 << num)) || (col[j] & (1 << num)) ||
                               (box[i / 3 * 3 + j / 3] & (1 << num)) )
            return false;
        
        return true;
    }
    
    bool sudokuSolverRec(vector<vector<int>> &mat, int i, int j, vector<int> &row, vector<int> &col, vector<int> &box) {
        int n = mat.size();
        if (i == n - 1 && j == n)
            return true;
    
        if (j == n) {
            i++;
            j = 0;
        }
      
        if (mat[i][j] != 0)
            return sudokuSolverRec(mat, i, j + 1, row, col, box);
    
        for (int num = 1; num <= n; num++) {
            if (isSafe(mat, i, j, num, row, col, box)) {
                mat[i][j] = num;
              
                row[i] |= (1 << num);
                col[j] |= (1 << num);
                box[i / 3 * 3 + j / 3] |= (1 << num);
              
                if (sudokuSolverRec(mat, i, j + 1, row, col, box))
                    return true;
                  
                mat[i][j] = 0;
                row[i] &= ~(1 << num);
                col[j] &= ~(1 << num);
                box[i / 3 * 3 + j / 3] &= ~(1 << num);
            }
        }
      
        return false;
    }
  public:
    void solveSudoku(vector<vector<int>> &mat) {
         int n = mat.size();
        vector<int> row(n, 0), col(n, 0), box(n, 0);
    
        // Set the bits in bitmasks for values that are initital present   
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0) {
                    row[i] |= (1 << mat[i][j]);
                    col[j] |= (1 << mat[i][j]);
                    box[ (i / 3) * 3 + j / 3] |= (1 << mat[i][j]);
                }
            }
        }
    
        sudokuSolverRec(mat, 0, 0, row, col, box);
            
        }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends