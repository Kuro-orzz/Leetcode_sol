class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2) return false;
        stack<int> st1, st2;
        for(int i = 0; i < s.size(); i++){
            if(locked[i] == '0') st1.push(i);
            else if(s[i] == '(') st2.push(i);
            else{
                if(!st2.empty()) st2.pop();
                else if(!st1.empty()) st1.pop();
                else return false;
            }
        }
        while(!st1.empty() && !st2.empty() && st1.top() > st2.top()){
            st1.pop();
            st2.pop();
        }
        return st2.empty();
    }
};