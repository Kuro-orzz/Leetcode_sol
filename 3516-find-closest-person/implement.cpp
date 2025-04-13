class Solution {
public:
    int findClosest(int x, int y, int z) {
        int t1 = abs(x-z);
        int t2 = abs(y-z);
        if(t1 < t2) return 1;
        else if(t1 > t2) return 2;
        return 0;
    }
};