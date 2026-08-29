#define ll long long
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())

template <typename T>
struct Fenwick{
    int n;
    vector<T> fen;

    Fenwick(int _n): n(_n), fen(_n+1) {}

    void update(int pos, T val) {
        for (; pos <= n; pos += pos & -pos) {
            fen[pos] += val;
        }
    }

    T get(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= pos & -pos) {
            ans += fen[pos];
        }
        return ans;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    void update_range(int l, int r, T val){
        update(l, val);
        update(r+1, -val);
    }

    void reset() {
        fill(all(fen), T(0));
    }
};

template <typename T>
struct Compress {
    int cnt = 1;
    map<T, int> compressed;
    vector<T> decompress;

    Compress(const vector<T> &a) {
        decompress.push_back(T(0));
        vector<T> b = a;
        sort(all(b));
        unique(b);
        for (T x : b) {
            compressed[x] = cnt++;
            decompress.push_back(x);
        }
    }

    int operator[] (const T &x) const { assert(compressed.count(x)); return compressed.at(x); }

    T getDecomp(int i) const { return decompress[i]; }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n+1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + (nums[i-1] == target ? 1 : -1);
        }
        ll ans = 0;
        Compress<int> comp(pref);
        Fenwick<int> BIT(n + 1);
        for (int i = 0; i <= n; i++) {
            ans += BIT.get(comp[pref[i]] - 1);
            BIT.update(comp[pref[i]], 1);
        }
        return ans;
    }
};