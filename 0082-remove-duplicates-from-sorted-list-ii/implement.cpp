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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        while (head != NULL) {
            mp[head->val]++;
            head = head->next;
        }
        vector<int> v;
        for (auto &it : mp) {
            if (it.second > 1) continue;
            v.push_back(it.first);
        }
        if (v.size()) head = new ListNode();
        ListNode *ptr = head;
        for (int i = 0; i < v.size(); i++) {
            ptr->val = v[i];
            if (i+1 != v.size()) {
                ptr->next = new ListNode();
                ptr = ptr->next;
            }
        }
        return head;
    }
};