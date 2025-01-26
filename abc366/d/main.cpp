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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i32 n;
    cin >> n;

    vector a(n, vector(n, vector<i64>(n))), sum(n + 2, vector(n + 2, vector<i64>(n + 2)));

    rep(i, n) rep(j, n) rep(k, n) cin >> a[i][j][k];
    rep(i, n) rep(j, n) rep(k, n) sum[i + 1][j + 1][k + 1] = a[i][j][k];
    rep(i, n + 1) rep(j, n + 1) rep(k, n + 1) sum[i + 1][j][k] += sum[i][j][k];
    rep(i, n + 1) rep(j, n + 1) rep(k, n + 1) sum[i][j + 1][k] += sum[i][j][k];
    rep(i, n + 1) rep(j, n + 1) rep(k, n + 1) sum[i][j][k + 1] += sum[i][j][k];

    i32 q;
    cin >> q;
    rep(i, q) {
        i32 lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        --lx, --ly, --lz;
        auto sum3 = [&](i32 rx, i32 ry, i32 lz, i32 rz) {
            return sum[rx][ry][rz] - sum[rx][ry][lz];
        };

        auto sum2 = [&](i32 rx, i32 ly, i32 ry, i32 lz, i32 rz) {
            i32 res = 0;
            res += sum3(rx, ry, lz, rz);
            res -= sum3(rx, ly, lz, rz);
            return res;
        };

        auto sum1 = [&](i32 lx, i32 rx, i32 ly, i32 ry, i32 lz, i32 rz) {
            i32 res = 0;
            res += sum2(rx, ly, ry, lz, rz);  // 0~rx, ly~ry, lz~rz
            res -= sum2(lx, ly, ry, lz, rz);
            return res;
        };
        cout << sum1(lx, rx, ly, ry, lz, rz) << '\n';
    }
}