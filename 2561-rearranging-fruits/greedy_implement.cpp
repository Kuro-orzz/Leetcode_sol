class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        map<int, int> mp1, mp2, mp;
        for (int x : basket1) mp[x]++, mp1[x]++;
        for (int x : basket2) mp[x]++, mp2[x]++;
        for (auto it : mp) {
            if (it.second % 2 == 1) return -1;
        }
        int mn1 = (*mp1.begin()).first;
        int mn2 = (*mp2.begin()).first;
        vector<int> need_swap1, need_swap2;
        for (auto [x, y] : mp) {
            for (int i = 0; i < mp1[x] - y/2; i++) need_swap1.push_back(x);
            for (int i = 0; i < mp2[x] - y/2; i++) need_swap2.push_back(x);
        }
        long long ans = 0;
        reverse(need_swap2.begin(), need_swap2.end());
        for (int i = 0; i < need_swap1.size(); i++) {
            ans += min(min(mn1, mn2) * 2, min(need_swap1[i], need_swap2[i]));
        }
        return ans;
    }
};