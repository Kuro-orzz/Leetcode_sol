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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a = "";
        string b = "";
        while (l1 != nullptr) {
            a += to_string(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            b += to_string(l2->val);
            l2 = l2->next;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while(a.length() < b.length())
            a = '0' + a;
        while(a.length() > b.length())
            b = '0' + b;
        string res = "";
        int nho = 0;
        for(int i = a.length()-1; i >= 0; i--){
            int x = a[i]-'0'+b[i]-'0'+nho;
            nho = 0;
            if(x < 10)
                res = (char)(x + '0') + res;
            else{
                nho = 1;
                res = (char)(x%10+'0') + res;
            }
        }
        if(nho)
            res = '1'+res;
        ListNode* head = new ListNode(res[res.length()-1]-'0');
        ListNode* tmp = head;
        for(int i = res.length()-2; i >= 0; i--) {
            tmp->next = new ListNode(res[i]-'0');
            tmp = tmp->next;
        }
        return head;
    }
};