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
    i32 n, x;
    cin >> n >> x;
    vector<pair<i64, i64>> v1, v2, v3;
    rep(i, n) {
        i64 v, a_in, c_in;
        cin >> v >> a_in >> c_in;
        switch (v) {
            case 1:
                v1.emplace_back(a_in, c_in);
                break;
            case 2:
                v2.emplace_back(a_in, c_in);
                break;
            case 3:
                v3.emplace_back(a_in, c_in);
                break;
            default:
                break;
        }
    }

    auto f = [](pair<i64, i64> &lhs, pair<i64, i64> &rhs) {
        return lhs.first * rhs.second > rhs.first * lhs.second;
    };

    rep(i, 3) {
        sort(all(a[i], [](auto lhs, auto rhs) {
            return lhs
        }));
    }
}