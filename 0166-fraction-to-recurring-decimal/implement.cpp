/*
    I hate edge case
    So lazy to implement
    Just want some problem using more algo than implement
*/
#define ll long long

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) return "0";
        bool isNeg = (1ll * numerator * denominator > 0 ? false : true);
        ll upper = llabs(numerator);
        ll lower = llabs(denominator);
        string integer_part = to_string(upper / lower);
        string decimal_part = "";
        ll cur = upper % lower;
        int pos = 0;
        map<int, int> mp;
        while (cur) {
            cur *= 10;
            int tmp = cur / lower;
            if (mp.count(cur)) {
                decimal_part.insert(mp[cur], "(");
                decimal_part += ')';
                break;
            }
            decimal_part += to_string(tmp);
            mp[cur] = pos;
            cur %= lower;
            pos++;
        }
        string ans = "";
        if (isNeg) ans += '-';
        ans += integer_part;
        if (decimal_part != "") ans += "." + decimal_part;
        return ans;
    }
};