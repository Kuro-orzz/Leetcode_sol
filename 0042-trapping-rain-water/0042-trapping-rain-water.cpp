class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l, r;
        int l_max = 0, r_max = 0;
        for(int i = 0; i < n; i++){
            l_max = max(l_max, height[i]);
            l.push_back(l_max); 
        }
        for(int i = n-1; i >= 0; i--){
            r_max = max(r_max, height[i]);
            r.push_back(r_max);
        }
        reverse(r.begin(), r.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(l[i], r[i])-height[i];
        }
        return ans;
    }   
};