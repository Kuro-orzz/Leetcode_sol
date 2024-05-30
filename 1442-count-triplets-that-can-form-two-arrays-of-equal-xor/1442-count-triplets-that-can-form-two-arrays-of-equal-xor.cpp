class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int t = arr[i];
            for(int j = i+1; j < n; j++){
                t ^= arr[j];
                if(!t)
                    ans += j-i;
            }
        }
        return ans;
    }
};