#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

template <typename T>
class Hash {
public:
    static constexpr int base = 311;
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
    string s;

    bool checkEqualStr(int i, int j, int len) {
        for (int k = 0; k < len; k++) {
            if (s[i + k] != s[j + k]) {
                return false;
            }
        }
        return true;
    }

    int check(Hash<int> &h, int len, int n) {
        set<pii> st;
        for (int i = 1; i+len-1 <= n; i++) {
            int x = h.getHash(i, i+len-1);
            auto it = st.lower_bound({x, 0});
            while (it != st.end() && it->fi == x) {
                if (checkEqualStr(it->se, i-1, len)) {
                    return i-1;
                }
                it = next(it);
            }
            st.insert({x, i-1});
        }
        return -1;
    }

    pii binSearch(Hash<int> &h, int n) {
        int l = 1, r = n;
        pii ans = {-1, -1}; // startPos, len
        while (l <= r) {
            int mid = (l + r) >> 1;
            int x = check(h, mid, n);
            if (x != -1) {
                ans = {x, mid};
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    string longestDupSubstring(string s) {
        this->s = s;
        int n = s.size();
        Hash<int> h(s);
        auto [startPos, len] = binSearch(h, n);
        return startPos != -1 ? s.substr(startPos, len) : "";
    }
};