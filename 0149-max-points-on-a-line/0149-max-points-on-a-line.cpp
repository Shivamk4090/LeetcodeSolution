class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int ans = 0;
        for(int i=0; i<p.size()-1; i++){
            unordered_map<double, int> mp;
            int temp = 0;
            for(int j=i+1; j<p.size(); j++){
                int dely = p[j][1]-p[i][1];
                int delx = p[j][0]-p[i][0];
                if(delx==0){
                    temp++;
                    if(temp>ans)ans=temp;
                }else{
                    double slope = (double)dely/(double)delx;
                    mp[slope]++;
                    if(mp[slope]>ans)ans = mp[slope];                    
                }
            }
        }
        return ans+1;
    }
};