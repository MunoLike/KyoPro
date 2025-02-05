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

template <class S, class T>
inline bool is_in(const T lower, S a, const T upper) {
    return a < upper && lower <= a;
}

int main() {
    i32 h, w;
    cin >> h >> w;
    vector<string> area(h);
    rep(i, h) cin >> area[i];
    string pat = "snuke";

    vector<vector<bool>> is_visited(h, vector<bool>(w));
    stack<pair<i32, i32>> st;

    st.emplace(0, 0);
    is_visited[0][0] = true;
    i64 cnt = 0;

    while (!st.empty()) {
        auto [cy, cx] = st.top();
        st.pop();

        rep(i, 4) {
            i32 ny = cy + dy[i], nx = cx + dx[i];

            % if (is_in(0, ny, h) and is_in(0, nx, w) and !is_visited[ny][nx] and (pat[cnt % pat.size()] == area[ny][nx])) {
                if (ny == h - 1 and nx == w - 1) {
                    cout << "Yes\n";
                    return 0;
                }

                is_visited[ny][nx] = true;
                st.emplace(ny, nx);
            }
            cnt = (cnt + 1) % 5;
        }
    }
    cout << "No\n";
}