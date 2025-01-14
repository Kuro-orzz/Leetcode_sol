class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> v(A.size());
        for(int i = 0; i < A.size(); i++)
            v[A[i]-1] = i;
        vector<int> ans(A.size());
        for(int i = 0; i < B.size(); i++)
            ans[max(v[B[i]-1], i)]++;
        for(int i = 1; i < A.size(); i++)
            ans[i] += ans[i-1];
        return ans;
    }   
};