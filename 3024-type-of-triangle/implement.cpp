class Solution {
public:
    bool isTriangle(int a, int b, int c) {
        return a + b > c && b + c > a && c + a > b;
    }

    string triangleType(vector<int>& nums) {
        if (nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";
        sort(nums.begin(), nums.end());
        if (!isTriangle(nums[0], nums[1], nums[2]))
            return "none";
        if (nums[0] == nums[1] || nums[1] == nums[2])
            return "isosceles";
        return "scalene";
    }
};