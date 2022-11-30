class Solution {
public:
    int findDuplicate(vector<int>& v) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int slow = 0;
        int fast = 0;
        
        while(1){
            slow = v[slow];
            fast = v[v[fast]];
            if(slow==fast) break;
        }
        
        fast = 0;
        while(slow!=fast){
            slow = v[slow];
            fast = v[fast];
        }
        return fast;        
    }
};