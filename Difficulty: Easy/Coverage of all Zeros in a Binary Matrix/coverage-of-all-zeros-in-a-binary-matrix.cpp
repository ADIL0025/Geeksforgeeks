//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution {
public:
    int FindCoverage(vector<vector<int>>&arr){
        // Code here
        int ans=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=arr.size(),m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    for(int k=0;k<4;k++){
                        int nr=i+drow[k],nc=j+dcol[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<m){
                            if(arr[nr][nc]==1) ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		Solution obj;
		int ans = obj.FindCoverage(matrix);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends