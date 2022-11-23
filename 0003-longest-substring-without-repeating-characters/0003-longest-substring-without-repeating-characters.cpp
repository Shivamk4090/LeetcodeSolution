class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i =0;
        int j =0;
        int n = s.size();
        
        int ans = 0;
        set<char> st;
        while(j<n){
            if(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }else{
                if(j-i+1>ans)ans=j-i+1;
                st.insert(s[j]);
                j++;
            }
            
        }
        return ans;
    }
};