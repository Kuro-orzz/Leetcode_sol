#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int m = obstacles.size();
        vector<vector<int>> row(6e4+6), col(6e4+6);
        for (int i = 0; i < m; i++) {
            row[obstacles[i][1]+3e4].push_back(obstacles[i][0]);
            col[obstacles[i][0]+3e4].push_back(obstacles[i][1]);
        }
        for (int i = 0; i < row.size(); i++) sort(row[i].begin(), row[i].end());
        for (int i = 0; i < col.size(); i++) sort(col[i].begin(), col[i].end());

        pii curPos = {0, 0};
        char direction[4] = {'N', 'E', 'S', 'W'};
        int curDir = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (commands[i] == -2) curDir = (curDir + 3) % 4;
            else if (commands[i] == -1) curDir = (curDir + 1) % 4;
            else {
                if (direction[curDir] == 'N') {
                    auto it = lower_bound(all(col[curPos.fi+3e4]), curPos.se+1);
                    int k = commands[i];
                    int obsPos = it - col[curPos.fi+3e4].begin();
                    if (obsPos != col[curPos.fi+3e4].size()) {
                        curPos.se += min(k, abs(curPos.se - (col[curPos.fi+3e4][obsPos] - 1)));
                    } else {
                        curPos.se += k;
                    }
                } else if (direction[curDir] == 'E') {
                    auto it = lower_bound(all(row[curPos.se+3e4]), curPos.fi+1);
                    int k = commands[i];
                    int obsPos = it - row[curPos.se+3e4].begin();
                    if (obsPos != row[curPos.se + 3e4].size()) {
                        curPos.fi += min(k, abs(curPos.fi - (row[curPos.se+3e4][obsPos] - 1)));
                    } else {
                        curPos.fi += k;
                    }
                } else if (direction[curDir] == 'S') {
                    auto it = lower_bound(all(col[curPos.fi+3e4]), curPos.se);
                    int k = commands[i];
                    int obsPos = it - col[curPos.fi+3e4].begin();
                    if (obsPos) {
                        curPos.se -= min(k, abs(curPos.se - (col[curPos.fi+3e4][obsPos-1] + 1)));
                    } else {
                        curPos.se -= k;
                    }
                } else if (direction[curDir] == 'W') {
                    auto it = lower_bound(all(row[curPos.se+3e4]), curPos.fi);
                    int k = commands[i];
                    int obsPos = it - row[curPos.se+3e4].begin();
                    if (obsPos) {
                        curPos.fi -= min(k, abs(curPos.fi - (row[curPos.se+3e4][obsPos-1] + 1)));
                    } else {
                        curPos.fi -= k;
                    }
                }
            }
            ans = max(ans, curPos.fi * curPos.fi + curPos.se * curPos.se);
        }
        return ans;
    }
};