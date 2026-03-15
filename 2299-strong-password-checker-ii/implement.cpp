class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if (n < 8) return false;
        bool lower, upper, digit, special_char, adj_char;
        lower = upper = digit = special_char = false;
        adj_char = true;
        for (int i = 0; i < n; i++) {
            char c = password[i];
            if (isalpha(c) && islower(c)) lower = true;
            else if (isalpha(c) && isupper(c)) upper = true;
            if (isdigit(c)) digit = true;
            if (!isalnum(c)) special_char = true;
            if (i && password[i-1] == c) adj_char = false;
        }
        return lower && upper && digit && special_char && adj_char; 
    }
};