#define ll long long
class Solution {
public:
    vector<int> segmentSieve(int l, int r){
        vector<int> prime(r-l+1, 1);
        for(ll p = 2; p*p <= r; p++){
            ll lim = max(p*p, (l+p-1)/p*p);
            for(ll j = lim; j <= r; j += p)
                if (j-l >= 0) prime[j-l] = 0;
        }
        if (l == 0) prime[0] = 0;
        if (l == 0 && r > l) prime[1] = 0;
        if (l == 1) prime[1-l] = 0;
        return prime;
    }

    set<int> listPrime(int l, int r) {
        vector<int> prime = segmentSieve(l, r);
        set<int> listPi;
        for (int i = l; i <= r; i++) {
            if (prime[i-l]) listPi.insert(i);
        }
        return listPi;
    }

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        set<int> prime = listPrime(1, 1e5);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int x : prime) {
                if (x * x >= nums[i]) break;
                if (nums[i] % x) continue;
                int y = nums[i] / x;
                if (prime.find(y) != prime.end() || y == x * x) {
                    ans += 1 + nums[i] + x + nums[i] / x;
                    break;
                }
            }
        }
        return ans;
    }
};