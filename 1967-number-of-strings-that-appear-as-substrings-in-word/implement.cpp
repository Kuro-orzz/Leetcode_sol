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
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        Hash<int> h(word);
        unordered_map<int, int> mp;
        for (int i = 0; i < word.size(); i++) {
            for (int j = i; j < word.size(); j++) {
                mp[h.getHash(i+1, j+1)] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            Hash<int> t(patterns[i]);
            int x = t.getHash(1, patterns[i].size());
            if (mp.count(x)) {
                ans++;
            }
        }

        return ans;
    }
};