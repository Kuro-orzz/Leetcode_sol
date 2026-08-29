class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int cur_row = 1, cur_seat = 0, ans = 0;
        sort(reservedSeats.begin(), reservedSeats.end());
        for (int i = 0; i < reservedSeats.size(); i++) {
            if (reservedSeats[i][0] > cur_row) {
                if (cur_seat < 2) ans += 2;
                else if (cur_seat < 6) ans++;
                ans += 2 * (reservedSeats[i][0]-cur_row-1);
                cur_row = reservedSeats[i][0];
                cur_seat = 0;
            }
            if (cur_seat < 2 && reservedSeats[i][1] > 9) {
                ans += 2;
            } else if (cur_seat < 2 && reservedSeats[i][1] > 5) {
                ans++;
            } else if (cur_seat < 4 && reservedSeats[i][1] > 7) {
                ans++;
            } else if (cur_seat < 6 && reservedSeats[i][1] > 9) {
                ans++;
            }
            cur_seat = reservedSeats[i][1];
        }
        if (cur_seat < 2) {
            ans += 2;
        } else if (cur_seat < 6) {
            ans++;
        }
        ans += 2 * (n-cur_row);
        return ans;
    }
};