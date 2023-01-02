class Solution {
public:
    bool detectCapitalUse(string word) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        bool isSmall=false, isCapital=false;
        int capIndex = -1;
        
        for(int i=0; i<word.size(); i++){
            if(word[i]>='a' && word[i]<='z') isSmall=true;
            if(word[i]>='A' && word[i]<='Z'){
                isCapital=true;
                capIndex = i;
            }
        }
        
        if(isSmall && !isCapital) return true;
        if(!isSmall && isCapital) return true;
        if(isSmall && isCapital && capIndex==0) return true;

        return false;
    }
};