class Solution {
    bool ans = false;
    void dfs(int node, vector<bool>& vis, vector<vector<int>> &g, int des){
        vis[node] = true;
        if(des==node){
            ans  = true;
            return;
        }
        for(auto n:g[node]){
            if(vis[n]==false)
                dfs(n, vis, g, des);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int des) {
        vector<vector<int>> g(n);
        for(int i=0; i<edges.size(); i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        dfs(source, vis, g, des);
        return ans;
    }
};