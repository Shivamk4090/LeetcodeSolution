class Solution {
    int dfs(vector<int>& informTime, vector<vector<int>>* graph, int node, vector<bool> *vis){
        int v = 0;
        if((*vis)[node]==false){
            (*vis)[node] = true;
            for(int i=0; i<(*graph)[node].size(); i++){
                v = max(v, dfs(informTime, graph, (*graph)[node][i], vis));
            }
        }
        
        return v+informTime[node];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>* graph = new vector<vector<int>>(n, vector<int>());
        int head = -1;
        for(int i=0; i<manager.size(); i++){
            if(manager[i]!=-1)
                (*graph)[manager[i]].push_back(i); 
            else head = i;
        }
        vector<bool> *vis = new vector<bool>(n, false);
        int ans = dfs(informTime, graph, head, vis); 
        
        return  ans;
    }
};