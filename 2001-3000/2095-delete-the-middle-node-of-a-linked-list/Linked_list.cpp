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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;
        while (true) {
            if (fast->next && fast->next->next && fast->next->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                slow->next = slow->next->next;
                break;
            }
        }
        return head;
    }
};