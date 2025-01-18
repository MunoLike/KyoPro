#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {1, 0, -1, 0, -1, -1, 1, 1};
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

template <class S, class T>
inline bool is_in(const T lower, S a, const T upper) {
    return a < upper && lower <= a;
}

int main() {
    i32 n;
    cin >> n;

    vector<vector<i32>> area(n, vector<i32>(n));

    i32 dir = 0, cnt = 1;
    i32 y = 0, x = 0;
    while (!(y == n / 2 and x == n / 2)) {
        i32 ny = y + dy[dir], nx = x + dx[dir];
        if (is_in(0, ny, n) and is_in(0, nx, n) and area[ny][nx] == 0) {
            area[y][x] = cnt;
            ++cnt;
            y = ny, x = nx;
        } else {
            dir = (dir + 1) % 4;
        }
    }

    rep(i, n) {
        rep(j, n) {
            if (i == n / 2 and j == n / 2)
                cout << 'T';
            else
                cout << area[i][j];

            if (j < n - 1) cout << ' ';
        }
        cout << '\n';
    }
}