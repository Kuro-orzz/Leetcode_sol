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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        while(list1 != NULL && list2 != NULL){
            ListNode* newNode = new ListNode();
            if(list1->val > list2->val){
                newNode->val = list2->val;
                list2 = list2->next;
            }
            else{
                newNode->val = list1->val;
                list1 = list1->next;
            }
            ptr->next = newNode;
            ptr = ptr->next;
        }
        while(list1 != NULL){
            ListNode* newNode = new ListNode();
            newNode->val = list1->val;
            list1 = list1->next;
            ptr->next = newNode;
            ptr = ptr->next;
        }
        while(list2 != NULL){
            ListNode* newNode = new ListNode();
            newNode->val = list2->val;
            list2 = list2->next;
            ptr->next = newNode;
            ptr = ptr->next;
        }
        ans = ans->next;
        return ans;
    }
};