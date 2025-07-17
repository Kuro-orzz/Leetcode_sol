class FindSumPairs {
public:
    unordered_map<int, int> cnt;
    vector<int> a, b;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int x : nums2) cnt[x]++;
        a = nums1;
        b = nums2;    
    }
    
    void add(int index, int val) {
        cnt[b[index]]--;
        b[index] += val;
        cnt[b[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (int x : a) {
            res += cnt[tot - x];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */