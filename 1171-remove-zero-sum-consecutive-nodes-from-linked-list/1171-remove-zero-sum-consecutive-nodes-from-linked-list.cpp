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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int a[1006];
        memset(a, 0, sizeof(a));
        int cnt = 1;
        while(head != NULL){
            a[cnt] = head->val;
            cnt++;
            head = head->next;
        }
        unordered_map<int, int> mp;
        int prefix[1001];
        prefix[0] = 0;
        vector<pair<int, int>> v;
        for(int i = 1; i < cnt; i++){
            prefix[i] = prefix[i-1]+a[i];
            if(prefix[i] == 0)
                v.push_back({1, i});
            if(mp[prefix[i]] > 0)
                v.push_back({mp[prefix[i]]+1, i});
            mp[prefix[i]] = i;
        }
        sort(v.begin(), v.end());
        int tmp = 0;
        for(auto x : v){
            if(x.first > tmp){
                for(int i = x.first; i <= x.second; i++)
                    a[i] = 1001;
                tmp = x.second;
            }
        }
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        for(int i = 1; i < cnt; i++){
            if(a[i] != 1001){
                ListNode* newNode = new ListNode(a[i]);
                ptr->next = newNode;
                ptr = ptr->next;
            }
        }
        ans = ans->next;
        return ans;
    }   
};