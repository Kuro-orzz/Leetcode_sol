class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.size();
        int res_len = n - numFriends + 1;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (word[pos] < word[i]) {
                pos = i;
            } else if (word[pos] == word[i]) {
                int p1 = pos, p2 = i;
                int lim = min(n, p2 + res_len);
                bool gt = false;
                while (p2 < lim) {
                    if (word[p1] < word[p2]) {
                        gt = true;
                        break;
                    } else if (word[p1] > word[p2]) {
                        break;
                    }
                    p1++, p2++;
                }
                if (gt) pos = i;
            }
        }
        return word.substr(pos, min(n-pos,res_len));
    }
};