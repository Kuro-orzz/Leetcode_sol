class Solution {
public:
    struct fen{
        vector<int> BIT;
        fen(int n): BIT(n+1, 0){}
        void update(int pos, int val){
            while(pos < BIT.size()){
                BIT[pos] += val;
                pos += pos&-pos;
            }
        }
        int get(int pos){
            int res = 0;
            while(pos){
                res += BIT[pos];
                pos -= pos&-pos;
            }      
            return res;  
        }
        void update_range(int l, int r, int val){
            update(l, val);
            update(r+1, -val);
        }
    };
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        fen f(n);
        for(int i = 0; i < nums.size(); i++)
            f.update_range(i+1, i+1, nums[i]);
        int ans = 0;
        for(int i = 0; i < n-k+1; i++){
            if(f.get(i+1) > 1){
                int t = f.get(i+1);
                int tmp = t-nums[i];
                f.update_range(i+1, i+1, tmp%2 ? -t+(nums[i]^1) : -t+nums[i]);
            }
            if(f.get(i+1) != 1){
                f.update_range(i+1, i+k, 1);
                ans++;
            }
        }
        for(int i = n-k+1; i < n; i++){
            int t = f.get(i+1);
            int tmp = t-nums[i];
            f.update_range(i+1, i+1, tmp%2 ? -t+(nums[i]^1) : -t+nums[i]);
            if(f.get(i+1) != 1){
                cout << f.get(i+1);
                return -1;
            }
        }
        return ans;
    }
};