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
    string s;
    cin >> s;

    i32 n = s.size();

    i32 l_a = 0, r_a = n - 1;
    while (l_a < n and s[l_a] == 'a') ++l_a;
    while (r_a >= 0 and s[r_a] == 'a') --r_a;

    r_a = n - 1 - r_a;
    if (l_a > r_a) {
        cout << "No\n";
    } else {
        i32 diff = r_a - l_a;
        string as(diff, 'a');
        as += s;
        i32 n = as.size();
        bool flag = true;
        for (i32 i = 0; i < n / 2; ++i) {
            if (as[i] != as[n - i - 1]) {
                flag = false;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
}