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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        int cnt = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            st.push(tmp->val);
            cnt++;
            tmp = tmp->next;
        }
        for(int i = 0; i < cnt/2; i++){
            if(head->val != st.top())
                return false;
            head = head->next;
            st.pop();
        }

        return true;
    }
};