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
  i32 N, X, Y, Z;
  cin >> N >> X >> Y >> Z;

  vector<i32> math_res(N, 0);
  vector<i32> eng_res(N, 0);
  rep(i, N) cin >> math_res[i];
  rep(i, N) cin >> eng_res[i];

  vector<i32> successed(N);
  iota(all(successed), 0);

  stable_sort(all(successed), [&](auto& lhs, auto& rhs) { return math_res[lhs] > math_res[rhs]; });
  sort(successed.begin() + X, successed.end());

  stable_sort(successed.begin() + X, successed.end(), [&](auto& lhs, auto& rhs) { return eng_res[lhs] > eng_res[rhs]; });
  sort(successed.begin() + X + Y, successed.end());

  stable_sort(successed.begin() + X + Y, successed.end(), [&](auto& lhs, auto& rhs) { return math_res[lhs] + eng_res[lhs] > math_res[rhs] + eng_res[rhs]; });
  sort(successed.begin(), successed.begin() + X + Y + Z);

  for (i32 i = 0; i < X + Y + Z; ++i) {
    cout << successed[i] + 1 << endl;
  }
}