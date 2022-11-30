class Solution {
public:
    Node* copyRandomList(Node* head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        Node* temp=head;
        unordered_map<Node*, Node*> mp;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/