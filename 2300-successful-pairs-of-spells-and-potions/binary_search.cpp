class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int x : spells) {
            auto it = lower_bound(potions.begin(), potions.end(), ceil(success / (double)x));
            if (it == potions.end()) ans.push_back(0);
            else ans.push_back(m - (it - potions.begin()));
        }
        return ans;
    }
};