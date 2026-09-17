#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

template <typename T>
class Hash {
public:
    static constexpr int base = 331;
    static constexpr int mod = 1'000'000'007;
    vector<T> h, p;

    Hash() {}

    Hash(const string &s) {
        build(s);
    }

    void build(const string &s) {
        int n = s.size();
        h = hashStr(s, n);
        p = calc_pow(n);
    }

    T getHash(int l, int r) const {
        T x = (h[r] - 1ll * h[l-1] * p[r-l+1]) % mod;
        return T((x + mod) % mod);
    }

private:
    vector<T> hashStr(const string &s, int n) {
        vector<T> hash(n + 1);
        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a' + 1;
            hash[i] = (1ll * hash[i-1] * base + c) % mod;
        }
        return hash;
    }

    vector<T> calc_pow(int n) {
        vector<T> P;
        P.emplace_back(1);
        for (int i = 1; i <= n; i++) {
            P.emplace_back((1ll * P[i-1] * base) % mod);
        }
        return P;
    }
};

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        string x = s;
        reverse(x.begin(), x.end());
        Hash<ll> H1(s), H2(x);
        vector<pii> v;
        for (int i = 0; i < n; i++) {
            for (int j = i + k - 1; j < n; j++) {
                int len = j - i + 1;
                ll le = H1.getHash(i+1, i+len/2);
                ll ri = H2.getHash(n-j, n-j+len/2-1);
                if (le == ri) v.emplace_back(i, j);
            }
        }
        int ans = 0, last = -1;
        for (pii it : v) {
            if (it.fi > last) {
                ans++;
                last = it.se;
            } else if (it.fi < last && it.se < last) {
                last = it.se;
            }
        }
        return ans;
    }
};