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
    i32 h, w, n;
    cin >> h >> w >> n;

    vector<set<i32>> row(h), column(w);  // 横方向に見たときの個数と縦方向に見たときの個数を.size()で持つ。また、指定した行の何個目の列にあるかを持つ。行も同様。

    rep(i, n) {
        i32 x, y;
        cin >> x >> y;
        x--;
        y--;
        row[x].emplace(y);
        column[y].emplace(x);
    }

    i32 q;
    cin >> q;
    rep(i, q) {
        i32 c, pos;
        cin >> c >> pos;
        --pos;
        switch (c) {
            case 1: {
                cout << row[pos].size() << '\n';
                for (i32 y : row[pos]) {
                    column[y].erase(pos);
                }

                row[pos].clear();
            } break;
            case 2: {
                cout << column[pos].size() << '\n';
                for (i32 x : column[pos]) {
                    row[x].erase(pos);
                }

                column[pos].clear();
            } break;
        }
    }
}