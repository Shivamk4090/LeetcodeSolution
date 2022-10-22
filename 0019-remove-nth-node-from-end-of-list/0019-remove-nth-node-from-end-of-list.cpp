class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head, *fast = head;
        
        while(n>0){
            fast = fast->next;
            n--;
        }
        
        if(fast==NULL) return head->next;
        
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        if(slow->next!=NULL)
        slow->next = slow->next->next;        
        
        return head;
    }
};
