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
    vector<string> normalize(string &s) {
        int n = s.size();
        vector<string> res;
        string x = "";
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) x += s[i];
            else {
                if (x == "" || i == n-1) continue;
                else if (s[i+1] == '-') {
                    if (x != "") res.push_back(x);
                    x = "";
                } else x += s[i];
            }
        }
        if (x != "") res.push_back(x);
        return res;
    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for (string &x : chunks) {
            s += x;
        }
        stringstream ss(s);
        vector<string> v;
        string tmp;
        while (ss >> tmp) {
            vector<string> t = normalize(tmp);
            v.insert(v.end(), t.begin(), t.end());
        }
        map<int, int> mp;
        for (string &c : v) {
            Hash<long long> h(c);
            mp[h.getHash(1, c.size())]++;
        }
        vector<int> ans;
        for (string &c : queries) {
            Hash<long long> h(c);
            ans.push_back(mp[h.getHash(1, c.size())]);
        }
        return ans;
    }
};