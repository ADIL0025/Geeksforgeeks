//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int isvalid(int n, int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

class Solution {
  private:
  vector<int> par, rank;
  
  int find(int u)
  {
      if (par[u] == u)
        return u;

      return par[u] = find(par[u]);
  }
  
  void merge(int u, int v)
  {
      
      u = find(u);
      v = find(v);
        if (u == v)
            return;

        if (rank[u] < rank[v]) {
            par[u] = v;
            rank[v] += rank[u];
            
        }
        else {
            par[v] = u;
            rank[u] += rank[v];
        }
  }
        
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int> mp;
        int ans = 0;
        
        
        rank.resize(n * n);
        par.resize(n * n);
        
        for (int i = 0; i < n * n; i++)
        {
            par[i] = i;
            rank[i] = 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) continue;
                
                int curr = i * n + j;
                
                for (int k = 0; k < 4; k++)
                {
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    int nd = nx * n + ny;

                    if (isvalid(n, nx, ny) && grid[nx][ny] == 1)
                    {
                        merge(curr, nd);
                    }
                }
            }
        }
        
       
        
        //make 0 -> 1
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) continue;
                
                int cnt = 0;
                set<int> st;
                
                for (int k = 0; k < 4; k++)
                {
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    
                    
                    if (isvalid(n, nx, ny) && grid[nx][ny] == 1)
                    {
                        int nd = nx * n + ny;
                        st.insert(find(nd));
                    }
                }
                
                for (auto q : st)
                {
                    cnt += rank[q];
                }
                
                ans = max(ans, cnt + 1);
            }
        }
        
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            ans = max(ans, rank[find(cellNo)]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends