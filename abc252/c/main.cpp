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

int main() {
    i32 N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    i32 mi = INT32_MAX;
    vector<vector<i32>> proc(10, vector<i32>(10, 0));  //[A][B]=特定の数AがB番目にあるリールの個数

    rep(i, N) {       // リール
        rep(j, 10) {  // 何番目にあるか
            proc[S[i][j] - '0'][j]++;
        }
    }

    rep(i, 10) {  // 特定の数iが
        i32 mx = INT32_MIN;
        rep(j, 10) {                               // j番目にある
            chmax(mx, 10 * (proc[i][j] - 1) + j);  // ある数iで揃えるためにかかる時間を算出する．同じ位置にあった場合，proc[i][j] >= 2で一周回るのを待たなければいけないことを表している．
        }
        chmin(mi, mx);  // iの中で一番早くそろえられるときの時間を記録
    }
    cout << mi << endl;
}