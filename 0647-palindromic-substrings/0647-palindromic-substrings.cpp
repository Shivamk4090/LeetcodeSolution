class Solution {
public:
    int countSubstrings(string s) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)), ch(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)dp[i][j] = 1;
                if(i>=j)ch[i][j] = 1;
            }
        }
        for(int i=n-2; i>=0 ; i--){
            for(int j=i+1; j<n; j++){
                dp[i][j] = dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                if(s[i]==s[j] && ch[i+1][j-1]==1){
                    dp[i][j] = dp[i][j] + 1;
                    ch[i][j] = 1;
                }
            }
        }
        return dp[0][n-1];
    }
};