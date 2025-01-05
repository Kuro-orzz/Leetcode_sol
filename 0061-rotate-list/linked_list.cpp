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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        vector<int> v;
        ListNode* t = head;
        while(t){
            v.push_back(t->val);
            t = t->next;
        }
        rotate(v.begin(), v.begin()+v.size()-k%v.size(), v.end());
        t = head;
        int i = 0;
        while(t){
            t->val = v[i++];
            t = t->next; 
        }
        return head;
    }
};