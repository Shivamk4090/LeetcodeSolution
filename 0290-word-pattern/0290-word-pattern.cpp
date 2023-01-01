class Solution {
public:
    bool wordPattern(string p, string s1) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        vector<string> s;
        stringstream ss(s1);
        string token;
        while (getline(ss, token, ' ')) {
            s.push_back(token);
        }
        if(s.size()!=p.size()) return false;
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;

        for(int i=0; i<p.size(); i++){
            if(mp.find(p[i]) != mp.end()){
                if(mp[p[i]] != s[i]) return false;
            }
            if(mp2.find(s[i]) != mp2.end())
                if(mp2[s[i]] != p[i]) return false;
            
            mp[p[i]] = s[i];
            mp2[s[i]] = p[i];
        }
        return true;
    }
};