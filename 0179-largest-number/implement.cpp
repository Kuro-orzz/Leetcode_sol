class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for(int x : nums)
            a.push_back(to_string(x));
        auto cmp = [&](string a, string b){
            return a+b > b+a;
        };
        sort(a.begin(), a.end(), cmp);
        if(a[0] == "0")
            return "0";
        string ans = "";
        for(string s : a)
            ans += s;
        return ans;
    }
};