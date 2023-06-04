class Solution {
    vector<bool> vis;
    int c = 0;
    int n;
    void dfs(int i, vector<vector<int>>&g){
        if(!vis[i]){
            vis[i] = true;
            for(int j=0; j<n; j++){
                if(g[i][j]==1 && !vis[j])dfs(j, g);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vis = vector<bool>(n); 
        for(int i=0; i<n; i++){
            if(!vis[i]){
                c++;
                dfs(i, isConnected);
            }
        }
        return c;
    }
};