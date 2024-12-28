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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode *tmp = head;
        while(tmp != NULL){
            sz++;
            tmp = tmp->next;
        }
        if(sz == 1){
            head = NULL;
            return head;
        }
        if(sz == n){
            head = head->next;
            return head;
        }
        tmp = head;
        for(int i = 0; i < sz-n-1; i++)
            tmp = tmp->next;
        tmp->next = tmp->next->next;
        return head;
    }
};