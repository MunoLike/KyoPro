#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vb = vector<bool>;
using vvi32 = vector<vi32>;
using vvi64 = vector<vi64>;
using vvb = vector<vb>;
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

i64 h, w, k, cnt = 0;

i64 dfs(i32 i, i32 j, i32 depth, vvb &visited, vector<string> &area) {
    visited[i][j] = true;
    i64 cnt = 0;
    rep(dir, 4) {
        i32 ni = i + dy[dir], nj = j + dx[dir];
        if (is_in(0L, ni, h) and is_in(0L, nj, w) and area[ni][nj] == '.' and !visited[ni][nj]) {
            if (depth + 1 == k) {
                ++cnt;
            } else {
                cnt += dfs(ni, nj, depth + 1, visited, area);
            }
        }
    }
    visited[i][j] = false;
    return cnt;
}

int main() {
    cin >> h >> w >> k;
    vector<string> area(h);
    rep(i, h) cin >> area[i];

    vvb visited(h, vb(w));

    i64 cnt = 0;
    rep(i, h) {
        rep(j, w) {
            if (area[i][j] == '.') {
                cnt += dfs(i, j, 0, visited, area);
            }
        }
    }

    cout << cnt << endl;
}