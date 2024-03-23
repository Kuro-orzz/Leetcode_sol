class Solution {
public:
    double average(vector<int>& salary) {
        int maximum = 0;
        int minimum = INT_MAX;
        int sum = 0;
        for(int i : salary){
            maximum = max(maximum, i);
            minimum = min(minimum, i);
            sum += i;
        }
        return (sum-maximum-minimum)/(double)(salary.size()-2);
    }
};