class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans, s;
        s.insert(0);
        for (int x : arr) {
            set<int> tmp;
            for (int v : s) {
                ans.insert(x);
                ans.insert(v | x);
                tmp.insert(x);
                tmp.insert(v | x);
            }
            s.swap(tmp);
        }
        return ans.size();
    }
};