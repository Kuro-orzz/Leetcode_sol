using T = tuple<string, string, bool>;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<T> info(n);
        for (int i = 0; i < n; i++) {
            info[i] = {code[i], businessLine[i], isActive[i]};
        }
        auto cmp = [&](T &a, T &b) {
            if (get<1>(a)[0] == get<1>(b)[0]) return get<0>(a) < get<0>(b);
            return get<1>(a)[0] < get<1>(b)[0];
        };
        sort(info.begin(), info.end(), cmp);
        vector<string> ans;
        set<string> s({"electronics", "grocery", "pharmacy", "restaurant"});
        for (int i = 0; i < n; i++) {
            bool isValid = true;
            auto [id, business, active] = info[i];
            if (id == "") isValid = false;
            for (int j = 0; j < id.size(); j++) {
                if (!iswalnum(id[j]) && id[j] != '_') isValid = false;
            }
            if (s.find(business) == s.end()) isValid = false;
            if (!active) isValid = false;
            if (isValid) ans.push_back(id);
        }
        return ans;
    }
};