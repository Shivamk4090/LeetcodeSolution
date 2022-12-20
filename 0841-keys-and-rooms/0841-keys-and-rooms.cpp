class Solution {
    void dfs(int node, vector<bool>& vis, vector<vector<int>> &g){
        vis[node] = true;
        for(auto n:g[node]){
            if(vis[n]==false)
                dfs(n, vis, g);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& r) {
        int n  = r.size();
        vector<vector<int>> g(n);
        for(int i=0; i<r.size(); i++){
            for(int j=0; j<r[i].size(); j++){
                g[i].push_back(r[i][j]);
            }
        }
        vector<bool> vis(n, false);
        dfs(0, vis, g);
        bool ans  = true;
        for(int i=0; i<n; i++){
            if(vis[i]==false){
                ans = false;
                break;
            }
        }
        return ans;
    }
};