class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int cnt = 0;
        int t = meetings[0][1];
        if(meetings[0][0] > 1)
            cnt += meetings[0][0]-1;
        for(int i = 1; i < meetings.size(); i++){
            if(t < meetings[i][0])
                cnt += meetings[i][0]-t-1;
            t = max(t, meetings[i][1]);
        }
        cnt += days-t;
        return cnt;
    }
};