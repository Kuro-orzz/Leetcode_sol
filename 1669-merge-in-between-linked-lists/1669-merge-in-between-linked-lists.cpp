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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ans = list1;
        for(int i = 0; i < a-1; i++)
            list1 = list1->next;
        ListNode* tmp = list1;
        for(int i = 0; i <= b-a; i++)
            tmp = tmp->next;
        list1->next = list2;
        while(list1->next != NULL)
            list1 = list1->next;
        list1->next = tmp->next;
        return ans;
    }
};