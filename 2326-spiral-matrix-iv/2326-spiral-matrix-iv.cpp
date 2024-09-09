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
#define fi first
#define se second
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        pair<int, int> cur = {0, 0};
        while(head != NULL){
            while(head != NULL && cur.se < n && ans[cur.fi][cur.se] == -1){
                ans[cur.fi][cur.se] = head->val;
                head = head->next;
                cur.se++;
            }
            cur.fi++;
            cur.se--;
            while(head != NULL && cur.fi < m && ans[cur.fi][cur.se] == -1){
                ans[cur.fi][cur.se] = head->val;
                head = head->next;
                cur.fi++;
            }
            cur.fi--;
            cur.se--;
            while(head != NULL && cur.se >= 0 && ans[cur.fi][cur.se] == -1){
                ans[cur.fi][cur.se] = head->val;
                head = head->next;
                cur.se--;
            }
            cur.fi--;
            cur.se++;
            while(head != NULL && cur.fi >= 0 && ans[cur.fi][cur.se] == -1){
                ans[cur.fi][cur.se] = head->val;
                head = head->next;
                cur.fi--;
            }
            cur.fi++;
            cur.se++;
        }
        return ans;
    }
};