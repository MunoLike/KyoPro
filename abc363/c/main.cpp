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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<i32> ajs = {1, 2, 2};

    i32 N, K;
    string S;
    cin >> N >> K >> S;

    sort(all(S));

    i32 count = 0;
    i32 pat = 0;
    do {
        ++pat;
        for (auto x : ajs) cout << x << ' ';
        cout << '\n';

        // bool is_palindrome_outer = false;
        // for (i32 i = 0; i <= N - K; ++i) {
        //     bool is_palindrome = true;
        //     for (i32 j = 1; j <= K; ++j) {
        //         // cout << i + j - 1 << ' ' << i + K - j << '\n';
        //         if (S[i + j - 1] != S[i + K - j]) {
        //             is_palindrome = false;
        //         }
        //     }
        //     if (is_palindrome) {
        //         is_palindrome_outer = true;
        //         break;
        //     }
        // }
        // count += is_palindrome_outer;
        // // cout << '\n';
    } while (next_permutation(all(ajs)));

    cout << pat - count << endl;
}
