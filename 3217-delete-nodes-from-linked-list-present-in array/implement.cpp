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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (head != NULL && s.count(head->val)) {
            head = head->next;
        }
        ListNode* ptr = head;
        while (ptr != NULL && ptr->next != NULL) {
            if (s.count(ptr->next->val)) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};