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

class vertex {
   public:
    i32 to;
    i64 cost;

    vertex(i32 to, i64 cost) : to(to), cost(cost) {
    }
};

using p = pair<i64, i32>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i32 n, m;
    cin >> n >> m;
    vector<i64> weight(n), result(n, (i64)1 << 60);
    vector<vector<vertex>> edges(n);  // vertex no, weight
    rep(i, n) cin >> weight[i];
    rep(i, m) {
        i64 u, v, b;
        cin >> u >> v >> b;
        --u, --v;
        edges[u].emplace_back(v, b + weight[v]);
        edges[v].emplace_back(u, b + weight[u]);
    }

    priority_queue<p, vector<p>, greater<p>> queue;  // weight, vertex no
    queue.emplace(weight[0], 0);
    while (!queue.empty()) {
        auto [w, no] = queue.top();
        queue.pop();
        if (result[no] < w) {  // 入れられたときより小さくなっている可能性がある
            continue;
        }
        for (auto &e : edges[no]) {
            i64 nd = e.cost + w;
            if (nd < result[e.to]) {  // 小さいときだけ次のループに
                queue.emplace(nd, e.to);
                result[e.to] = nd;
            }
        }
    }

    rep(i, n - 1) cout << result[i + 1] << ' ';
    cout << '\n';
}