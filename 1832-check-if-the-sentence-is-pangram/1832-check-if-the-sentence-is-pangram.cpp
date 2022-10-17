class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26, 0);
        for(auto e: sentence){
            v[e-'a']++;
        }
        for(auto e : v){
            if(e==0) return false;
        }
        return true;
    }
};