class Solution {
public:
    vector<int> a;

    bool calc(int i, int j, int score1, int score2, int turn) {
        if (i > j) return score1 >= score2;
        if (turn == 1) {
            bool t1 = calc(i+1, j, score1 + a[i], score2, 2);
            bool t2 = calc(i, j-1, score1 + a[j], score2, 2);
            return t1 || t2;
        } else {
            bool t1 = calc(i+1, j, score1, score2 + a[i], 1);
            bool t2 = calc(i, j-1, score1, score2 + a[j], 1);
            return t1 && t2;
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        this->a = nums;
        return calc(0, n-1, 0, 0, 1);
    }
};