#define ll long long
class Solution {
public:
    bool checkPrime(ll x) {
        for (ll i = 2; i*i <= x; i++) {
            if (x % i == 0) return false;
        }
        return x > 1;
    }
    
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        set<ll> st;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n-i+1; j++) {
                string t = s.substr(i, j);
                if (checkPrime(stoll(t))) {
                    st.insert(stoll(t));
                }
            }
        }
        vector<ll> prime;
        for (ll x : st) {
            prime.push_back(x);
        }
        sort(prime.begin(), prime.end(), greater<>());
        if (prime.size() < 3) {
            return accumulate(prime.begin(), prime.end(), 0ll);
        }
        return prime[0] + prime[1] + prime[2];
    }
};