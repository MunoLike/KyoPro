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
    i32 t;
    cin >> t;

    rep(_, t) {
        i32 n;
        string s;
        cin >> n >> s;

        vector<pair<i32, i32>> one_lr;
        bool in_one = false;
        rep(i, n) {
            if (!in_one and s[i] == '1') {
                in_one = true;
                one_lr.emplace_back(i, i);
            } else if (in_one and s[i] == '0') {
                in_one = false;
                one_lr.back().second = i - 1;
            }
        }

        if (in_one) {
            one_lr.back().second = n - 1;
        }

        i32 cnt = 0;
        i32 l = 0, r = 0;

        if (!one_lr.empty()) {
            l = one_lr[0].second;
            for (i32 i = 1; i < one_lr.size(); i++) {
            }
        }
    }
}