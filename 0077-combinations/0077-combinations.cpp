class Solution {
    template<typename T>
    void permutation(vector<T> v, int i, vector<T> curr, int k, vector<vector<T>> &ans){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int x=i; x<v.size(); x++){
            curr.push_back(v[x]);
            permutation(v, i+1, curr, k, ans);i++;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        vector<int> v(n), curr;
        for(int i=0; i<n; i++){
            v[i] = i+1;
        }
        vector<vector<int>> ans;
        permutation<int>(v, 0, curr, k, ans);
        return ans;
    }
};