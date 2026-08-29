#define ll long long

template <typename T>
class Hash {
public:
    static constexpr int base = 331;
    static constexpr int mod = 1'000'000'007;
    int n;
    vector<T> h, p;

    Hash() {}

    Hash(const string &s) {
        build(s);
    }

    void build(const string &s, bool extend = 0) {
        n = s.size();
        h = hashStr(s, n);
        if (extend) p = calc_pow(n);
    }

    T getHash() const {
        T x = (h[n] - 1ll * h[0] * p[n]) % mod;
        return T((x + mod) % mod);
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
    bool isVowel(char c) { return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'; }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        unordered_map<ll, int> hash, hash_norm, hash_vowel;
        Hash<ll> h;
        h.build("123456789", 1);
        for (int i = 0; i < n; i++) {
            string tmp = wordlist[i];
            h.build(tmp);
            if (!hash.count(h.getHash())) hash[h.getHash()] = i;
            
            transform(tmp.begin(), tmp.end(), tmp.begin(), [](char &c){ return tolower(c); });
            h.build(tmp);
            if (!hash_norm.count(h.getHash())) hash_norm[h.getHash()] = i;
            
            for (int j = 0; j < tmp.size(); j++) {
                if (isVowel(tmp[j])) {
                    tmp[j] = (char)('a' - 1);
                }
            }
            h.build(tmp);
            if (!hash_vowel.count(h.getHash())) hash_vowel[h.getHash()] = i;
        }
        vector<string> ans;
        for (string &s : queries) {
            h.build(s);
            int val = h.getHash();
            
            transform(s.begin(), s.end(), s.begin(), [](char &c){ return tolower(c); });
            h.build(s);
            int val_norm = h.getHash();
            
            for (char &c : s) {
                if (isVowel(c)) c = (char)('a' - 1);
            }
            h.build(s);
            int val_vowel = h.getHash();
            
            if (hash.count(val)) {
                ans.push_back(wordlist[hash[val]]);
            } else if (hash_norm.count(val_norm)) {
                ans.push_back(wordlist[hash_norm[val_norm]]);
            } else if (hash_vowel.count(val_vowel)) {
                ans.push_back(wordlist[hash_vowel[val_vowel]]);
            } else {
                ans.push_back("");
            }
        }

        return ans;
    }
};