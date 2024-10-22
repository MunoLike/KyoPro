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
    i32 N, Q;
    cin >> N >> Q;
    vector<i32> a(N), order(N);  // 実際の位置-番号，iと書かれたボールの位置
    rep(i, N) {
        a[i] = i;
        order[i] = i;
    }
    rep(i, Q) {
        i32 x;
        cin >> x;
        --x;
        i32 pos = order[x];
        i32 a_x = a[pos];
        i32 a_y = a[pos + 1 == N ? pos - 1 : pos + 1];
        swap(a[pos], a[pos + 1 == N ? pos - 1 : pos + 1]);
        swap(order[a_x], order[a_y]);
    }
    rep(i, N) {
        cout << a[i] + 1 << (" \n"[i == N - 1]);
    }
}