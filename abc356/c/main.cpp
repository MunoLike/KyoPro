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
    i32 n, m, k;
    cin >> n >> m >> k;

    vector<i32> trial(m);
    vector<bool> result(m);

    rep(i, m) {
        i32 c;
        cin >> c;
        rep(j, c) {
            i32 a;
            cin >> a;
            --a;
            trial[i] |= (1 << a);
        }
        char in;
        cin >> in;
        result[i] = in == 'o' ? true : false;
    }

    i32 ans = 0;

    for (u32 key = 0; key < (1UL << n); ++key) {
        bool ok = true;
        rep(i, m) {
            i32 cnt = popcount(key & trial[i]);
            if (cnt < k and result[i]) ok = false;
            if (cnt >= k and !result[i]) ok = false;
        }
        if (ok) ans++;
    }

    cout << ans << endl;
}