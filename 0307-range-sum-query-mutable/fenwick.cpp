class NumArray {
public:
    vector<int> fen;
    NumArray(vector<int>& nums) {
        fen.resize(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++)
            update(i, nums[i]);
    }

    void update(int index, int val) {
        val -= sumRange(index, index);
        index++;
        while(index < fen.size()){
            fen[index] += val;
            index += (index & -index);
        }
    }
    
    int get(int pos){
        int ans = 0;
        while(pos){
            ans += fen[pos];
            pos -= (pos & - pos);
        }
        return ans;
    }

    int sumRange(int left, int right) {
        left++; right++;
        return get(right)-get(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */