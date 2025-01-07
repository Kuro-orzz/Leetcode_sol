class Solution {
public:
    pair<double, double> line(vector<int> &c, vector<int> &d){
        double a = 0;
        if(c[0]-d[0] == 0) return {c[0], 1e9};
        if(c[1]-d[1] == 0) return {1e9, c[1]};
        a = (double)(c[1]-d[1])/(c[0]-d[0]);
        double b = c[1]-a*c[0];
        return {a, b};        
    }

    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        int cnt = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                cnt = 2;
                pair<double, double> u = line(points[i], points[j]);
                for(int k = j+1; k < points.size(); k++){
                    if(u.first == 1e9 && points[k][1] == u.second)
                        cnt++;
                    if(u.first == 1e9) continue;
                    if(u.second == 1e9 && points[k][0] == u.first)
                        cnt++;
                    if(u.second == 1e9) continue;
                    if(fabs(u.first * points[k][0] + u.second - points[k][1]) < 1e-9)
                        cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};