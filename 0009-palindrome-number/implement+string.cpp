class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        if(s == tmp)
            return true;
        else
            return false;
    }
};