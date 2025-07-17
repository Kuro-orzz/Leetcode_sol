template <int32_t mod>
struct ModInt {
    int32_t x;

    ModInt(): x(0) {}
    ModInt(int32_t _x): x(_x % mod) { x = x < 0 ? x + mod : x; }

    ModInt &operator += (const ModInt &p) {
        x += p.x;
        if (x >= mod) x -= mod;
        return *this;
    }

    ModInt &operator -= (const ModInt &p) {
        x -= p.x;
        if (x < 0) x += mod;
        return *this;
    }

    ModInt &operator *= (const ModInt &p) {
        x = (int32_t)(1ll * x * p.x % mod);
        return *this; 
    }

    ModInt &operator /= (const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    // ModInt += Int
    ModInt &operator += (int32_t t) { return *this += ModInt(t); }
    ModInt &operator -= (int32_t t) { return *this -= ModInt(t); }
    ModInt &operator *= (int32_t t) { return *this *= ModInt(t); }
    ModInt &operator /= (int32_t t) { return *this /= ModInt(t); }

    ModInt operator - () const { return ModInt(-x); } // -a;
    ModInt operator + () const { return ModInt(*this); } // +a;
    ModInt &operator ++ () { *this += 1; return *this; } // ++a;
    ModInt &operator -- () { *this -= 1; return *this; } // --a;
    ModInt operator ++ (int) { ModInt res = *this; *this += 1; return res; } // a++;
    ModInt operator -- (int) { ModInt res = *this; *this -= 1; return res; } // a--;

    // ModInt = ModInt + ModInt
    ModInt operator + (const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator - (const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator * (const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator / (const ModInt &p) const { return ModInt(*this) /= p; }

    // ModInt = ModInt + Int
    ModInt operator + (int32_t t) const { return ModInt(*this) += t; }
    ModInt operator - (int32_t t) const { return ModInt(*this) -= t; }
    ModInt operator * (int32_t t) const { return ModInt(*this) *= t; }
    ModInt operator / (int32_t t) const { return ModInt(*this) /= t; }

    // ModInt = Int + ModInt
    friend ModInt operator + (int32_t t, const ModInt &p) { ModInt res(t); res += p; return res; }
    friend ModInt operator - (int32_t t, const ModInt &p) { ModInt res(t); res -= p; return res; }
    friend ModInt operator * (int32_t t, const ModInt &p) { ModInt res(t); res *= p; return res; }
    friend ModInt operator / (int32_t t, const ModInt &p) { ModInt res(t); res /= p; return res; }

    bool operator == (const ModInt &p) const { return x == p.x; }
    bool operator != (const ModInt &p) const { return x != p.x; }
    bool operator < (const ModInt &p) const { return x < p.x; }
    bool operator <= (const ModInt &p) const { return x <= p.x; }
    bool operator > (const ModInt &p) const { return x > p.x; }
    bool operator >= (const ModInt &p) const { return x >= p.x; }

    bool operator == (int32_t t) const { return x == t; }
    bool operator != (int32_t t) const { return x != t; }
    bool operator < (int32_t t) const { return x < t; }
    bool operator <= (int32_t t) const { return x <= t; }
    bool operator > (int32_t t) const { return x > t; }
    bool operator >= (int32_t t) const { return x >= t; }

    ModInt inverse() const { return power(mod - 2); }

    ModInt power(int32_t b) const {
        assert(b >= 0);
        ModInt mul(x), ret(1);
        while (b) {
            if (b & 1) ret *= mul;
            mul *= mul;
            b /= 2;
        }
        return ret;
    }

    friend istream &operator >> (istream &in, ModInt &p) { 
        int32_t t;
        in >> t;
        p = ModInt<mod>(t);
        return in;
    }
    
    friend ostream &operator << (ostream &out, const ModInt &p) { return out << p.x; }

    int32_t get() const { return x; }
    static constexpr int32_t get_mod() { return mod; }
};

#define ll long long

class Solution {
public:
    static const int MOD = 1e9 + 7;
    using mint = ModInt<MOD>;

    vector<mint> fact;

    void preprocess() {
        fact[0] = 1;
        for (int i = 1; i < (int)fact.size(); i++) {
            fact[i] = fact[i-1] * i;
        }
    }

    mint comb(int n, int k) {
        if (k < 0 || k > n) return 0; 
        return fact[n] / (fact[n-k] * fact[k]);
    }

    int countGoodArrays(int n, int m, int k) {
        fact.resize(n+1);
        preprocess();
        mint t = m-1;
        t = t.power(n-k-1);
        return (comb(n-1, k) * m * t).get();
    }
};