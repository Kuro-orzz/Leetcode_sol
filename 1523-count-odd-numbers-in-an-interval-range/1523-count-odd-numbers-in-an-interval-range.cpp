class Solution {
public:
    int countOdds(int low, int high) {
        if(high%2!=0)
            return ceil((high-low+1)/2.0);
        return ceil((high-low)/2.0);
    }
};