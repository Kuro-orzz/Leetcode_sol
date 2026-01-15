class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        int neg_pos = -1;
        for (int i = 0; i < n; i++) {
            if (balance[i] < 0) {
                neg_pos = i;
                break;
            }
        }
        if (neg_pos == -1) return 0;
        long long ans = 0;
        int dist = 1;
        while (balance[neg_pos] < 0) {
            // left
            int left = neg_pos - dist;
            if (left < 0) left += n;
            int move_left = min(-balance[neg_pos], balance[left]);
            ans += 1ll * move_left * dist;
            balance[neg_pos] += move_left;
            balance[left] -= move_left;
            // right
            int right = neg_pos + dist;
            if (right >= n) right -= n;
            int move_right = min(-balance[neg_pos], balance[right]);
            ans += 1ll * move_right * dist;
            balance[neg_pos] += move_right;
            balance[right] -= move_right;
            
            if (dist >= n) return -1;
            dist++;
        }
        return ans;
    }
};