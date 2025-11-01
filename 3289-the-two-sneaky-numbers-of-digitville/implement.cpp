class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n), ans;
        for (int &x : nums) {
            if (!vis[x]) vis[x] = 1;
            else ans.push_back(x);
        }
        return ans;
    }
};