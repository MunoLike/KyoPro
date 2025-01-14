#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (i32 i = 1; i <= (n); (i)++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const i32 dx[] = {0, 1, 0, -1, -1, 1, 1, -1};

template <class S, class T>
inline S prevent_oor(S a, const T b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    return a;
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
    i64 n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<i64> x(n), forw, rev;
    rep(i, n) {
        i64 x;
        cin >> x;
        if (s[i] == '1')
            forw.emplace_back(x);
        else
            rev.emplace_back(x);
    }

    sort(all(rev));
    sort(all(forw));

    i64 cnt = 0;

    rep(i, rev.size()) {
        i32 l = lower_bound(all(forw), rev[i] - t * 2) - forw.begin();
        i32 r = lower_bound(all(forw), rev[i]) - forw.begin();
        cnt += r - l;
    }

    cout << cnt << '\n';
}