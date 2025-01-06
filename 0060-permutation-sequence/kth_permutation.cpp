class Solution {
public:
    int f[10];

    void init(){
        f[0] = 1;
        for(int i = 1; i < 10; i++)
            f[i] = f[i-1] * i;
    }

    string getPermutation(int n, int k) {
        init();
        string ans = "";
        int t = n;
        vector<int> v(10);
        iota(v.begin(), v.end(), 0);
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(f[i]*j < k){
                    ans += char(v[j+1]+'0');
                    v.erase(v.begin()+j+1);
                    k -= f[i]*j;
                    break;
                }
            }
            t--;
        }   
        return ans;
    }
};