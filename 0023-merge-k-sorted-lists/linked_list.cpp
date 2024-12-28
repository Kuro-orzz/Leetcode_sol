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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for(auto &it : lists){
            while(it != NULL){
                v.push_back(it->val);
                it = it->next;
            }
        }
        sort(v.begin(), v.end());       
        ListNode* ans = new ListNode();
        ListNode* t = ans;
        for(int x : v){
            ListNode* newNode = new ListNode(x);
            t->next = newNode;
            t = t->next;
        }
        return ans->next;
    }
};