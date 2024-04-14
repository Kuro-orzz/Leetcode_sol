class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        bool prime[106];
        memset(prime, true, sizeof prime);
        prime[0] = prime[1] = false;
        for(int i = 2; i <= 100; i++){
            bool check = true;
            for(int j = 2; j <= sqrt(i); j++)
                if(i % j == 0){
                    check = false;
                    break;
                }
            if(!check)
                prime[i] = false;
        }
        vector<int> memo;
        for(int i = 0; i < nums.size(); i++)
            if(prime[nums[i]])
                memo.push_back(i);
        return abs(memo[0]-memo[memo.size()-1]);
    }
};