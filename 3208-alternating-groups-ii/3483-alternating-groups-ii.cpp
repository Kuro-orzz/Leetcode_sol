class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int cnt = 0;
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] != colors[i-1])
                cnt++;
            else
                cnt = 0;
            if(cnt >= k-1)
                ans++;
        }
        cnt = 0;
        for(int i = colors.size()-k+2; i < colors.size(); i++){
            if(colors[i] != colors[i-1])
                cnt++;
            else
                cnt = 0;
            if(cnt >= k-1)
                ans++;
        }
        if(colors[0] != colors[colors.size()-1])
            cnt++;
        else
            cnt = 0;
        if(cnt >= k-1)
            ans++;
        for(int i = 1; i < k-1; i++){
            if(colors[i] != colors[i-1])
                cnt++;
            else
                cnt = 0;
            if(cnt >= k-1)
                ans++;
        }        
        return ans;
    }
};