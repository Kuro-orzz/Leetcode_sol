class Solution {
public:
    int k;
    vector<string> v;

    void backtrack(string &s, int &n){
        if(v.size() == this->k) return;
        if(s.size() == n){
            v.push_back(s);
            return;
        }
        for(char i = 'a'; i <= 'c'; i++){
            if(s.size() && s.back() == i) continue;
            s += i;
            backtrack(s, n);
            s.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        this->k = k;
        string s = "";
        backtrack(s, n);
        return v.size() == k ? v.back() : "";
    }
};