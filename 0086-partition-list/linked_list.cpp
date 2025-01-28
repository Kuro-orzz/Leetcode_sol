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
    ListNode* partition(ListNode* head, int x) {
        vector<pair<int, int>> v;
        ListNode* tmp = head;
        int i = 0;
        while(tmp){
            v.push_back({tmp->val, i++});
            tmp = tmp->next;
        }
        sort(v.begin(), v.end());
        auto it = lower_bound(v.begin(), v.end(), make_pair(x, 0));
        auto cmp = [&](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        };
        sort(v.begin(), it, cmp);
        sort(it, v.end(), cmp);
        tmp = head;
        i = 0;
        while(tmp){
            tmp->val = v[i++].first;
            tmp = tmp->next;
        }
        return head;
    }
};