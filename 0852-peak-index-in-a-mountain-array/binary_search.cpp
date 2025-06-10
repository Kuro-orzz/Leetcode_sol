class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            mid = max(mid, 1);
            mid = min(mid, (int)arr.size());
            if (arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {
                l = mid + 1;
            } else if (arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1]) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};