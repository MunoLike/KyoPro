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
    vector<pair<i32, i32>> vertices(4);
    rep(i, 4) cin >> vertices[i].first >> vertices[i].second;

    i32 v1[] = {vertices[1].first - vertices[0].first,
                vertices[1].second - vertices[0].second};
    i32 v2[] = {vertices[2].first - vertices[1].first,
                vertices[2].second - vertices[1].second};
    i32 v3[] = {vertices[3].first - vertices[2].first,
                vertices[3].second - vertices[2].second};
    i32 v4[] = {vertices[0].first - vertices[3].first,
                vertices[0].second - vertices[3].second};

    i32 s1 = v1[0] * v2[1] - v1[1] * v2[0];
    i32 s2 = v2[0] * v3[1] - v2[1] * v3[0];
    i32 s3 = v3[0] * v4[1] - v3[1] * v4[0];
    i32 s4 = v4[0] * v1[1] - v4[1] * v1[0];

    if (s1 > 0 and s2 > 0 and s3 > 0 and s4 > 0)
        cout << "Yes\n";
    else
        cout << "No\n";
}