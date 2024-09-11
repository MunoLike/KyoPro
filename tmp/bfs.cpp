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

void dfs(i32 pos, vector<vector<i32>> &edge, vector<bool> &visited) {
    visited[pos] = true;
    for (i32 i : edge[pos]) {
        if (visited[i] == false) dfs(i, edge, visited);
    }
}

int main() {
    i32 N, M, A, B;
    cin >> N >> M;
    vector<vector<i32>> edge(N);
    vector<i32> dist(N, -1);

    rep(i, M) {
        cin >> A >> B;
        --A, --B;
        edge[A].emplace_back(B);
        edge[B].emplace_back(A);
    }

    queue<i32> Q;
    Q.push(0);
    dist[0] = 0;

    while (!Q.empty()) {
        i32 pos = Q.front();
        Q.pop();
        for (auto val : edge[pos]) {
            i32 nex = val;
            if (dist[nex] == -1) {
                dist[nex] = dist[pos] + 1;
                Q.push(nex);
            }
        }
    }

    for (auto v : dist) cout << v << endl;
}