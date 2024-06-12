// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int bin_search(int l, int r){
        while(l <= r){
            int mid = (1ll*l+r)>>1;
            if(isBadVersion(mid)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
    int firstBadVersion(int n) {
        return bin_search(1, n);
    }
};