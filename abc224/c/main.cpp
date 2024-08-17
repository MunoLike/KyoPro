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
  i32 N;
  cin >> N;
  vector<i64> x(N), y(N);
  rep(i, N) {
    cin >> x[i] >> y[i];
  }

  i32 count = 0;
  for (i32 i = 0; i < N; ++i) {
    for (i32 j = i; j < N; ++j) {
      for (i32 k = j; k < N; ++k) {
        i64 abx = x[i] - x[j], aby = y[i] - y[j];
        i64 acx = x[i] - x[k], acy = y[i] - y[k];

        count += (abs(abx * acy - aby * acx) > 0);
      }
    }
  }

  cout << count << '\n';
}