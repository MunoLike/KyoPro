#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i32 h, w;
    cin >> h >> w;

    vector<vector<i32>> a(h, vector<i32>(w)), b(h, vector<i32>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }
    rep(i, h) {
        rep(j, w) {
            cin >> b[i][j];
        }
    }

    i64 opcnt = 0;
    rep(i, h - 1) {
        rep(j, w - 1) {
            i32 diff = b[i][j] - a[i][j];
            opcnt += abs(diff);
            rep(k, 2) rep(l, 2) {
                a[i + k][j + l] += diff;
            }
        }
    }

    bool is_eq = true;
    for (i32 i = 0; i < h - 1; ++i) {
        is_eq &= a[i][w - 1] == b[i][w - 1];
    }
    for (i32 i = 0; i < w - 1; ++i) {
        is_eq &= a[h - 1][i] == b[h - 1][i];
    }

    if (is_eq) {
        cout << "Yes\n";
        cout << opcnt << "\n";
    } else {
        cout << "No\n";
    }
}