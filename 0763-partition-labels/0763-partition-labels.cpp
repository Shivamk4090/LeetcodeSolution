class Solution {
public:
    vector<int> partitionLabels(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> v(26);
        for(int i=0; i<s.size(); i++){
            int j = (int)s[i] - (int)'a';
            if(v[j].size()==0){
                v[j].push_back(i);
                v[j].push_back(i);
               
            }else{
                v[j][0] = min(v[j][0], i);
                v[j][1] = max(v[j][1], i); 
            }
        }
        vector<vector<int>> v1;
        for(int i=0; i<v.size(); i++){
            if(v[i].size()!=0){
                v1.push_back(v[i]);
            }
        }
        vector<vector<int>> ans;
        sort(v1.begin(), v1.end());
        vector<int> temp = v1[0];
        for(int i=0; i<v1.size(); i++){
            if(v1[i][0]<= temp[1]){
                temp[1] = max(temp[1], v1[i][1]);
            }else{
                ans.push_back(temp);
                temp = v1[i];
            }
        }
        ans.push_back(temp);
        vector<int> res;
        for(int i=0; i<ans.size(); i++){
            res.push_back(ans[i][1]-ans[i][0]+1);            
        }
        return res;
    }
};