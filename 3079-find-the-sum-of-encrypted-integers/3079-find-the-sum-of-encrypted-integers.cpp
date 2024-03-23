class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        auto findMax = [&](int n){
            int ans = 0;
            while(n){
                ans = max(ans, n%10);
                n /= 10;
            }
            return ans;
        };
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            int tmp = findMax(nums[i]);
            string change = to_string(nums[i]);
            for(int j = 0; j < change.size(); j++)
                change[j] = tmp+'0';
            sum += stoi(change);
        }
        return sum;
    }
};