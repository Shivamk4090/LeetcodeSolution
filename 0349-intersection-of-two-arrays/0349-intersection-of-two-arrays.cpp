class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_set<int> st, ans;
        for(auto e: nums1){
            st.insert(e);
        }
        vector<int> ansv;
        for(auto e: nums2){
            if(st.find(e)!=st.end()){
                ans.insert(e);
            }
        }
        for(auto e: ans){
            ansv.push_back(e);
        }
        return ansv;
    }
};