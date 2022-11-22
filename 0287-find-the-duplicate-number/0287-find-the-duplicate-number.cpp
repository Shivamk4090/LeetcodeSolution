// Tc -> O(n)  Sc->O(n || 10^5)
class Solution {
public:
    int findDuplicate(vector<int>& v) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> mp(1e5+1, 0);
        for(auto e: v){
            mp[e]++;
            if(mp[e]>1){
                return e;
            }
        }
        
        return -1;
    }
};