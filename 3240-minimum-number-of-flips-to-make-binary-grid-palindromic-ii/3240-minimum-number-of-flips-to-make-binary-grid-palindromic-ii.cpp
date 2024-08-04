class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n/2; i++)
            for(int j = 0; j < m/2; j++){
                int t = grid[i][j]+grid[i][m-j-1]+grid[n-i-1][j]+grid[n-i-1][m-j-1];
                if(t == 1 || t == 3)
                    ans++;
                else if(t == 2)
                    ans += 2;
            }
        if(n % 2 == 1 && m % 2 == 0){
            int cnt = 0;
            int dif = 0;
            for(int i = 0; i < m; i++){
                if(grid[n/2][i])
                    cnt++;
                if(grid[n/2][i] != grid[n/2][m-i-1])
                    dif++;
            }
            dif /= 2;
            if(dif < 2)
                ans += dif+min(((cnt+dif) % 4 ? 2 : 0), ((cnt-dif) % 4 ? 2 : 0));
            else
                ans += dif;
        }      
        else if(n % 2 == 0 && m % 2 == 1){
            int cnt = 0;
            int dif = 0;
            for(int i = 0; i < n; i++){
                if(grid[i][m/2])
                    cnt++;
                if(grid[i][m/2] != grid[n-i-1][m/2])
                    dif++;
            }
            dif /= 2;
            if(dif < 2)
                ans += dif+min(((cnt+dif) % 4 ? 2 : 0), ((cnt-dif) % 4 ? 2 : 0));
            else
                ans += dif;
        }
        else if(n % 2 == 1 && m % 2 == 1){
            int cnt0 = 0;
            int cnt1 = 0;
            int dif = 0;
            for(int i = 0; i < m; i++){
                if(grid[n/2][i])
                    cnt1++;
                else cnt0++;
                if(grid[n/2][i] != grid[n/2][m-i-1])
                    dif++;
            }
            for(int i = 0; i < n; i++){
                if(grid[i][m/2])
                    cnt1++;
                else cnt0++;
                if(grid[i][m/2] != grid[n-i-1][m/2])
                    dif++;
            }
            dif /= 2;
            if(grid[n/2][m/2])
                cnt1 -= 2;
            else cnt0--;
            if(dif < 2)
                ans += dif+grid[n/2][m/2]+min(((cnt1+dif) % 4 ? 2 : 0), ((cnt1-dif) % 4 ? 2 : 0));
            else
                ans += dif+grid[n/2][m/2];
        }
        return ans;
    }
};