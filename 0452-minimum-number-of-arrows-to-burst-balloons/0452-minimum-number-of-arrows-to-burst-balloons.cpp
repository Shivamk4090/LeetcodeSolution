class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        sort(p.begin(), p.end());
        int ans = 1;
        int y = p[0][1];
        for(int i=1; i<p.size(); i++){
            if(p[i][0]<=y){
                y = min(y, p[i][1]);
            }else{
                ans++;
                y = p[i][1];
            }     
        }
        return ans;
    }
};