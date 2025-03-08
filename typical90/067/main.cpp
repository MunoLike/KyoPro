#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (i32 i = 0; i < (n); i++)
#define rep1(i, n) for (i32 i = 1; i <= (n); (i)++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const i32 dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
const string lrud("URDL");

template <class S, class T>
inline S prevent_oor(S a, const T b) {
    a %= b;
    if (a < 0) {
        a += b;
    }
    return a;
}

template <class S, class T>
inline bool is_in(const T lower, S a, const T upper) {
    return a < upper && lower <= a;
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

i64 oct_to_dec(string oct) {
    i64 ret = 0;
    rep(i, oct.size()) {
        ret *= 8;
        ret += oct[i] - '0';
    }
    return ret;
}

string dec_to_nov(i64 dec) {
    string ret;
    while (dec > 0) {
        ret.push_back(dec % 9 + '0');
        dec /= 9;
    }
    reverse(all(ret));
    return ret;
}

string nov_to_oct(string nov) {
    rep(i, nov.size()) {
        if (nov[i] == '8') nov[i] = '5';
    }
    return nov;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string n;
    i32 k;
    cin >> n >> k;

    rep(i, k) {
        n = nov_to_oct(dec_to_nov(oct_to_dec(n)));
    }

    if (n == "")
        cout << 0 << endl;
    else
        cout << n << endl;
}