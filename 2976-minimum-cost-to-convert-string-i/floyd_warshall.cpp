#define ll long long

class Solution {
public:
    void floyd_warshall(int n, vector<vector<ll>> &dist) {
        for (int k = 0; k < n; ++k) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    if (dist[u][k] == 1e18 || dist[k][v] == 1e18) continue;
                    if (dist[u][v] > dist[u][k] + dist[k][v]) {
                        dist[u][v] = dist[u][k] + dist[k][v];
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> d(26, vector<ll>(26, 1e18));
        for (int i = 0; i < original.size(); i++) {
            d[original[i]-'a'][changed[i]-'a'] = min(d[original[i]-'a'][changed[i]-'a'], 1ll * cost[i]);
        }
        floyd_warshall(26, d);
        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                if (d[source[i]-'a'][target[i]-'a'] == 1e18) return -1;
                ans += d[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};