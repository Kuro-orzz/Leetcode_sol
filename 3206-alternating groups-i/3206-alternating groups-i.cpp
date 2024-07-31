class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        if(colors[0] != colors[1] && colors[0] != colors[colors.size()-1])
            ans++;
        if(colors[colors.size()-1] != colors[0] && colors[colors.size()-1] != colors[colors.size()-2])
            ans++;
        for(int i = 1; i < colors.size()-1; i++){
            if(colors[i] != colors[i-1] && colors[i] != colors[i+1])
                ans++;
        }
        return ans;
    }
};