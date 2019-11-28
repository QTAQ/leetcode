class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> m;
        while(head){
            if(m.find(head) != m.end()) return head;
            m[head] = true;
            head = head->next;
        }
        return NULL;
    }
};