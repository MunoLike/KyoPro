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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i32 H, W;
    cin >> H >> W;

    vector<string> S_in(H), T_in(H), S, T;

    rep(i, H) {
        cin >> S_in[i];
    }
    rep(i, H) {
        cin >> T_in[i];
    }

    rep(j, W) {
        string a(H, '.'), b(H, '.');
        rep(i, H) {
            a[i] = S_in[i][j];
            b[i] = T_in[i][j];
        }
        S.emplace_back(a);
        T.emplace_back(b);
    }

    sort(all(S));
    sort(all(T));

    if (S != T) {
        cout << "No\n";
        return 0;
    } else {
        cout << "Yes\n";
    }
}