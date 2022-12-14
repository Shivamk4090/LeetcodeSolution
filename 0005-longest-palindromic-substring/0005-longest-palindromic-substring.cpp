class Solution {
public:
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)), choice(n, vector<int>(n, -1));
        // choice = 1, 2, 3
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)dp[i][j] = 1;
            }
        }
        for(int i=n-2; i>=0 ; i--){
            for(int j=i+1; j<n; j++){
                // not taken
                dp[i][j] = dp[i+1][j];
                choice[i][j] = 1;
                if(dp[i][j-1]>dp[i][j]){
                    dp[i][j] = dp[i][j-1];
                    choice[i][j] = 2;
                }
                //taken
                if(s[i]==s[j] && (choice[i+1][j-1]==3 || choice[i+1][j-1]==-1)){
                    dp[i][j] = max(dp[i][j], 2+dp[i+1][j-1]);
                    choice[i][j] = 3;
                }
            }
        }
        int x=1001, y=-1;
        int i = 0, j = n-1;
        while(j>=i){
            if(choice[i][j]==1){
                i++;
            }
            else if(choice[i][j]==2){
                j--;
            }
            else{
                x = min(i, x);
                y = max(j, y);
                i++;
                j--;
            }
        }
        string ans = "";
        if(dp[0][n-1]==1){
            ans.append(1, s[0]);
            return ans;
        }
        return s.substr(x, y-x+1);
    }
};