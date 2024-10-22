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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    i32 N;
    double S, T;
    cin >> N >> S >> T;
    vector<vector<i32>> sg;  // start, goal

    rep(i, N) {
        i32 A, B, C, D;
        cin >> A >> B >> C >> D;
        sg.push_back({A, B, C, D});
    }

    sort(all(sg));

    double min_time = 9999999999;
    do {
        for (i32 ord = 0; ord < (1 << N); ++ord) {
            double time = 0;
            i32 x = 0, y = 0;
            rep(i, N) {
                if (ord & (1 << i)) {
                    time += sqrt((y - sg[i][1]) * (y - sg[i][1]) + (x - sg[i][0]) * (x - sg[i][0])) / S;
                    time += sqrt((sg[i][0] - sg[i][2]) * (sg[i][0] - sg[i][2]) + (sg[i][1] - sg[i][3]) * (sg[i][1] - sg[i][3])) / T;
                    x = sg[i][2];
                    y = sg[i][3];
                } else {
                    time += sqrt((y - sg[i][3]) * (y - sg[i][3]) + (x - sg[i][2]) * (x - sg[i][2])) / S;
                    time += sqrt((sg[i][0] - sg[i][2]) * (sg[i][0] - sg[i][2]) + (sg[i][1] - sg[i][3]) * (sg[i][1] - sg[i][3])) / T;
                    x = sg[i][0];
                    y = sg[i][1];
                }
            }

            chmin(min_time, time);
        }
    } while (next_permutation(all(sg)));

    cout << setprecision(15) << min_time << endl;
}