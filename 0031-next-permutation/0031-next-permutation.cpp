class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int fluc = -1;
        int n = v.size();
        // find the fluctuatuin point
        for(int i=n-1; i>0; i--){
            if(v[i-1]<v[i]){
                fluc = i-1;
                break;
            }
        }
        
        // case of decreasing sequence
        if(fluc == -1){
            int i = 0;
            int j = n-1;
            while(i<j){
                swap(v[i], v[j]);
                i++;
                j--;
            }
            return;
        }
        
        int j = fluc+1;
        // check if any no after fluc+1
        for(int i=fluc+1; i<n; i++){
            if(v[i]>v[fluc] && v[i]<v[fluc+1]){
                j = i;
            }
        }
        swap(v[fluc], v[j]);
        sort(v.begin()+fluc+1, v.end());
    }
};