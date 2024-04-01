class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int total = 0;
        for(int i = 0; i < possible.size(); i++)
            if(possible[i] == 0)
                total--;
            else
                total++;
        int ans = INT_MAX;
        int point = 0;
        for(int i = 0; i < possible.size()-1; i++){
            if(possible[i] == 0)
                point--;
            else
                point++;
            if(point > total-point)
                return i+1;
        }
        return -1;
    }
};