//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dis(n, vector<int>(m,1e9));
        dis[0][0] = grid[0][0];
        set<pair<int,pair<int,int>>>st; // {wt,{row,col}}
        st.insert({grid[0][0], {0,0}});
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        while(!st.empty()){
            auto it = st.begin();
            st.erase(it);
            
            int wt = it->first;
            int row = it->second.first;
            int col = it->second.second;
            
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if((nRow>=0 && nRow<n && nCol>=0 && nCol<m) && 
                    wt + grid[nRow][nCol] < dis[nRow][nCol]){
                    dis[nRow][nCol] = wt + grid[nRow][nCol];
                    st.insert({dis[nRow][nCol],{nRow, nCol}});
                }
            }
        }
        return dis[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends