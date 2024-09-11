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

template <class S, class T>
inline bool is_in(const T lower, S a, const T upper) {
    return a < upper && lower <= a;
}

void dfs(i32 y, i32 x, i32 H, i32 W, vector<vector<i32>> &area, set<i32> &found, i32 &count) {
    if (!found.contains(area[y][x])) {
        if (y == H - 1 && x == W - 1) {
            ++count;
            return;
        }
        found.insert(area[y][x]);
        for (i32 k : {1, 2}) {
            i32 ny = y + dy[k];
            i32 nx = x + dx[k];
            if (is_in(0, ny, H) && is_in(0, nx, W)) {
                dfs(ny, nx, H, W, area, found, count);
            }
        }
        found.erase(area[y][x]);
    }
}

int main() {
    i32 H, W;
    cin >> H >> W;
    vector<vector<i32>> area(H, vector<i32>(W));
    rep(i, H) rep(j, W) cin >> area[i][j];

    set<i32> found;
    i32 count = 0;
    dfs(0, 0, H, W, area, found, count);

    cout << count << endl;

    // queue<pair<i32, i32>> Q;
    // rep(i, H) rep(j, W) {
    //     set<i32> visited;
    //     Q.emplace(i, j);
    //     visited.emplace(area[i][j]);
    //     while (!Q.empty()) {
    //         auto [ni, nj] = Q.front();
    //         Q.pop();
    //         visited.emplace(area[ni][nj]);
    //         for (i32 k = 1; k <= 2; ++k) {
    //             i32 ny = ni + dy[k];
    //             i32 nx = nj + dx[k];
    //             if (is_in(0, ny, H) && is_in(0, nx, W) && !visited.contains(area[ny][nx])) {
    //                 Q.emplace(ny, nx);
    //             }
    //         }
    //     }
    // }
}
