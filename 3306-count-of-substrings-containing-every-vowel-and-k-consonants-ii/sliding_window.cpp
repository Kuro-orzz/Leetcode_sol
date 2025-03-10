class Solution {
public:
    int isVowel(char c){
        if(c == 'a') return 1;
        else if(c == 'e') return 2;
        else if(c == 'i') return 3;
        else if(c == 'o') return 4;
        else if(c == 'u') return 5;
        return 0;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> pos;
        for(int i = 0; i < n; i++){
            if(!isVowel(word[i]))
                pos.push_back(i);
        }
        pos.push_back(n);
        long long ans = 0;
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<char, int> mp;
        while(r < n){
            bool v = isVowel(word[r]);
            if(v) mp[word[r]]++;
            else cnt++;
            int t = *upper_bound(pos.begin(), pos.end(), r);
            while(l < r && mp.size() == 5 && cnt >= k){
                if(cnt == k)
                    ans += t-r;
                v = isVowel(word[l]);
                if(v) mp[word[l]]--;
                else cnt--;
                if(!mp[word[l]])
                    mp.erase(word[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};