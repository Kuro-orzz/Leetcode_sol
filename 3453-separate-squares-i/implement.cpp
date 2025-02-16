class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9;
        double high = 0;
        for(int i = 0; i < squares.size(); i++){
            low = min(low, (double)squares[i][1]);
            high = max(high, (double)squares[i][1]+squares[i][2]);
        }
        double mid;
        while(fabs(low-high) >= 1e-5){
            mid = (low+high)/2;
            double sum_l = 0;
            double sum_h = 0;
            for(int i = 0; i < squares.size(); i++){
                int y = squares[i][1];
                int l = squares[i][2];
                if(mid <= y)
                    sum_h += 1ll*l*l;
                else if(mid >= y+l)
                    sum_l += 1ll*l*l;
                else{
                    sum_l += 1ll*(mid-y)*l;
                    sum_h += 1ll*(y+l-mid)*l;
                }
            }
            if(sum_l < sum_h) low = mid;
            else high = mid;
        }
        return mid;
    }
};