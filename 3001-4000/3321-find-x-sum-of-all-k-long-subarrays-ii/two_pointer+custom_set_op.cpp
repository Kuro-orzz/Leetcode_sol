#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    map<int, int> cnt;
    set<pii> top_x, other;
    ll sum = 0;

    void update_top_x(int old_fre, int new_fre, int val) {
        top_x.erase({old_fre, val});
        sum -= 1ll * val * old_fre;
        if (new_fre) top_x.insert({new_fre, val});
        sum += 1ll * val * new_fre;
    }

    void update_other(int old_fre, int new_fre, int val) {
        other.erase({old_fre, val});
        if (new_fre) other.insert({new_fre, val});
    }

    void top_x_TO_other(int old_fre, int new_fre, int val) {
        pii rm_top_x = {old_fre, val};
        pii to_other = {new_fre, val};
        top_x.erase(rm_top_x);
        sum -= 1ll * val * old_fre;
        if (new_fre) other.insert(to_other);
    }

    void other_TO_top_x(int old_fre, int new_fre, int val) {
        pii rm_other = {old_fre, val};
        pii to_top_x = {new_fre, val};
        other.erase(rm_other);
        if (new_fre) top_x.insert(to_top_x);
        sum += 1ll * val * new_fre;
    }

    void add(int val) {
        int old_fre = cnt[val];
        int new_fre = old_fre + 1;
        if (top_x.count({old_fre, val})) {
            update_top_x(old_fre, new_fre, val);
        } else {
            if (!top_x.empty()) {
                pii mn_top = *top_x.begin();
                if (new_fre > mn_top.fi || (new_fre == mn_top.fi && val > mn_top.se)) {
                    other_TO_top_x(old_fre, new_fre, val);
                    top_x.erase(mn_top);
                    sum -= 1ll * mn_top.fi * mn_top.se;
                    other.insert(mn_top);
                } else {
                    update_other(old_fre, new_fre, val);
                }
            } else {
                update_other(old_fre, new_fre, val);
            }
        }
    }

    void remove(int val) {
        int old_fre = cnt[val];
        int new_fre = old_fre - 1;
        if (other.count({old_fre, val})) {
            update_other(old_fre, new_fre, val);
        } else if (top_x.count({old_fre, val})) {
            if (!other.empty()) {
                pii mx_other = *other.rbegin();
                if (new_fre < mx_other.fi || (new_fre == mx_other.fi && val < mx_other.se)) {
                    top_x_TO_other(old_fre, new_fre, val);
                    other.erase(mx_other);
                    top_x.insert(mx_other);
                    sum += 1ll * mx_other.fi * mx_other.se;
                } else {
                    update_top_x(old_fre, new_fre, val);
                }
            } else {
                update_top_x(old_fre, new_fre, val);
            }
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int l = 0, r = 0;
        vector<ll> ans;

        while (r < n) {
            if (top_x.size() < x) {
                int old_fre = cnt[nums[r]];
                update_top_x(old_fre, old_fre+1, nums[r]);
            } else {
                add(nums[r]);
            }
            cnt[nums[r++]]++;
            
            // [l, r] == k ?
            if (r - l < k) continue;

            ans.push_back(sum);
            
            remove(nums[l]);
            cnt[nums[l++]]--;
        }
        return ans;
    }
};