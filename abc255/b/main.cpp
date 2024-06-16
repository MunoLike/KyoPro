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
inline S chmax(S& a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

template <class S, class T>
inline S chmin(S& a, T b) {
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
  i32 N, K;
  cin >> N >> K;
  vector<i64> having(K);
  vector<i64> edist(N, INT64_MAX);
  vector<pair<i64, i64>> pos;
  rep(i, K) {
    cin >> having[i];
    --having[i];
  }
  rep(i, N) {
    i64 x, y;
    cin >> x >> y;
    pos.emplace_back(x, y);
  }

  i64 ma = 0;
  rep(i, N) {
    i64 mi = INT64_MAX;
    rep(j, K) {
      auto& [x1, y1] = pos[i];
      auto& [x2, y2] = pos[having[j]];
      chmin(mi, (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
    chmax(ma, mi);
  }

  printf("%.6f\n", sqrt(ma));
}