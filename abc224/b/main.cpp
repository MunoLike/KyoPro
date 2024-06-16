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
  i32 H, W;
  cin >> H >> W;
  vector<vector<i64>> area(H, vector<i64>(W));
  rep(i, H) rep(j, W) cin >> area[i][j];

  bool flag = true;
  for (i32 i1 = 0; i1 < H; i1++) {
    for (i32 i2 = i1 + 1; i2 < H; i2++) {
      for (i32 j1 = 0; j1 < W; j1++) {
        for (i32 j2 = j1 + 1; j2 < W; j2++) {
          if (area[i1][j1] + area[i2][j2] > area[i2][j1] + area[i1][j2]) {
            flag = false;
          }
        }
      }
    }
  }
  cout << (flag ? "Yes\n" : "No\n");
}