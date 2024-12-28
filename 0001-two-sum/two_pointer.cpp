class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x = 0;
        int y = nums.size()-1;
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        vector<int> res;
        while(x < y){
            if(tmp[x] + tmp[y] < target)
                x++;
            else if(tmp[x] + tmp[y] > target)
                y--;
            else{
                for(int i = 0; i < nums.size(); i++)
                    if(nums[i] == tmp[x] || nums[i] == tmp[y])
                        res.push_back(i);
                break;
            }
        }
        if(res[0] > res[1])
            swap(res[0], res[1]);
        return res;
    }
};