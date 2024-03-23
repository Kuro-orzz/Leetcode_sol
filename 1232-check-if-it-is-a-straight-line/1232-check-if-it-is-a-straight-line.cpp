class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2)
            return true;
        pair<int, int> p = {coordinates[0][0]-coordinates[1][0], coordinates[0][1]-coordinates[1][1]};
        int ucln = __gcd(p.first, p.second);
        p.first /= ucln;
        p.second /= ucln;
        for(int i = 2; i < coordinates.size(); i++){
            pair<int, int> tmp = {coordinates[0][0]-coordinates[i][0], coordinates[0][1]-coordinates[i][1]};
            int tmp1 = __gcd(tmp.first, tmp.second);
            tmp.first /= tmp1;
            tmp.second /= tmp1;
            if((p.first != tmp.first || p.second != tmp.second))
                return false;
        }
        return true;
    }
};