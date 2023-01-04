#include<algorithm>
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = tasks.size()+1;
        n = max(5, n);
        vector<int> dp(n, 0);
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        for(int i=5; i<dp.size(); i++){
            dp[i] = min(dp[i-2], dp[i-3])+1;
        }
        unordered_map<int, int> mp;
        for(auto e: tasks){
            mp[e]++;
        }
        int ans = 0;
        for(auto e: mp){
            if(e.second==1)return -1;
            ans += dp[e.second];
        }
        return ans;
    }
};