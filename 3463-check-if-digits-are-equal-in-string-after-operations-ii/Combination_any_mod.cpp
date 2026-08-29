#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second
using i128 = __int128;

ll binPow(ll a, ll b, ll M) {
    a %= M;
    ll res = 1 % M;
    while (b) {
        if (b & 1) res = (i128)res * a % M;
        a = (i128)a * a % M;
        b /= 2;
    }
    return res;
}

vector<ll> primeFactor(ll n) {
    vector<ll> factor;
    for (int i : {2, 3, 5}) {
        while (n % i == 0) {
            n /= i;
            factor.push_back(i);
        }
    }
    int inc[] = {4, 2, 4, 2, 4, 6, 2, 6};
    int j = 0;
    ll lim = sqrtl(n);
    while (lim > 0 && lim > n / lim) lim--;
    for (ll i = 7; i <= lim; i += inc[j%8], j++) {
        if (n % i) continue;
        while(n % i == 0) {
            n /= i;
            factor.push_back(i);
        }
        lim = sqrtl(n);
        while (lim > 0 && lim > n / lim) lim--;
    }
    if (n > 1) factor.push_back(n);
    return factor;
}

vector<pll> primeFactorPow(ll n) {
    vector<pll> res;
    for (ll p : primeFactor(n))
        if (!res.empty() && res.back().fi == p) res.back().se++;
        else res.push_back({p, 1});
    return res;
}

// C(n, k) % p^e
// O(p^e) build and memory, O(log n) per query, require p^e <= 1e7
struct CombPrimePower {
    ll p, e, pe, phi, unit;
    vector<ll> f, pw;   // f[i] = prod of j in [1, i] with p not dividing j, % pe
                        // pw[i] = p^i % pe
    // every value here is < pe <= 1e7 so products stay under 1e14, plain ll is enough

    CombPrimePower() {}
    CombPrimePower(ll _p, ll _e) : p(_p), e(_e) {
        pe = 1;
        for (ll i = 0; i < e; i++) pe *= p;
        phi = pe - pe / p;                  // a^-1 = binPow(a, phi-1, pe)
        f.resize(pe);
        f[0] = 1 % pe;
        for (ll i = 1; i < pe; i++) f[i] = (i % p == 0) ? f[i-1] : f[i-1] * i % pe;
        unit = f[pe-1];                     // +1 or -1, so only parity matters in fact()
        pw.resize(e+1);
        pw[0] = 1 % pe;
        for (ll i = 1; i <= e; i++) pw[i] = pw[i-1] * p % pe;
    }

    // kept apart from fact() on purpose: it is the cheap half, and letting comb()
    // bail out on it first skips 3 fact() calls, worth 3x on m with many factors
    ll expo(ll n) {
        ll t = 0;
        while (n > 0) {
            n /= p;
            t += n;
        }
        return t;
    }

    // same as factmod() in Factorial.h but for p^e instead of p
    ll fact(ll n) {
        ll a = 1 % pe;
        while (n > 0) {
            if ((n / pe) & 1) a = a * unit % pe;
            a = a * f[n % pe] % pe;
            n /= p;
        }
        return a;
    }

    ll comb(ll n, ll k) {
        if (k < 0 || k > n) return 0;
        ll E = expo(n) - expo(k) - expo(n-k);
        if (E >= e) return 0;
        ll d = fact(k) * fact(n-k) % pe;    // multiply first, one inverse instead of two
        return fact(n) * binPow(d, phi-1, pe) % pe * pw[E] % pe;
    }
};

// C(n, k) % m for any m
// O(m) build and memory, O(log^2 n) per query, require every p^e <= 1e7
struct CombAnyMod {
    ll m;
    vector<CombPrimePower> pp;
    vector<ll> w;   // CRT weight, w[i] = M_i * (M_i^-1 % pe_i) % m with M_i = m / pe_i

    CombAnyMod() {}
    CombAnyMod(ll _m) : m(_m) {
        for (pll pe : primeFactorPow(m)) pp.push_back(CombPrimePower(pe.fi, pe.se));
        for (CombPrimePower &c : pp) {      // w does not depend on n, k
            ll M = m / c.pe;
            w.push_back((i128)M * binPow(M % c.pe, c.phi - 1, c.pe) % m);
        }
    }

    ll comb(ll n, ll k) {
        ll res = 0;
        for (int i = 0; i < (int)pp.size(); i++) {
            ll a = pp[i].comb(n, k);
            if (a) res = (res + (i128)a * w[i] % m) % m;
        }
        return res;
    }
};

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        CombAnyMod C(10);
        int firstNum = 0, secondNum = 0;
        for (int i = 1; i <= n-1; i++) {
            int nCk = C.comb(n-2, i-1);
            firstNum = (firstNum + nCk * (s[i-1]-'0')) % 10;
            secondNum = (secondNum + nCk * (s[i] - '0')) % 10;
        }
        return firstNum == secondNum;
    }
};