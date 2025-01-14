#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, -1, 1, 0, 1};
const i32 dx[] = {-1, -1, 0, 0, 1, 1};

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
    cin >> n;
    dsu uf(n);
    map<pair<i32, i32>, i32> mp;  // pos, no

    rep(i, n) {
        i32 x, y;
        cin >> x >> y;
        --x, --y;
        mp[{x, y}] = i;
    }

    for (auto &e : mp) {
        auto [x, y] = e.first;
        rep(i, 6) {
            i32 nx = x + dx[i], ny = y + dy[i];
            auto it = mp.find({nx, ny});
            if (it != mp.end()) uf.merge(e.second, (*it).second);
        }
    }

    i32 connected = 0;
    rep(i, n) {
        if (uf.leader(i) == i) ++connected;
    }

    cout << connected << '\n';
}