class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> v(51, 0);
        for(int i = 0; i < ranges.size(); i++){
            for(int j = ranges[i][0]; j <= ranges[i][1]; j++)
                v[j] = 1;
        }
        bool t = true;
        for(int i = left; i <= right; i++)
            if(!v[i]) t = false;
        return t;
    }
};