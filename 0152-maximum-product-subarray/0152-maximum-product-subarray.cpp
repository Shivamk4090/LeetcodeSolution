class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int j =0;
        while(j<nums.size()&& nums[j]==0 )j++;
        if(j==nums.size()) return 0;
        int maxP=nums[j], maxN=nums[j];
        
        int ans = nums[j];
        
        for(auto i=j+1; i<nums.size(); i++){
           if(nums[i]<0)swap(maxP, maxN);

            maxP = max(nums[i], maxP*nums[i]);
            maxN = min(nums[i], maxN*nums[i]);
            
            if(maxP>ans)ans = maxP;
        }
        
        return ans;
        
    }
};