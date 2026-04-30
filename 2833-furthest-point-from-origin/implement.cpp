class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int pos = 0, k = 0;
        for (char &c : moves) {
            if (c == 'L') pos--;
            else if (c == 'R') pos++;
            else k++;
        }
        return abs(pos) + k;
    }
};