class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int x : s){
            if(x < k) return -1;
            else if(x > k) ans++;
        }
        return ans;
    }
};