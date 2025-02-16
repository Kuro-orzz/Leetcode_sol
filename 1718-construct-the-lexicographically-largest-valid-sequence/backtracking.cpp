class Solution {
public:
    vector<int> cnt, ans;

    bool backtrack(int idx, int n){
        if(idx == ans.size()) return true;
        if(ans[idx])
            return backtrack(idx+1, n);
        for(int i = n; i >= 1; i--){
            if(cnt[i]) continue;
            if(i > 1 && (idx+i >= ans.size() || ans[idx+i])) continue;
            if(i == 1) ans[idx] = 1;
            else ans[idx] = ans[idx+i] = i;
            cnt[i] = 1;
            if(backtrack(idx+1, n)) return true;
            if(i == 1) ans[idx] = 0;
            else ans[idx] = ans[idx+i] = 0;
            cnt[i] = 0;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        cnt.resize(n+1, 0);
        ans.resize(2*n-1, 0);
        backtrack(0, n);   
        return ans;
    }
};