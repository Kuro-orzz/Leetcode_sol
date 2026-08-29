#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<pii> priority;
        for (int i = 0; i < n; i++) {
            priority.push_back({arr[i], i});
        }
        sort(priority.begin(), priority.end());
        vector<int> dist(n, 1);
        for (int i = 0; i < n; i++) {
            int idx = priority[i].se;
            int mx_left = 0;
            for (int j = idx-1; j >= max(0, idx-d); j--) {
                if (arr[j] <= mx_left) break;
                if (arr[idx] < arr[j]) {
                    dist[j] = max(dist[j], dist[idx] + 1);
                    mx_left = max(mx_left, arr[j]);
                }
            }
            int mx_right = 0;
            for (int j = idx+1; j <= min(n-1, idx+d); j++) {
                if (arr[j] <= mx_right) break;
                if (arr[idx] < arr[j]) {
                    dist[j] = max(dist[j], dist[idx] + 1);
                    mx_right = max(mx_right, arr[j]);
                }
            }
        }
        return *max_element(dist.begin(), dist.end());
    }
};