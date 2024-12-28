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
    void reorderList(ListNode* head) {
        deque<int> q;
        ListNode* tmp = head;
        while(tmp != NULL){
            q.push_front(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        int cnt = 0;
        while(!q.empty()){
            if(cnt % 2 == 0){
                tmp->val = q.back();
                tmp = tmp->next;
                q.pop_back();
                cnt++;
            }
            else{
                tmp->val = q.front();
                tmp = tmp->next;
                q.pop_front();
                cnt++;
            }
        }
    }
};