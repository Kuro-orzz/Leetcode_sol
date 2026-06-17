class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long w = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int i = 0; i < n; i++) {
            if (w < asteroids[i]) return false;
            w += asteroids[i];
        }
        return true;
    }
};