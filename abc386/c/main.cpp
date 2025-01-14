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
    i64 k;
    string s, t;
    cin >> k >> s >> t;

    i32 mxsz = max(s.size(), t.size());
    bool flag = true;

    if (s.size() - t.size() == 0) {
        i32 mis = 0;
        rep(i, mxsz) {
            if (s[i] != t[i]) ++mis;
        }
        if (mis > 1) flag = false;
    } else if (abs((i32)s.size() - (i32)t.size()) == 1) {
        i32 s_cnt = 0, t_cnt = 0;
        while (s_cnt < s.size() and t_cnt < t.size() and s[s_cnt] == t[t_cnt]) ++s_cnt, ++t_cnt;
        if (s.size() < t.size()) {
            ++t_cnt;
        } else {
            ++s_cnt;
        }

        i32 mis = 0;
        while (s_cnt < s.size() and t_cnt < t.size()) {
            if (s[s_cnt] != t[t_cnt]) ++mis;
            ++s_cnt, ++t_cnt;
        }

        if (mis > 0) flag = false;
    } else {
        flag = false;
    }

    cout << (flag ? "Yes" : "No") << endl;
}