#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

    i32 R, C;
    pair<i32, i32> start, goal;  // y, x
    cin >> R >> C;
    cin >> start.first >> start.second;
    --start.first, --start.second;
    cin >> goal.first >> goal.second;
    --goal.first, --goal.second;

    vector<string> area(R);
    rep(i, R) {
        cin >> area[i];
    }

    vector<vector<i32>> length(R, vector(C, -1));
    queue<pair<i32, i32>> Q;
    Q.emplace(start.first, start.second);
    length[start.first][start.second] = 0;

    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();

        rep(i, 4) {
            i32 ny = p.first + dy[i];
            i32 nx = p.second + dx[i];

            if (is_in(0, ny, R) && is_in(0, nx, C) && length[ny][nx] == -1 && area[ny][nx] == '.') {
                length[ny][nx] = length[p.first][p.second] + 1;
                Q.emplace(ny, nx);
            }
        }
    }

    cout << length[goal.first][goal.second] << endl;
}