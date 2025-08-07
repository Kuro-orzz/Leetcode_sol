class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, l = 0;
        unordered_map<int, int> mp;
        for (int r = 0; r < fruits.size(); r++) {
            mp[fruits[r]]++;
            while (mp.size() > 2) {
                mp[fruits[l]]--;
                if (!mp[fruits[l]]) mp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};