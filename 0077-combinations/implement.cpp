class Solution {
public:
    vector<vector<int>> ans;
    vector<int> a;
    int n, k;
    
    void backtrack(int idx) {
        if(a.size() == k){
            vector<int> v;
            for(int x : a) v.push_back(x);
            ans.push_back(v);
            return;
        }
        for(int i = idx; i <= n; i++){
            a.push_back(i);
            backtrack(i+1);
            a.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        backtrack(1);
        return ans;
    }
};