class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long cnt1 = 0;
        for(int i = 0; i < arr.size(); i++){
            cnt1 += abs(arr[i]-brr[i]);
        }
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        long long cnt2 = 0;
        for(int i = 0; i < arr.size(); i++)
            cnt2 += abs(arr[i]-brr[i]);
        return min(cnt1, cnt2+k);
    }
};