class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for(int i = 0; i <= n-m*k; i++){
            vector<int> v(arr.begin()+i, arr.begin()+i+m);
            int idx = i+m;
            bool ch = true;
            for(int j = 0; j < k-1; j++){
                vector<int> t(arr.begin()+idx, arr.begin()+idx+m);
                if(v != t) ch = false;
                idx += m;
            }
            if(ch) return true;
        }
        return false;
    }
};