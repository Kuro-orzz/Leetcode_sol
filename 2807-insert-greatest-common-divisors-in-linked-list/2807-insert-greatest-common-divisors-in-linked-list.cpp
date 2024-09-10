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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p = head;
        while(p->next){
            ListNode *newNode = new ListNode(__gcd(p->val, p->next->val));
            newNode->next = p->next;
            p->next = newNode;
            p = p->next->next;
        }
        return head;
    }
};