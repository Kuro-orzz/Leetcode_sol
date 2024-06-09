class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9+7;
        int ans = 0;
        vector<int> v(n, 1);
        for(int i = 0; i < k; i++){
            for(int j = 1; j < n; j++)
                v[j] = (v[j]+v[j-1]) % mod;
        }
        return v[n-1];
    }
};