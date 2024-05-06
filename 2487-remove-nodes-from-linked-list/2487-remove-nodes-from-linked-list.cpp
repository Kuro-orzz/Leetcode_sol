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
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode* p = head;
        while(p){
            while(v.size() && v.back() < p->val)
                v.pop_back();
            v.push_back(p->val);
            p = p->next;
        }
        reverse(v.begin(), v.end());
        ListNode* ans = new ListNode();
        ListNode* tmp = ans;
        while(v.size()){
            ListNode* newNode = new ListNode(v.back());
            v.pop_back();
            tmp->next = newNode;
            tmp = tmp->next;
        }
        return ans->next;
    }
};