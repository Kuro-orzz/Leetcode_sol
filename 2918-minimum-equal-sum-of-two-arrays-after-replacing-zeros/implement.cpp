class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        bool check1 = false;
        bool check2 = false;
        long long sum1 = 0;
        for (int x : nums1) {
            if (x) sum1 += x;
            else {
                sum1++;
                check1 = true;
            }
        }
        long long sum2 = 0;
        for (int x : nums2) {
            if (x) sum2 += x;
            else {
                sum2++;
                check2 = true;
            }
        }
        if (sum1 <= sum2 && check1) return sum2;
        else if (sum1 >= sum2 && check2) return sum1;
        else if (sum1 == sum2) return sum1;
        else return -1;
    }
};