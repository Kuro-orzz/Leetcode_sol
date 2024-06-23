#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pii, vector<pii>, greater<pii>> pq1;
        priority_queue<pii> pq2;
        int l = 0, r = 0;
        int ans = 0;
        while(r < nums.size()){
            while(!pq1.empty() && abs(nums[r]-pq1.top().first) > limit){
                l = max(l, pq1.top().second+1);
                pq1.pop();
            }
            while(!pq2.empty() && abs(nums[r]-pq2.top().first) > limit){
                l = max(l, pq2.top().second+1);
                pq2.pop();
            }
            pq1.push({nums[r], r});
            pq2.push({nums[r], r});
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};