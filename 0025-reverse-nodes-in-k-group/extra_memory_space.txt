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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode* tmp = head;
        while(tmp){
            v.push_back(tmp);
            tmp = tmp->next;
        }
        for(int i = 0; i < v.size()/k; i++){
            for(int j = 0; j < k/2; j++)
                swap(v[i*k+j], v[(i+1)*k-j-1]);
        }
        for(int i = 0; i < v.size()-1; i++)
            v[i]->next = v[i+1];
        v[v.size()-1]->next = NULL;
        head = v[0];
        return head;
    }
};