class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        sort(v.begin(), v.end(), greater<int>());
        return v[0] * v[1];
    }
};