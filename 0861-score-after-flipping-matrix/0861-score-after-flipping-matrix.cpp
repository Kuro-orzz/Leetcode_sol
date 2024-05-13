class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        vector<int> cnt(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < grid[i].size(); j++){
                    grid[i][j] ^= 1;
                    cnt[j] += grid[i][j];
                }
            }
            else{
                for(int j = 0; j < grid[i].size(); j++)
                    cnt[j] += grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            string s = "";  
            for(int j = grid[i].size()-1; j >= 0; j--){
                if(cnt[j] < grid.size()-cnt[j])
                    grid[i][j] ^= 1;
                s += grid[i][j]+'0';
            }
            reverse(s.begin(), s.end());
            ans += bitset<32>(s).to_ullong();
        }
        return ans;
    }
};