// 2 things are changing => length of both string with optimal answer for evry state {i, j}

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int r = t1.size(), c = t2.size();
        vector<vector<int>> v(r, vector<int>(c));
        
        v[0][0]= (t1[0]==t2[0]);
        for(int i=1; i<c; i++){
            if(t2[i]==t1[0]){
                v[0][i] = 1;
            }
            else{
                v[0][i] = max(v[0][i-1], 0);
            }
        }
        for(int i=1; i<r; i++){
            if(t1[i]==t2[0]){
                v[i][0] = 1;
            }else{
                v[i][0] = max(v[i-1][0], 0);
            }
        }
        for(int i=1; i<r;i++){
            for(int j=1; j<c; j++){
                if(t1[i]==t2[j]){
                    v[i][j]= 1 + v[i-1][j-1];
                }else{
                    v[i][j] = max(v[i-1][j], v[i][j-1]);
                }
            }
        }
        return v[r-1][c-1];
    }
};