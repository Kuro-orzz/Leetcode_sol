class Solution {
public:
    vector<int> nt;

    void sieve(int n){
        nt.resize(n+1, 1);
        nt[0] = nt[1] = 0;
        for(int i = 2; i*i <= n; i++){
            if(!nt[i]) continue;
            for(int j = i*i; j <= n; j+=i)
                if(j % i == 0)
                    nt[j] = 0;
        }
    }

    vector<int> closestPrimes(int left, int right) {
        sieve(right);
        vector<int> ans;
        int prev = INT_MIN;
        for(int i = left; i <= right; i++){
            if(!nt[i]) continue;
            if(ans.size() < 2) ans.push_back(i);
            else if(i-prev < ans[1]-ans[0]){
                ans[0] = prev;
                ans[1] = i;
            }
            prev = i;
        }
        if(ans.size() < 2) return {-1, -1};
        return ans;
    }
};