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
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        Hash<int> h(text);
        set<string> s;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; i + 2*j + 1 <= n; j++) {
                int l1 = i, r1 = l1 + j;
                int l2 = r1 + 1, r2 = l2 + j;
                if (h.getHash(l1, r1) == h.getHash(l2, r2)) {
                    s.insert(text.substr(l1-1, r1-l1+1));
                }
            }
        }
        return (int)s.size();
    }
};