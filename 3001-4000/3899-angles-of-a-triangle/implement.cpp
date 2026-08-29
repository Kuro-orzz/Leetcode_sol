class Solution {
public:
    double PI = 3.14159265358979323846;

    bool isTriangle(vector<int> &a) {
        return a[0] + a[1] > a[2] && a[1] + a[2] > a[0] && a[2] + a[0] > a[1];
    }

    double calc(vector<int> &a) {
        return acos((a[0]*a[0] + a[1]*a[1] - a[2]*a[2]) / (2.0 * a[0] * a[1])) / PI * 180;
    }

    vector<double> internalAngles(vector<int>& sides) {
        if (!isTriangle(sides)) return {};
        vector<double> ans;
        for (int i = 0; i < 3; i++) {
            ans.push_back(calc(sides));
            swap(sides[0], sides[1]);
            swap(sides[1], sides[2]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};