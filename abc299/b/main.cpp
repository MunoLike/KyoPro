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
  i32 N, T;
  cin >> N >> T;
  vector<i32> color(N, 0);
  vector<i64> power(N, 0);
  rep(i, N) cin >> color[i];
  rep(i, N) cin >> power[i];

  i64 max_power = 0;
  i64 cc_idx = -1;
  i64 eq1_power = power[0];
  i64 eq1_idx = 0;
  rep(i, N) {
    if (color[i] == T) {
      if (max_power < power[i]) {
        max_power = max(max_power, power[i]);
        cc_idx = i;
      }
    }

    if (color[0] == color[i]) {
      if (eq1_power < power[i]) {
        eq1_power = max(eq1_power, power[i]);
        eq1_idx = i;
      }
    }
  }

  if (cc_idx == -1) {
    cout << eq1_idx + 1 << endl;
  } else {
    cout << cc_idx + 1 << endl;
  }
}