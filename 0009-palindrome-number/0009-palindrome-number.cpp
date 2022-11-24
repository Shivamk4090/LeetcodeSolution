class Solution {
public:
    
    bool isPalindrome(int x) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(x<0) return false;
        string s = to_string(x);
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
};