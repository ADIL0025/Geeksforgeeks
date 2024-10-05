//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    void solve(vector<vector<char>>&v,vector<vector<int>>&vis,int i,int j){
        // if(i<0 || j<0 || i>=v.size() || j>=v[0].size())return;
        int x,y;
        // if(vis[i][j])return;
        vis[i][j]=1;
        for(x=i-1;x<=i+1;x++){
            for(y=j-1;y<=j+1;y++){
                if(x==i && y==j)continue;
                if(x>=0 && y>=0 && x<v.size() && y<v[0].size() && v[x][y]=='1' && vis[x][y]==0){
                    solve(v,vis,x,y);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>&v) {
        // Code here
        int i,j,n=v.size(),m=v[0].size(),ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(vis[i][j]==0 && v[i][j]=='1'){
                    solve(v,vis,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends