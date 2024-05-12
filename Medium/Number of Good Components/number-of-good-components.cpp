//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
bool bfs(int node, bool visited[], vector<vector<int>>& adj) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        int nodes = 0;
        int edges = adj[node].size();
        bool flag = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            nodes++;
            if (adj[curr].size() != edges) flag = false;
            for (auto it : adj[curr]) {
                if (visited[it]) continue;
                visited[it] = true;
                q.push(it);
            }
        }
        return flag && edges + 1 == nodes;
    }
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<vector<int>> adj(v + 1);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        bool visited[v + 1] = {false};
        int count = 0;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                if (bfs(i, visited, adj)) count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends