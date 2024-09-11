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
    cout.tie(nullptr);
    i32 N;
    cin >> N;
    vector<vector<i32>> G(N);
    vector<i64> Ts(N);
    vector<bool> visited(N);
    rep(i, N) {
        i64 K;
        i32 A;
        cin >> Ts[i] >> K;
        rep(j, K) {
            cin >> A;
            --A;
            G[i].emplace_back(A);
        }
    }

    queue<i32> q;
    q.push(N - 1);
    visited[N - 1] = true;
    while (!q.empty()) {
        i32 idx = q.front();
        q.pop();
        for (auto v : G[idx]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    i64 ans = 0;
    rep(i, N) {
        ans += Ts[i] * visited[i];
    }

    cout << ans << endl;
}