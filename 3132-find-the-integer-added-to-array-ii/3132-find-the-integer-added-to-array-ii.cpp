class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = INT_MAX;
        for(int i = 0; i < nums1.size(); i++)
            for(int j = i+1; j < nums1.size(); j++){
                int pos = 0;
                int cnt = 0;
                int sub = INT_MAX;
                bool check  = true;
                while(pos < nums1.size()){
                    if(pos != i && pos != j){
                        if(sub == INT_MAX)
                            sub = nums2[cnt]-nums1[pos];    
                        else{
                            if(nums2[cnt] - nums1[pos] != sub){
                                check = false;
                                break;
                            }
                        }
                        cnt++;
                    }
                    pos++;
                }
                if(check)
                    ans = min(ans, sub);
            }
        return ans;
    }
};