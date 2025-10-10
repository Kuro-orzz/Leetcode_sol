class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int ans = min(height[l], height[r]) * (r - l);
        while (l < r) {
            if (height[l] < height[r]) l++;
            else r--;
            ans = max(ans, min(height[l], height[r]) * (r - l));
        }
        return ans;
    }
};