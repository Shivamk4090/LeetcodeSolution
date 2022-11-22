class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(v.begin(), v.end());
        int i = 0;
        int n = v.size();
        while(i<n && v[i]<=0){
            i++;
        }
        int j = 1;
        while(i<n){
            if(i>0 && v[i]==v[i-1]){
                i++;continue;
            }
            if(v[i]!=j){
                return j;
            }
            i++;j++;
        }
        return j;
    }
};