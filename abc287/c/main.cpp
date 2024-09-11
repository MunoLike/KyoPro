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

void dfs(i32 idx, vector<vector<i32>> &edges, vector<i32> &length) {
    for (i32 &e : edges[idx]) {
        if (length[e] == -1) {
            length[e] = length[idx] + 1;
            dfs(e, edges, length);
        }
    }
}

int main() {
    i32 N, M;
    cin >> N >> M;
    vector<vector<i32>> edges(N);
    rep(i, M) {
        i32 u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }

    if (M != N - 1) {
        cout << "No\n";
        return 0;
    }

    rep(i, N) {
        if (edges[i].size() > 2) {
            cout << "No\n";
            return 0;
        }
    }

    queue<i32> Q;
    vector<bool> visited(N);

    Q.push(0);
    visited[0] = true;
    while (!Q.empty()) {
        i32 fr = Q.front();
        Q.pop();
        for (i32 &e : edges[fr]) {
            if (!visited[e]) {
                Q.push(e);
                visited[e] = true;
            }
        }
    }

    bool flag = true;
    for (auto val : visited) flag &= val;
    cout << (flag ? "Yes\n" : "No\n");
}