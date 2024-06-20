class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int ans = 0;
        int l = 1, r = 1e9;
        while(l <= r){
            int mid = (l+r) >> 1;
            int t = 1;
            int pos = position[0];
            for(int i = 1; i < m; i++){
                auto it = lower_bound(position.begin(), position.end(), pos+mid);
                if(it != position.end()){
                    pos = position[it-position.begin()];
                    t++;
                }
                else
                    break;
            }
            if(t == m){
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};