#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string x : words){
            int i = 0;
            int j = x.length()-1;
            bool ok = true;
            while(i < j){
                if(x[i] == x[j])
                    i++, j--;
                else{
                    ok = false;
                    break;
                }
            }
            if(ok)
                return x;
        }
        return "";
    }
};