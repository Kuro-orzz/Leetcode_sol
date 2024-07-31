class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        bitset<32> a(n), b(k);
        for(int i = 0; i < 32; i++){
            if(a[i] == 1 && b[i] == 0)
                ans++;
            else if(a[i] == 0 && b[i] == 1)
                return -1;
        }
        return ans;
    }
};