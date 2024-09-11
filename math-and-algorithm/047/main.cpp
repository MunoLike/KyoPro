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

void dfs(i32 idx, vector<vector<i32>> &edges, vector<i32> &color) {
    for (auto val : edges[idx]) {
        if (color[val] == 0) {
            color[val] = 3 - color[idx];
            dfs(val, edges, color);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    vector<vector<i32>> edges(N);
    vector<i32> color(N, 0), A(M), B(M);

    rep(i, M) {
        cin >> A[i] >> B[i];
        --A[i], --B[i];
        edges[A[i]].push_back(B[i]);
        edges[B[i]].push_back(A[i]);
    }

    rep(i, N) {
        if (color[i] == 0) {
            color[i] = 1;
            dfs(i, edges, color);
        }
    }

    bool answer = true;
    rep(i, M) {
        answer &= color[A[i]] != color[B[i]];
    }
    cout << (answer ? "Yes\n" : "No\n");
}