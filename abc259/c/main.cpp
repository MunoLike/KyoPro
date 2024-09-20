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

void run_length(vector<pair<char, i32>> &sv, string &s) {
    i32 l = 0, r = 0;

    i32 N = s.size();
    while (l < N) {
        while (r < N && s[l] == s[r]) ++r;
        sv.emplace_back(s[l], r - l);
        l = r;
    }
}

int main() {
    string S, T;
    cin >> S >> T;

    vector<pair<char, i32>> sv, st;
    run_length(sv, S);
    run_length(st, T);

    bool flag = true;
    if (sv.size() != st.size())
        flag = false;
    else {
        i32 N = sv.size();
        rep(i, N) {
            if (sv[i].first != st[i].first) flag = false;
            if (!((sv[i].second == st[i].second) || (sv[i].second < st[i].second && sv[i].second >= 2))) {
                flag = false;
            }
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
}