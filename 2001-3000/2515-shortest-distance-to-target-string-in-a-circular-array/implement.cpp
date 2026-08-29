class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) v.push_back(i);
        }
        int ans = INT_MAX;
        for (int x : v) {
            ans = min({ans, abs(startIndex-x), x+n-startIndex, startIndex+n-x});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};