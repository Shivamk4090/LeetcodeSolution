class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& v1) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> ans;
        v.push_back(v1);
        sort(v.begin(), v.end());
        vector<int> temp = v[0];
        for(int i=1; i<v.size(); i++){
            // merge interval
            if(v[i][0]<= temp[1]){
                temp[1] = max(temp[1], v[i][1]);
            }else{
                //cuurent interval can't be merged with the temp
                ans.push_back(temp);
                temp = v[i];
            }
        }
        ans.push_back(temp);
        return ans;
        
    }
};