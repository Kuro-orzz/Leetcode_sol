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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* k = ans;
        ListNode* t = head->next;
        int sum = 0;
        while(t != NULL){
            if(t->val == 0){
                ListNode* newNode = new ListNode(sum);
                k->next = newNode;
                k = k->next;
                sum = 0;
            }
            else
                sum += t->val;
            t = t->next;
        }
        return ans->next;
    }
};