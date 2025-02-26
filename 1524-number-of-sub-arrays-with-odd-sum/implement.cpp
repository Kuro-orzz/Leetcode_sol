class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int a[2];
        memset(a, 0, sizeof a);
        int ans = 0, sum = 0;
        a[0] = 1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] % 2 == sum % 2)
                ans += a[1];
            else
                ans += a[0];
            sum += arr[i];
            a[sum%2]++;
            ans %= mod;
        }
        return ans;
    }
};