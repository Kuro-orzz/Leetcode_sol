class Solution {
public:
    vector<string> ans;
    void gen(string s, int k, int n, int l, int r){
        if(k == 2*n){
            ans.push_back(s);
            return;
        }
        if(l == r)
            gen(s+'(', k+1, n, l+1, r); 
        if(l > r){
            if(l == n)
                gen(s+')', k+1, n, l, r+1);
            else{
                gen(s+'(', k+1, n, l+1, r);
                gen(s+')', k+1, n, l, r+1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string x = "";
        gen(x, 0, n, 0, 0);
        return ans;
    }
};