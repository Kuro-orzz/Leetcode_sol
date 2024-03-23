#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = n;
        for(int i = 0; i < n; i++){
            string x = "";
            x += s[i];
            for(int j = i+1; j < n; j++){
                x += s[j];
                bool ok = true;
                int l = 0, r = x.length()-1;
                while(l < r){
                        if(x[l] == x[r]) l++, r--;
                        else{
                            ok = false;
                            break;
                        }
                    }
                if(ok)
                    ans++;
            }
        }
        return ans;
    }
};