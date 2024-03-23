class Solution {
public:
    int pivotInteger(int n) {
        auto check = [&](int x, int n){
            int l = x*(1+x)/2;
            int r = n*(1+n)/2-l+x;
            if(l < r)
                return -1;
            else if(l > r)
                return 0;
            else
                return 1;
        };
        auto pivot = [&](int l, int r){
            while(l <= r){
                int mid = (l+r)/2;
                if(check(mid, n) == -1)
                    l = mid+1;
                else if(check(mid, n) == 0)
                    r = mid-1;
                else
                    return mid;
            }
            return -1;
        };
        return pivot(1, n);
    }
}; 