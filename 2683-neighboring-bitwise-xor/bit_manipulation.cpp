class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int a = 0, b = 1;
        for(int i = 1; i < n; i++){
            a ^= derived[i-1];
            b ^= derived[i-1];
        }
        return (a^0 == derived[n-1]) || (b^1 == derived[n-1]); 
    }
};