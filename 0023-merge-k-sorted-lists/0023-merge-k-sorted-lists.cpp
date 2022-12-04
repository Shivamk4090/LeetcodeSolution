class Solution {
    ListNode *mergeTwoLists(ListNode *head, ListNode *head2)
    {
        if (head == NULL && head2 == NULL)
            return NULL;
        if (head == NULL && head2 != NULL)
        {
            return head2;
        }
        if (head != NULL && head2 == NULL)
        {
            return head;
        }
        ListNode *ansHead = NULL, *ansTail = NULL;
        while (head != NULL && head2 != NULL)
        {

            if (head->val <= head2->val)
            {
                ListNode *newNode = new ListNode(head->val);

                if (ansHead == NULL)
                {
                    ansHead = newNode;
                    ansTail = newNode;
                }
                else
                {
                    ansTail->next = newNode;
                    ansTail = ansTail->next;
                }
                head = head->next;
            }
            else
            {
                ListNode *newNode = new ListNode(head2->val);
                if (ansHead == NULL)
                {
                    ansHead = newNode;
                    ansTail = newNode;
                }
                else
                {
                    ansTail->next = newNode;
                    ansTail = ansTail->next;
                }
                head2 = head2->next;
            }
        }

        if (head)
        {
            ansTail->next = head;
        }
        else
        {
            ansTail->next = head2;
        }
        return ansHead;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = lists.size();
        if(n==0) return nullptr;
        while(n>1){
            for(int i=0; i<n/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
            }
            n = (n+1)/2;
        }
        return lists.front();
    }
};

