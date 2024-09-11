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
    vector<vector<i32>> edges(N + 1);
    vector<i32> A(M), B(M);

    vector<bool> visited(N + 1, false);
    rep(i, M) {
        cin >> A[i] >> B[i];
        edges[A[i]].emplace_back(B[i]);
        edges[B[i]].emplace_back(A[i]);
    }

    queue<i32> Q;

    i32 count = 0;
    rep(i, N) {
        i32 idx = i + 1;
        if (!visited[idx]) {
            Q.push(idx);
            visited[idx] = true;
            while (!Q.empty()) {
                i32 f = Q.front();
                Q.pop();

                for (i32 &val : edges[f]) {
                    if (!visited[val]) {
                        Q.push(val);
                        visited[val] = true;
                    }
                }
            }
            ++count;
        }
    }

    cout << count << endl;
}