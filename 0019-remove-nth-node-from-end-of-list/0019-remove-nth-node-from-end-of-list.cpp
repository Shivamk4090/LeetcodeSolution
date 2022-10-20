class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* curr = head;
        while(curr != NULL){
            size++;
            curr = curr->next;
        }
        
        if(size==1) return NULL;
        if(size==n) return head->next;
        
        
        int ith = size-n+1;
        int curpos = 0;
        curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            curpos++;
            if(curpos==ith){
                ListNode* temp = curr;
                prev->next = curr->next;
                delete temp;
                break;
            }
            prev =  curr;
            curr = curr->next;
        }        
        
        return head;
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