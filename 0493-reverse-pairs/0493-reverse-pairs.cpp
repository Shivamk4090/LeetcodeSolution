class Solution {
    int merge(vector<int>& arr, int l, int mid, int r)
    {
        int total = 0;
        int j = mid+1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && arr[i] > 2LL * arr[j]) {
              j++;
            }
            total += (j - (mid + 1));
        }
        
        int i = l;
        j = mid+1;
        vector<int> ans(r-l+1);
        int p = 0;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                ans[p]= arr[i];
                i++;
                p++;
            }else{
                ans[p]= arr[j];
                j++;
                p++;
            }
        }
        while(i<=mid){
            ans[p] = arr[i];
            i++;
            p++;
        }
        while(j<=r){
            ans[p] = arr[j];
            j++;
            p++;
        }
        
        for(int i=0;i<r-l+1;i++){
            arr[l+i] = ans[i];
        }
        return total;
    }

    int solve(vector<int>&nums, int l, int r){
        // postorder traversal 
        if(l>=r) return 0; 
        int mid = (l+r)/2;
        int inv = solve(nums, l, mid);
        inv += solve(nums, mid+1, r);
        inv += merge(nums, l, mid, r);
        return inv;
    }
public:
    int reversePairs(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};