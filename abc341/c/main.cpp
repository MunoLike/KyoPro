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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    i32 H, W, N;
    string T;
    cin >> H >> W >> N >> T;

    reverse(all(T));
    vector<string> S(H);

    rep(i, H) {
        cin >> S[i];
    }

    i32 num_pos = 0;

    rep(i, H) {
        rep(j, W) {
            i32 y = i, x = j;
            bool flag = true;

            if (S[y][x] == '#') continue;

            rep(k, N) {
                i32 idx = lrud.find(T[k]);
                y -= dy[idx];
                x -= dx[idx];

                if (y > 0 && x > 0 && H - 1 > y && W - 1 > x && S[y][x] == '.')
                    continue;
                else {
                    flag = false;
                    break;
                }
            }
            num_pos += flag;
        }
    }

    cout << num_pos << '\n';
}