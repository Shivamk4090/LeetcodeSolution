class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int ans = 0;
        int s = arr.size();
        
        if(arr.size()==1)
            if(arr[0]==0 && n<=1)  return true;
            else if(arr[0]==1 && n==0) return true;
            else return false;
        
        if(arr.size()>1){
            if(arr[0] == 0 && arr[1] == 0){
                ans++;
                arr[0] = 1;
            }
            if(arr[s-1]==0 && arr[s-2]==0){
                ans++;
                arr[s-1] = 1;
            }
        }
        for(int i=1; i<arr.size()-1; i++){
            if(arr[i]==0 && arr[i+1] != 1 && arr[i-1] != 1){
                ans++;
                arr[i] = 1;
            }
        }
        if(ans<n) return false; 
        else return true;
    }
};