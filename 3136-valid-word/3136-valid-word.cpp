class Solution {
public:
    bool isValid(string word) {
        int cnt = 0;
        bool vowel = false;
        bool consonant = false;
        for(int i = 0; i < word.size(); i++){
            if(tolower(word[i]) == 'a' || tolower(word[i]) == 'i' || tolower(word[i]) == 'u' || tolower(word[i]) == 'e' || tolower(word[i]) == 'o'){
                vowel = true;
            }
            else if(toupper(word[i]) >= 'A' && toupper(word[i]) <= 'Z'){
                consonant = true;
            }
            if(isdigit(word[i]) || isalpha(word[i]))
                cnt++;
            if(!isdigit(word[i]) && !isalpha(word[i]))
                return false;
        }
        return (vowel && consonant && cnt >= 3);
    }
};