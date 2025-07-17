#define ll long long
#define all(x) (x).begin(),(x).end()
class Solution {
public:
    int n;
    vector<vector<int>> a;
    vector<vector<ll>> dp;

    int binSearch(int l, int r, int x) {
        int res = -1;
        while (l <= r) {
            int mid = (l+r) >> 1;
            if (a[mid][0] >= x) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return res;
    }

    ll calc(int cur, int k) {
        if (cur == -1) return 0;
        if (k == 0 || cur == n) return 0;
        if (dp[cur][k] != -1) return dp[cur][k];
        int nxt = binSearch(cur + 1, n - 1, a[cur][1]+1);
        return dp[cur][k] = max(calc(cur+1, k), calc(nxt, k-1) + a[cur][2]);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        this->a = events;
        n = events.size();
        dp.resize(n, vector<ll>(k+1, -1));
        sort(all(a));
        return calc(0, k);
    }
};