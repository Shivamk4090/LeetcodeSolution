class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP=nums[0], maxN=nums[0];
        
        int ans = nums[0];
        
        for(auto i=1; i<nums.size(); i++){
           if(nums[i]<0)swap(maxP, maxN);

            maxP = max(nums[i], maxP*nums[i]);
            maxN = min(nums[i], maxN*nums[i]);
            
            if(maxP>ans)ans = maxP;
        }
        
        return ans;
        
    }
};