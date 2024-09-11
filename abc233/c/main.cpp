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

i64 N, X, ans = 0;

void dfs(vector<vector<i64>> &packets, i32 depth, i64 product) {
    if (depth == N) {
        if (product == X) ++ans;
        return;
    }
    for (auto val : packets[depth]) {
        if (product * val > X) continue;
        dfs(packets, depth + 1, product * val);
    }
}

int main() {
    cin >> N >> X;
    vector<vector<i64>> packets(N);

    rep(i, N) {
        i64 L;
        cin >> L;
        packets[i].resize(L);
        rep(j, L) {
            cin >> packets[i][j];
        }
    }

    dfs(packets, 0, 1);

    cout << ans << endl;
}