class Solution {
public:
    int mod = 1e9 + 7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        swap(m, n);
        hFences.push_back(1);
        hFences.push_back(n);
        vFences.push_back(1);
        vFences.push_back(m);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<int> h, v;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                h.insert(hFences[j] - hFences[i]);
            }
        }
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                v.insert(vFences[j] - vFences[i]);
            }
        }
        long long ans = -1;
        for (int x : h) {
            if (v.count(x)) ans = max(ans, 1ll * x * x);
        }
        if (ans == -1) return ans;
        return ans % mod;
    }
};