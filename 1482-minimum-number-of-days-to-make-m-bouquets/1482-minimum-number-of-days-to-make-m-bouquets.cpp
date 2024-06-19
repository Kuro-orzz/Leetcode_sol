class Solution {
public:
    void bin_search(int l, int r, vector<int> &v, int &m, int &k, int &ans){
        while(l <= r){
            int mid = (l+r)>>1;
            int bq = 0;
            int cnt = 0;
            for(int i = 0; i < v.size(); i++){
                if(v[i] <= mid)
                    cnt++;
                else
                    cnt = 0;
                if(cnt == k){
                    bq++;
                    cnt = 0;
                }
                if(bq == m) break;
            }
            if(bq == m){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = INT_MAX;
        bin_search(1, 1e9, bloomDay, m, k, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};