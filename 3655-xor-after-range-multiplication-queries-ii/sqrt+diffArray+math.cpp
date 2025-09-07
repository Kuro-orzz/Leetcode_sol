#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    using i128 = __int128;
    
    ll binPow(ll a, ll b, ll M) {
        a %= M;
        ll res = 1;
        while (b) {
            if (b & 1) res = (i128)res * a % M;
            a = (i128)a * a % M;
            b /= 2;
        }
        return res;
    }

    ll inverse(ll a, ll m) { return binPow(a, m-2, m); }

    const int mod = 1e9 + 7;
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int S = sqrt(n);
        vector<vector<vector<ll>>> diff(S+1);
        for (int k = 1; k <= S; k++) {
            diff[k].resize(k);
        }
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            if (k > S) {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1ll * nums[i] * v) % mod;
                }
            } else {
                int offset = l % k;
                int startPos = (l - offset) / k;
                int endPos = (r - offset) / k;

                if (diff[k][offset].size() <= endPos + 1) {
                    diff[k][offset].resize(endPos + 2, 1);
                }

                diff[k][offset][startPos] *= v;
                diff[k][offset][startPos] %= mod;
                diff[k][offset][endPos + 1] *= inverse(v, mod);
                diff[k][offset][endPos + 1] %= mod;
            }
        }

        // apply change
        for (int k = 1; k <= S; k++) {
            for (int offset = 0; offset < k; offset++) {
                if (diff[k][offset].empty()) continue;
                ll mul = 1;
                for (int i = 0; offset + i * k < n; i++) {
                    if (i < diff[k][offset].size()) {
                        mul = mul * diff[k][offset][i] % mod;
                    }
                    nums[offset + i * k] = 1ll * nums[offset + i * k] * mul % mod;
                }
            }
        }

        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};