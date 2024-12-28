class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string tmp;
        while(ss >> tmp){}
        return tmp.size();
    }
};