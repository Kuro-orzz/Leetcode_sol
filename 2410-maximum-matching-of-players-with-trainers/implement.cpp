#define all(x) (x).begin(),(x).end()

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(all(players));
        sort(all(trainers));
        int n = players.size();
        int m = trainers.size();
        int p1 = 0, p2 = 0;
        int ans = 0;
        while (p1 < n && p2 < m) {
            if (players[p1] <= trainers[p2]) {
                ans++, p1++, p2++;
            } else {
                p2++;
            }
        }
        return ans;
    }
};