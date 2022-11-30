class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = 0;
        int fast = 0;
        while(1){
            slow = v[slow];
            fast = v[v[fast]];
            if(slow==fast) break;
        }
        fast = 0;
        while(1){
            slow = v[slow];
            fast = v[fast];
            if(slow==fast) break;
        }
        return fast;        
    }
};