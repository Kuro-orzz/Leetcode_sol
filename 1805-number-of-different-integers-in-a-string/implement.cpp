class Solution {
public:
    string f(string s){
        int i = 0;
        while(i < s.size() && s[i] == '0')
            i++;
        if(i == s.size()) return "0";
        return s.substr(i);
    }

    int numDifferentIntegers(string word) {
        set<string> st;
        string s = "";
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= '0' && word[i] <= '9')
                s += word[i];
            else if(s != ""){
                st.insert(f(s));
                s = "";
            }
        }
        if(s != "") st.insert(f(s));
        return st.size();
    }
};