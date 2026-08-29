class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n; 
        while (l <= r) {
            int mid = (l + r) >> 1;
            int firstHalf = mid * (1 + mid) / 2;
            int secondHalf = (n - mid + 1) * (mid + n) / 2;
            if (firstHalf < secondHalf) {
                l = mid + 1;
            } else if (firstHalf > secondHalf) {
                r = mid - 1;
            } else return mid;
        }
        return -1;
    }
};