class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> A(n, vector<int>(n));
        int T,B,L,R,dir;
        T=0;
        B=A.size()-1;
        L=0;
        R=A[0].size()-1;
        dir=0;
        int i;
        int num=1;
        while(T<=B && L<=R)
        {
            if(dir==0)
            {
                for(i=L;i<=R;i++){
                    A[T][i] = num;
                    num++;
                }
                T++;
            }
            else if(dir==1)
            {
                for(i=T;i<=B;i++){
                    A[i][R] = num;
                    num++;
                }
                R--;
            }
            else if(dir==2)
            {
                for(i=R;i>=L;i--){
                    A[B][i] = num;
                    num++;
                }
                B--;
            }
            else if(dir==3)
            {
                for(i=B;i>=T;i--){
                    A[i][L] = num;
                    num++;
                }
                L++;
            }
            dir=(dir+1)%4;
        }
        return A; 
    }
};