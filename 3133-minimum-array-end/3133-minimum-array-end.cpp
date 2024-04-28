class Solution {
public:
    long long minEnd(int n, int x) {
        if(n == 1)
            return x;
        vector<int> bit(64, 0);
        bitset<32> bin(x);
        for(int i = 0; i < 32; i++)
            bit[i] = (bin[i] == 1 ? 1 : 0);
        vector<int> ans = bit;
        while(n){
            int tmp = __lg(n);
            if(!tmp)
                break;
            if((1 << __lg(n)) == n){
                int t = 0;
                for(int i = 0; i < 64; i++){
                    if(ans[i] == 0){
                        ans [i] = 1;
                        t++;
                    }
                    if(t == tmp)
                        break;
                }
            }
            else{
                int t = 0;
                for(int i = 0; i < 64; i++){
                    if(!ans[i])
                        t++;
                    if(t == tmp+1){
                        ans[i] = 1;
                        break;
                    }
                }
            }
            n -= (1 << __lg(n));
        }
        long long res = 0;
        for(int i = 0; i < 64; i++){
            if(ans[i])
                res += (1ll << i);        
        }
        return res;
    }
};