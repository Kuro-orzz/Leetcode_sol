class Solution {
public:
    char repeatedCharacter(string s) {
        int a[30];
        memset(a, 0 ,sizeof(a));
        for(int i = 0; i < s.length(); i++)
            if(a[s[i]-'a'] == 0)
                a[s[i]-'a']++;
            else
                return s[i];
        return -1;
    }
};