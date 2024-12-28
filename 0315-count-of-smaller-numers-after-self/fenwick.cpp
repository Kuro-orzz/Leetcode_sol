class Solution {
public:
    vector<int> fen;

    void update(int pos, int val){
        while(pos < fen.size()){
            fen[pos] += val;
            pos += (pos & -pos);
        }
    }

    int get(int pos){
        int ans = 0;
        while(pos){
            ans += fen[pos];
            pos -= (pos & -pos);
        }
        return ans;
    }

    vector<int> countSmaller(vector<int>& nums) {
        fen.resize(20002, 0);
        vector<int> ans(nums.size());
        for(int i = nums.size()-1; i >= 0; i--){
            nums[i] += 10001;
            ans[i] = get(nums[i]-1);
            update(nums[i], 1);
        }
        return ans;
    }
};