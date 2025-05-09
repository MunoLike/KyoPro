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
  i32 H, W;
  cin >> H >> W;
  vector<string> area(H);
  rep(i, H) {
    cin >> area[i];
  }

  i32 u = 1e9, d = 0, l = 1e9, r = 0;
  rep(i, H) {
    rep(j, W) {
      if (area[i][j] == '#') {
        chmin(u, i);
        chmax(d, i);
        chmin(l, j);
        chmax(r, j);
      }
    }
  }

  for (i32 i = u; i <= d; ++i) {
    for (i32 j = l; j <= r; ++j) {
      if (area[i][j] == '.') {
        cout << i + 1 << ' ' << j + 1 << '\n';
        return 0;
      }
    }
  }
}