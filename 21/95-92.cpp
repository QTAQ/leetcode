/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *r;
        ListNode *t;
        if(l1&&l2){
            if(l1->val <= l2->val){
                r = l1; t = l1; l1 = l1->next;
            }
            else{
                r = l2; t=l2; l2=l2->next;
            }
        }
        else{
            return (l1)?l1:l2;
        }
        while(l1&&l2){
            if(l1->val <= l2->val){
                t->next = l1; l1=l1->next; t=t->next;
            }
            else{
                t->next = l2; l2=l2->next; t=t->next;
            }
        }
        t->next = (l1)?l1:l2;
        return r;
    }

};