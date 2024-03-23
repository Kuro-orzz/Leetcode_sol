class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int a[2006];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < arr.size(); i++)
            a[arr[i]+1000] += 1;
        int st[2006];
        memset(st, 0, sizeof(st));
        for(int i = 0; i <= 2000; i++){
            if(a[i] > 0 && st[a[i]] == 1)
                return false;
            else if(a[i] > 0 && st[a[i]] == 0)
                st[a[i]]++;
        }
        return true;
    }
};