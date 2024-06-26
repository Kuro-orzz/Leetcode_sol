class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int ans = 0;
        int l = 1, r = position[position.size()-1];
        while(l <= r){
            int mid = (l+r) >> 1;
            int t = 1;
            int pos = position[0];
            for(int i = 1; i < n; i++){
                if(pos + mid <= position[i]){
                    pos = position[i];
                    t++;
                }
                if(t == m)  break;
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