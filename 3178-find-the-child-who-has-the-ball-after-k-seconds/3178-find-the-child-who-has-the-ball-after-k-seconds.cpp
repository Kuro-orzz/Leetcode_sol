class Solution {
public:
    int numberOfChild(int n, int k) {
        int t = k % (2*n-2);
        if(t < n)
            return t;
        else{
            return n-(t-n+2);
        }
    }
};