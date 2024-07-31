class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        int n = enemyEnergies.size();
        long long p = 0;
        int l = 0, r = n-1;
        int cnt = 0;
        while(l <= r){
            if(currentEnergy >= enemyEnergies[l]){
                p += currentEnergy/enemyEnergies[l];
                currentEnergy = currentEnergy%enemyEnergies[l];
            }
            else if(r >= 0 && p){
                currentEnergy += enemyEnergies[r];
                r--;
            }
            else
                break;
        }
        return p;
    }
};