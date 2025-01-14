#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vvi32 = vector<vector<i32>>;
using vvi64 = vector<vector<i64>>;
using mint = modint998244353;
#define rep(i, n) for (i32 i = 0; i < (n); i++)
#define rep1(i, n) for (i32 i = 1; i <= (n); (i)++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const i32 dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
const string lrud("URDL");

template <class S, class T>
inline S prevent_oor(S a, const T b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    return a;
}

template <class S, class T>
inline bool is_in(const T lower, S a, const T upper) {
    return a < upper && lower <= a;
}

template <class S, class T>
inline S chmax(S &a, T b) {
    if (a < b) {
        a = b;
    }
    return a;
}

template <class S, class T>
inline S chmin(S &a, T b) {
    if (a > b) {
        a = b;
    }
    return a;
}

inline int64_t div_floor(int64_t a, int64_t b) {
    if (b < 0) {
        a *= -1;
        b *= -1;
    }
    if (a < 0) {
        return (a + 1) / b - 1;
    } else {
        return a / b;
    }
}

inline int64_t div_ceil(int64_t a, int64_t b) {
    return div_floor(a + b - 1, b);
}

int main() {
    i32 n;
    cin >> n;
    vector<i64> q(n), r(n);
    rep(i, n) cin >> q[i] >> r[i];

    i32 m;
    cin >> m;
    vector<i64> t(m), d(m);
    rep(i, m) cin >> t[i] >> d[i], --t[i];

    rep(i, m) {
        i32 kind = t[i];
        if (d[i] % q[kind] == r[kind]) {
            cout << d[i] << '\n';
        } else {
            i64 ins_mod = (d[i] / q[kind]) * q[kind] + r[kind];
            if (ins_mod < d[i]) ins_mod += q[kind];
            cout << ins_mod << '\n';
        }
    }
}