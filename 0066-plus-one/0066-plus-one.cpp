class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int carry = 1;
        vector<int> ans;
        for(int i=v.size()-1; i>=0; i--){
            v[i] += carry;
            ans.push_back(v[i]%10);
            carry = v[i]/10;
        }
        if(carry)ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};