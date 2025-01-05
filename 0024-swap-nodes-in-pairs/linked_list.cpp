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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* t = head;
        head = head->next;
        t->next = head->next;
        head->next = t;
        while(t->next && t->next->next){
            ListNode* tmp = t->next;
            t->next = tmp->next;
            t = t->next;
            tmp->next = t->next;
            t->next = tmp;
            t = t->next;
        }
        return head;
    }
};