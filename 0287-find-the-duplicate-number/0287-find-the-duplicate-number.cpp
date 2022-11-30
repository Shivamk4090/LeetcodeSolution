class Solution {
public:
    int findDuplicate(vector<int>& v) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int slow = v[0];
        int fast = v[v[0]];
        
        while(slow!=fast){
            slow = v[slow];
            fast = v[v[fast]];
        }
        slow = 0;
        while(slow!=fast){
            slow = v[slow];
            fast = v[fast];
        }
        return slow;        
    }
};