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
    i32 h, w, d;
    cin >> h >> w >> d;
    vector<string> area(h);
    rep(i, h) cin >> area[i];

    vector<vector<i32>> is_visited(h, vector<i32>(w, 10000000));
    rep(i, h) {
        rep(j, w) {
            if (area[i][j] == 'H') {
                stack<pair<i32, i32>> s;
                s.emplace(i, j);
                is_visited[i][j] = 0;

                while (!s.empty()) {
                    auto [y, x] = s.top();
                    s.pop();

                    if (is_visited[y][x] == d) continue;

                    rep(dir, 4) {
                        i32 ny = y + dy[dir], nx = x + dx[dir];
                        if (is_in(0, ny, h) and is_in(0, nx, w) and area[ny][nx] == '.' and is_visited[y][x] + 1 < is_visited[ny][nx]) {
                            is_visited[ny][nx] = is_visited[y][x] + 1;
                            s.emplace(ny, nx);
                        }
                    }
                }
            }
        }
    }

    i32 cnt = 0;
    rep(i, h) rep(j, w) {
        if (is_visited[i][j] != 10000000) cnt++;
    }

    cout << cnt << endl;
}
