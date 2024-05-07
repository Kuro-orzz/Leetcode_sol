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
    ListNode* doubleIt(ListNode* head) {
        string s = "";
        while(head){
            s += head->val+'0';
            head = head->next;
        }
        string t = "";
        bool memo = false;
        for(int i = s.size()-1; i >= 0; i--){
            int tmp = 2*(s[i]-'0')+(memo ? 1 : 0);
            t += tmp%10+'0';
            if(tmp/10)
                memo = true;
            else
                memo = false;
        }
        if(memo)
            t += '1';
        ListNode* ans = new ListNode();
        ListNode* p = ans;
        while(t != ""){
            ListNode* newNode = new ListNode(t.back()-'0');
            p->next = newNode;
            p = p->next;
            t.pop_back();
        }
        return ans->next;
    }
};