class KMP {
public:
    size_t n, m;
    string S, T;
    vector<int> pi;

    KMP() {}

    KMP(string s1, string s2): S(s1), T(s2) {
        n = s1.size();
        m = s2.size();
    }

    void LPS() {
        pi.resize(n);
        for (size_t i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && S[i] != S[j]) {
                j = pi[j - 1];
            }
            if (S[i] == S[j]) j++;
            pi[i] = j;
        }
    }

    vector<int> __KMP() {
        if (n == 0) return {};
        LPS();
        int j = 0;
        vector<int> ans(m);
        for (size_t i = 0; i < m; i++) {
            while (j > 0 && T[i] != S[j]) {
                j = pi[j - 1];
            }
            if (T[i] == S[j]) j++;
            ans[i] = j;
            if (j == n) {
                j = pi[j - 1];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        KMP kmp(needle, haystack);
        vector<int> res = kmp.__KMP();
        for (size_t i = 0; i < n; i++) {
            if (res[i] == m) return i - m + 1;
        }
        return -1;
    }
};