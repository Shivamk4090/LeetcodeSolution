class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode* mid = NULL,*slow=head, *fast=head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // mid  
        mid = slow;
        ListNode* head2=slow->next, *prev=NULL, *curr=head2;
        
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        head2 = prev;
        mid->next = NULL;
        ListNode* head1 = head;
        
        // rearrange head1 & head2
        while(head1 != NULL && head2!=NULL){
            
            ListNode* temp1 = head1->next, *temp2 = head2->next;
            
            head2->next = head1->next;
            head1->next = head2;
            
            head1 = temp1;
            head2 = temp2 ;
            
        }
        
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