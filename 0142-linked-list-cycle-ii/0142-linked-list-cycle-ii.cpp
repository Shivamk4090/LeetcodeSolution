class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_set<ListNode*> st;
        while(head!=NULL){
            if(st.find(head)!=st.end()) return head;
            st.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/