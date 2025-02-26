class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> mark(17, 0);
        for(string s : nums){
            int t = bitset<32>(s).to_ulong();
            if(t < 17) mark[t] = 1;
        }    
        for(int i = 0; i < 17; i++)
            if(!mark[i])
                return bitset<32>(i).to_string().substr(32-n);
        return "";
    }
};