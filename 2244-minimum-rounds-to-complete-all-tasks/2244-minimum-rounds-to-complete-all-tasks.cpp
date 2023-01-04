#include<algorithm>
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(auto e: tasks){
            mp[e]++;
        }
        int ans = 0;
        for(auto e: mp){
            if(e.second==1)return -1;
            if(e.second%3==0)ans+= (e.second/3);
            else ans += (e.second/3+1);
        }
        return ans;
    }
};