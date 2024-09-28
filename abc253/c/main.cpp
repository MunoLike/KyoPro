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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    i32 Q;
    cin >> Q;
    map<i64, i64> pool;
    rep(i, Q) {
        i64 q, x, c;
        cin >> q;
        if (q == 1) {
            cin >> x;
            pool[x]++;
        } else if (q == 2) {
            cin >> x >> c;
            auto it = pool.find(x);
            if (it == pool.end()) continue;
            it->second = it->second - min(c, it->second);
            if (it->second == 0) pool.erase(it);
        } else {
            auto &&min_key = pool.begin()->first;
            auto &&max_key = pool.rbegin()->first;
            cout << max_key - min_key << '\n';
        }
    }
}