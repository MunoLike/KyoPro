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
  i32 H, M;
  cin >> H >> M;

  for (i32 add_min = 0; add_min < 3600; add_min++) {
    i32 h1 = H / 10, h2 = H % 10;
    i32 m1 = M / 10, m2 = M % 10;
    if (0 <= (h1 * 10 + m1) and (h1 * 10 + m1) <= 23) {
      if (0 <= (h2 * 10 + m2) and (h2 * 10 + m2) <= 59) {
        cout << H << ' ' << M;
        return 0;
      }
    }
    M++;
    if (60 == M) {
      M = 0;
      H++;
    }
    if (H == 24) H = 0;
  }
}