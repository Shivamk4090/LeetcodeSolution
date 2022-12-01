class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(k==1) return head;
        ListNode *temp = head, *tail;
        int count = 1;
        while(temp!=NULL && count<k){
            temp = temp->next;
            count++;
        }
        tail = temp;
        if(tail!=NULL){
            if(count==k){
                ListNode *prev=NULL, *curr=head, *nxt = head->next, *smaller=tail->next;
                while(curr!=smaller){
                    nxt = curr->next;
                    curr->next=prev;
                    prev = curr;
                    curr = nxt;
                }
                ListNode *newHead  = prev;
                ListNode *newTail = head;
                newTail->next = reverseKGroup(smaller, k);
                return newHead;
            }else{
                return head;
            }
        }else{
            return head;
        }
        
    }
};
