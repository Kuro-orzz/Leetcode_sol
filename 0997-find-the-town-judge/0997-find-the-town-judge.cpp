class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int a[n+1];
        int b[n+1];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < trust.size(); i++){
            a[trust[i][0]]++;
            b[trust[i][1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(a[i] == 0 && b[i] == n-1)
                return i;
        }
        return -1;
    }
};