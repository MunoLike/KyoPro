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

template <class T>
inline bool isin(T val, T lower, T upper) {
    return lower <= val && val < upper;
}

inline int64_t div_ceil(int64_t a, int64_t b) {
    return div_floor(a + b - 1, b);
}

int main() {
    i32 H, W;
    cin >> H >> W;
    vector<string> area(H);
    rep(i, H) cin >> area[i];

    vector<vector<i32>> step(H, vector<i32>(W, -1));  // そのマスにたどり着くまでに経由するマス数
    queue<pair<i32, i32>> Q;
    Q.emplace(0, 0);
    step[0][0] = 1;
    while (!Q.empty()) {
        auto [y, x] = Q.front();
        Q.pop();
        for (i32 i = 1; i <= 2; ++i) {
            i32 ny = y + dy[i], nx = x + dx[i];
            if (isin(ny, 0, H) && isin(nx, 0, W) && step[ny][nx] == -1 && area[ny][nx] == '.') {
                Q.emplace(ny, nx);
                step[ny][nx] = step[y][x] + 1;
            }
        }
    }

    i32 max_step = 1;
    rep(i, H) {
        rep(j, W) {
            chmax(max_step, step[i][j]);
        }
    }
    cout << max_step << endl;
}