class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int t = 0, i=0, j=0;
        while(i<word1.size() && j<word2.size()){
            if(t==0){
                ans.push_back(word1[i]);
                i++;
                t=1;
            }else{
                ans.push_back(word2[j]);
                j++;
                t=0;
            }
        }
        if(i<word1.size()) ans.append(word1.substr(i));
        if(j<word2.size()) ans.append(word2.substr(j));

        return ans;
    }
};