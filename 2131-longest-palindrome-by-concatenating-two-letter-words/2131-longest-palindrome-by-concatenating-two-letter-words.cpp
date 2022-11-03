class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> mp;
        for(auto e : words) mp[e]++;
        
        bool odd = 0;
        
        for(auto e:mp){
            string rs = "";
            rs +=  e.first[1];
            rs +=  e.first[0];
            if(e.first==rs && mp[e.first]%2!=0){
                if(odd==1){
                    ans += 2*(mp[e.first]-1);
                }else{
                    ans += 2*(mp[e.first]);
                }
                odd = 1;

            }
            else if (mp.find(rs)!=mp.end()){
                ans += 2*min(mp[e.first], mp[rs]);
            }
        }
        
        return ans;
    }
};