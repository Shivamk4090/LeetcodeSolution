class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = m.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[j][n-i-1] = m[i][j];
            }
        }
        m =  ans;
    }
};