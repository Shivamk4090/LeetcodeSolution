class Solution {
public:
    int maxIceCream(vector<int>& v, int coins) {
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