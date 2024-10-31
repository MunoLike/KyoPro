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

    i32 n;
    cin >> n;
    vector<i64> a(n), b(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n - 1) cin >> b[i];

    sort(all(a));

    const i32 inf = INT32_MAX / 2;
    i32 ok = inf, ng = 0;

    auto judge = [&](i32 val) {
        auto new_b = b;
        new_b.push_back(val);
        sort(all(new_b));
        rep(i, n) {
            if (a[i] > new_b[i]) {
                return false;
            }
        }
        return true;
    };

    while (ok - ng > 1) {
        i32 w = (ok + ng) / 2;
        if (judge(w)) {
            ok = w;
        } else {
            ng = w;
        }
    }

    if (ok == inf)
        cout << -1 << endl;
    else
        cout << ok << endl;
}