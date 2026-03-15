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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ptr = head;
        for (int i = 0; i < left - 1; i++) {
            ptr = ptr->next;
        }
        ListNode *tmp = ptr;
        stack<int> st;
        for (int i = left; i <= right; i++) {
            st.push(ptr->val);
            ptr = ptr->next;
        }
        for (int i = left; i <= right; i++) {
            tmp->val = st.top();
            st.pop();
            tmp = tmp->next;
        }
        return head;
    }
};