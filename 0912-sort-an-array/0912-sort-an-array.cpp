// [5,2,3,1] -> [1,2,3,4,5]
class Solution {
public:
    // ismein do array hai -> [low, mid], [mid+1, high]
    void merge(vector<int> &nums, int l, int mid, int h){
        int i = l, j=mid+1;
        vector<int> ans;
        while(i<=mid && j<=h){
            if(nums[i]<=nums[j]){
                ans.push_back(nums[i]);
                i++;
            }else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=h){
            ans.push_back(nums[j]);
            j++;
        }
        for(int i=0; i<ans.size(); i++){
            nums[l] = ans[i];
            l++;
        }
    }
    void mergeSort(vector<int> &nums, int l, int h){
        if(l<h){
            int mid = (l+h)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, h);
            merge(nums, l, mid, h);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};