class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int ans = 0;
        for(int j=0; j<s[0].size(); j++){
            for(int i=1; i<s.size(); i++){
                if(s[i][j]<s[i-1][j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};