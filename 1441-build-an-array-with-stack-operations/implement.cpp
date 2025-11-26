class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int sz = target.size();
        vector<string> ans;
        int cur = 0;
        for (int i = 1; i <= n, cur < sz; i++) {
            ans.push_back("Push");
            if (i == target[cur]) {
                cur++;
            } else {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};