class Solution {
public:
    int minDistance(string w1, string w2) {
        int r = w1.size();
        int c = w2.size();
        
        vector<vector<int>> v(r+1, vector<int>(c+1));
        for(int i=0; i<=c; i++) v[0][i] = i;
        for(int i=0; i<=r; i++) v[i][0] = i;
        
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                if(w1[i-1]==w2[j-1]){
                    v[i][j] = v[i-1][j-1];
                }else{
                    // insert, replace, delete
                    v[i][j] = 1 + min(v[i][j-1], min(v[i-1][j-1], v[i-1][j]));
                }
            }
        }
        return v[r][c];
    }
};