class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(nums[i]);
        int ans = 0;
        for(int it : s){
            if(s.find(it-1) == s.end()){
                int cnt = 0;
                int x = it;
                while(s.find(x+1) != s.end())
                    x++, cnt++;
                ans = max(ans, cnt+1);
            }
        }
        return ans;
    }
};