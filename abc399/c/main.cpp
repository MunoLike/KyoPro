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
    i32 N, M;
    cin >> N >> M;

    vector<vector<i32>> edges(N);
    vector<bool> visited(N);

    rep(i, M) {
        i32 A, B;
        cin >> A >> B;
        --A, --B;
        edges[A].emplace_back(B);
        edges[B].emplace_back(A);
    }

    queue<i32> Q;

    i32 need2del = 0;
    i32 connected = 0;
    rep(i, N) {
        if (visited[i]) {
            continue;
        }
        ++connected;
        Q.emplace(i);
        visited[i] = true;
        while (!Q.empty()) {
            i32 fr = Q.front();
            Q.pop();

            auto &es = edges[fr];
            for (auto e : es) {
                if (visited[e]) continue;
                Q.emplace(e);
                visited[e] = true;
            }
        }
    }

    cout << M - N + connected << endl;
}