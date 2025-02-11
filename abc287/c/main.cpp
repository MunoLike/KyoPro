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
    i32 n, m;
    cin >> n >> m;
    vector<vector<i32>> edge(n);
    rep(i, m) {
        i32 from, to;
        cin >> from >> to;
        --from, --to;
        edge[from].emplace_back(to);
        edge[to].emplace_back(from);
    }

    if (n - 1 != m) {
        cout << "No\n";
    } else {
        vector<bool> is_visited(n);
        queue<i32> q;
        q.emplace(0);
        is_visited[0] = true;

        bool flag_ord = true;
        while (!q.empty()) {
            i32 t = q.front();
            q.pop();
            i32 cnt = 0;
            for (auto v : edge[t]) {
                if (!is_visited[v]) {
                    is_visited[v] = true;
                    q.emplace(v);
                    ++cnt;
                }
            }
            if (cnt > 2) flag_ord = false;
        }

        bool flag_all = true;
        rep(i, n) {
            flag_all &= is_visited[i];
        }

        if (flag_all and flag_ord) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}