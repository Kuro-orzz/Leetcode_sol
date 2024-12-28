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
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        while(head != NULL){
            st.push(head->val);
            head = head->next;
        }
        ListNode* ans = new ListNode();
        ListNode* tmp = ans;
        while(!st.empty()){
            ListNode* newNode = new ListNode(st.top());
            tmp->next = newNode;
            tmp = tmp->next;
            st.pop();
        }
        return ans->next;
    }
};