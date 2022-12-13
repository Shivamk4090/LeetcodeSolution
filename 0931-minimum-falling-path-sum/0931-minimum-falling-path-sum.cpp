class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> dp(v.size(), vector<int>(v.size()));
        
        //base case
        dp[0] = v[0];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = dp[i-1][j]+v[i][j];
                if(j-1>=0)
                    dp[i][j] = min(dp[i-1][j-1]+v[i][j], dp[i][j]);
                if(j+1<n)
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1]+v[i][j]);
            }
        }
        
        int ans = dp[n-1][0];
        for(int i=1; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        
        return ans;
    }
};