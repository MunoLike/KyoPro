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
    vector<i64> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(all(a));
    sort(all(b));

    auto judge = [&](i64 val) {
        i32 n_a = 0, n_b = 0;
        // for (auto i : a)
        //     if (i <= val) ++n_a;

        // for (auto i : b)
        //     if (i >= val) ++n_b;
        i32 n_a = (upper_bound(all(a), val) - a.begin());
        i32 n_b = m - (lower_bound(all(b), val) - b.begin());
        return n_a >= n_b;
    };

    i64 ok = 1001001001, ng = 0;
    while (ok - ng > 1) {
        i64 val = (ok + ng) / 2;
        if (judge(val)) {
            ok = val;
        } else {
            ng = val;
        }
    }

    cout << ok << endl;
}