#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
    string s;
    cin >> n >> s;
    vector<pair<i64, i64>> w(n);  // 体重，子供か大人
    i32 x = 0;
    rep(i, n) {
        cin >> w[i].first;
        w[i].second = s[i] - '0';
        if (w[i].second == 1) ++x;
    }

    sort(all(w));

    i32 ans = x;
    rep(i, n) {
        if (w[i].second == 0)
            ++x;
        else
            --x;

        if (i < (n - 1)) {
            if (w[i].first != w[i + 1].first) chmax(ans, x);
        } else {
            chmax(ans, x);
        }
    }
    cout << ans << endl;
}