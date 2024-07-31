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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        int prev = 0;
        int cnt = 0;
        while(head != NULL){
            if(cnt && head->next){
                if(head->val > prev && head->val > head->next->val)
                    v.push_back(cnt);
                else if(head->val < prev && head->val < head->next->val)
                    v.push_back(cnt);
            }
            prev = head->val;
            head = head->next;
            cnt++;
        }
        if(v.size() < 2) return {-1, -1};
        int mn = INT_MAX, mx = v[v.size()-1]-v[0];
        for(int i = 1; i < v.size(); i++)
            mn = min(mn, v[i]-v[i-1]);
        return {mn, mx};
    }
};