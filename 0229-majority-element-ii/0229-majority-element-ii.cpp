class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int t = nums.size()/3;
        vector<int> ans;
        for(auto e: mp){
            if(e.second>t)ans.push_back(e.first);
        }
        return ans;
    }
};