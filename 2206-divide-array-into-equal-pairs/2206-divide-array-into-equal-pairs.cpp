class Solution {
public:
    bool divideArray(vector<int>& v) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        map<int, int> mp;
        for(auto e:v){
            mp[e]++;
        }
        for(auto e:mp){
            if(e.second%2!=0) return false;
        }
        return true;
    }
};