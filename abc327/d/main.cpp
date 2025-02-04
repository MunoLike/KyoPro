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
    i32 n, m;
    cin >> n >> m;
    vector<i32> a(m), b(m);
    rep(i, m) cin >> a[i];
    rep(i, m) cin >> b[i];

    map<i32, i32> mp_a, mp_b;
    rep(i, m) {
        mp_a.emplace(a[i], 1);
        mp_b.emplace(b[i], 1);
    }

    rep(i, m) {
        ++mp_a[b[i]];
        ++mp_b[a[i]];
        if (mp_a[b[i]] > 2 or mp_b[a[i]] > 2) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}