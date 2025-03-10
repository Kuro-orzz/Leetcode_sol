class Solution {
public:
    long long coloredCells(int n) {
        return 1ll*(n-1)*4*n/2+1;
    }
};