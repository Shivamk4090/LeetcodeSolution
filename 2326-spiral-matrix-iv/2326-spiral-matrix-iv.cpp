class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> A(m, vector<int>(n));
        int T,B,L,R,dir;
        T=0;
        B=A.size()-1;
        L=0;
        R=A[0].size()-1;
        dir=0;
        int i;
        while(T<=B && L<=R)
        {
            if(dir==0)
            {
                for(i=L;i<=R;i++){
                    if(head!=NULL){
                        A[T][i] = head->val;
                        head = head->next;
                    }else{
                        A[T][i] = -1;
                    }
                }
                T++;
            }
            else if(dir==1)
            {
                for(i=T;i<=B;i++){
                    if(head!=NULL){
                        A[i][R] = head->val;
                        head = head->next;
                    }else{
                        A[i][R] = -1;
                    }
                }
                R--;
            }
            else if(dir==2)
            {
                for(i=R;i>=L;i--){
                    if(head!=NULL){
                        A[B][i] = head->val;
                        head = head->next;
                    }else{
                        A[B][i] = -1;
                    }
                }
                B--;
            }
            else if(dir==3)
            {
                for(i=B;i>=T;i--){
                    if(head!=NULL){
                        A[i][L] = head->val;
                        head = head->next;
                    }else{
                        A[i][L] = -1;
                    }
                }
                L++;
            }
            dir=(dir+1)%4;
        }
        return A; 
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */