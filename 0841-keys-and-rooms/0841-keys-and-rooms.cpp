class Solution {
    void dfs(int node, vector<bool>& vis, vector<vector<int>> &g){
        vis[node] = true;
        for(auto n:g[node]){
            if(vis[n]==false)
                dfs(n, vis, g);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& g) {
        vector<bool> vis(g.size(), false);
        dfs(0, vis, g);
        for(int i=0; i<g.size(); i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};