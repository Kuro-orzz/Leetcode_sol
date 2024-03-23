class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;
        int cnt1 = 0;
        int cnt2 = n-1;
        for(int i = 0; i < n; i++){
            ans += mat[i][cnt1] + mat[cnt2][i];
            cnt1++; cnt2--;
        }
        if(n&1)
            ans -= mat[n/2][n/2];
        return ans;
    }
};