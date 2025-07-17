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
    int ans = 0, t = 1;

    void dfs(ListNode* cur) {
        if (!cur) return;
        else dfs(cur->next);
        ans += t * cur->val;
        t *= 2;
    }

    int getDecimalValue(ListNode* head) {
        dfs(head);
        return ans;
    }
};