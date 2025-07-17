class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        auto cmp = [&](vector<int> &a, vector<int> &b) { return a[0] < b[0]; };
        sort(meetings.begin(), meetings.end(), cmp);
        vector<long long> mark(n), cnt_used(n);
        int cur_room = 0;
        for (int i = 0; i < m; i++) {
            cur_room = 0;
            for (int j = 0; j < n; j++) {
                if (mark[j] < mark[cur_room]) cur_room = j;
                if (mark[j] > meetings[i][0]) continue;
                cur_room = j;
                break;
            }
            int meetLen = meetings[i][1] - meetings[i][0];
            mark[cur_room] = max(mark[cur_room], 1ll*meetings[i][0]) + meetLen;
            cnt_used[cur_room]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnt_used[ans] < cnt_used[i]) {
                ans = i;
            }
        }
        return ans;
    }
};