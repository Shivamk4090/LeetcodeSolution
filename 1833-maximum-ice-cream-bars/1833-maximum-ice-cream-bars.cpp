class Solution {
public:
    int maxIceCream(vector<int>& v, int coins) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        sort(v.begin(), v.end());
        int ans = 0, i=0;
        while(coins>0 && i<v.size() && v[i]<=coins){
            coins -= v[i];
            ans++;
            i++;
        }
        return ans;
    }
};