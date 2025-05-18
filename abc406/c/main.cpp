#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
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
    vector<i32> p(n);
    rep(i, n) { cin >> p[i]; }

    vector<i32> table(n - 1);
    for (i32 i = 0; i < n - 1; ++i) {
        table[i] = (p[i + 1] < p[i]) ? 0 : 1;
    }

    vector<pair<i32, i32>> rle;
    rle.emplace_back(1, 0);
    for (i32 i = 0; i < n - 1; ++i) {
        auto [v, c] = rle.back();
        if (table[i] == v) {
            ++rle.back().second;
        } else {
            rle.emplace_back(table[i], 1);
        }
    }

    i64 ans = 0;
    rep(i, rle.size()) {
        auto [v, c] = rle[i];
        if (v == 0) {
            i32 l = 0;
            i32 r = 0;
            if (0 < i) l = rle[i - 1].second;
            if (i + 1 < rle.size()) r = rle[i + 1].second;
            ans += (i64)l * r;
        }
    }
    cout << ans << endl;
}