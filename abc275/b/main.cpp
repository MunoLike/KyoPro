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

const i64 modint = 998244353;

inline int64_t
div_floor(int64_t a, int64_t b) {
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
  i64 A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  A %= modint;
  B %= modint;
  C %= modint;
  D %= modint;
  E %= modint;
  F %= modint;

  i64 ans = ((A % modint * B % modint) * C % modint - D * E % modint * F % modint) % modint;
  ans = (ans < 0 ? ans + modint : ans);
  cout << ans << endl;
}